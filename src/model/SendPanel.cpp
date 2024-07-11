//
// Created by Edoardo Nero on 08/07/24.
//

#include "include/model/SendPanel.h"

SendPanel::SendPanel() = default;

SendPanel::~SendPanel() = default;

std::string checkBalance(const std::string& balance) {
    std::string balanceFormatted = balance;
    std::replace(balanceFormatted.begin(), balanceFormatted.end(), ',', '.');

    double number;
    try {
        number = std::stod(balanceFormatted);
    } catch (const std::invalid_argument& e) {
        throw std::invalid_argument("L'importo non è un numero valido.");
    } catch (const std::out_of_range& e) {
        throw std::out_of_range("L'importo è fuori dall'intervallo consentito.");
    }

    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2) << number;
    return stream.str();
}

bool SendPanel::sendMoney(const int &id, const std::string &amount, const std::string &code) {
    //Verifica che l'ammontare da inviare sia un numero positivo e che l'utente abbia abbastanza denaro sul conto
    std::string balance = checkBalance(amount);

    if (balance.empty() || std::stod(balance) <= 0){
        throw std::runtime_error("L'importo deve essere un numero positivo");
    }

    MYSQL conn = DatabaseManager::getConnection();

    //verifica che l'utente abbia un conto bancario associato
    std::string query = "SELECT * FROM bank_account WHERE id_user = " + std::to_string(id);
    if (mysql_query(&conn, query.c_str()) != 0) {
        throw std::runtime_error("Errore durante l'esecuzione della query: " + std::string(mysql_error(&conn)));
    }
    MYSQL_RES* res = mysql_store_result(&conn);
    if (mysql_num_rows(res) == 0) {
        throw std::runtime_error("Associa un conto bancario al tuo account per poter inviare denaro");
    }

    query = "SELECT balance FROM bank_account WHERE id_user = " + std::to_string(id);
    if (mysql_query(&conn, query.c_str()) != 0) {
        throw std::runtime_error("Errore durante l'esecuzione della query: " + std::string(mysql_error(&conn)));
    }
    res = mysql_store_result(&conn);
    MYSQL_ROW row = mysql_fetch_row(res);
    if (std::stod(balance) > std::stod(row[0])) {
        throw std::runtime_error("Non hai abbastanza soldi sul conto");
    }

    //Verifica che il codice inserito sia corretto
    query = "SELECT id_user FROM temporary_identifier WHERE id_user != " + std::to_string(id) + " AND code = '" + code + "' AND expiration_date > NOW()";
    if (mysql_query(&conn, query.c_str()) != 0) {
        throw std::runtime_error("Errore durante l'esecuzione della query: " + std::string(mysql_error(&conn)));
    }
    res = mysql_store_result(&conn);
    if (mysql_num_rows(res) == 0) {
        throw std::runtime_error("Codice non valido o scaduto");
    }

    //Verifica che il destinatario abbia un conto bancario associato
    query = "SELECT * FROM bank_account WHERE id_user = (SELECT id_user FROM temporary_identifier WHERE code = '" + code + "')";
    if (mysql_query(&conn, query.c_str()) != 0) {
        throw std::runtime_error("Errore durante l'esecuzione della query: " + std::string(mysql_error(&conn)));
    }
    res = mysql_store_result(&conn);
    if (mysql_num_rows(res) == 0) {
        throw std::runtime_error("Il destinatario non ha un conto bancario associato");
    }

    //Aggiorna il saldo del mittente e del destinatario
    query = "UPDATE bank_account SET balance = balance - " + balance + " WHERE id_user = " + std::to_string(id);
    if (mysql_query(&conn, query.c_str()) != 0) {
        throw std::runtime_error("Errore durante l'esecuzione della query: " + std::string(mysql_error(&conn)));
    }
    query = "SELECT id_user FROM temporary_identifier WHERE code = '" + code + "'";
    if (mysql_query(&conn, query.c_str()) != 0) {
        throw std::runtime_error("Errore durante l'esecuzione della query: " + std::string(mysql_error(&conn)));
    }
    res = mysql_store_result(&conn);
    row = mysql_fetch_row(res);
    query = "UPDATE bank_account SET balance = balance + " + balance + " WHERE id_user = " + row[0];
    if (mysql_query(&conn, query.c_str()) != 0) {
        throw std::runtime_error("Errore durante l'esecuzione della query: " + std::string(mysql_error(&conn)));
    }

    //Aggiungi la transazione alla tabella transaction
    query = "INSERT INTO transaction (id_sender, id_receiver, amount, date) VALUES (" + std::to_string(id) + ", " + row[0] + ", " + balance + ", NOW())";
    if (mysql_query(&conn, query.c_str()) != 0) {
        throw std::runtime_error("Errore durante l'esecuzione della query: " + std::string(mysql_error(&conn)));
    }

    return true;
}