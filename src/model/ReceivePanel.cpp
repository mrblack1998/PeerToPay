//
// Created by Edoardo Nero on 09/07/24.
//

#include "include/model/ReceivePanel.h"

ReceivePanel::ReceivePanel() = default;

ReceivePanel::~ReceivePanel() = default;

std::vector<std::string> ReceivePanel::getCode(const int &id) {
    MYSQL conn = DatabaseManager::getConnection();

    //recupera se presente il codice e l'orario dalla tabella temporary_identifier associato all'id dell'utente con expiration_date maggiore di adesso
    std::string query = "SELECT code, TIME(expiration_date) FROM temporary_identifier WHERE id_user = " + std::to_string(id) + " AND expiration_date > NOW()";
    if (mysql_query(&conn, query.c_str()) != 0) {
        throw std::runtime_error("Errore durante l'esecuzione della query: " + std::string(mysql_error(&conn)));
    }

    MYSQL_RES* res = mysql_store_result(&conn);
    if (mysql_num_rows(res) == 1) {
        MYSQL_ROW row = mysql_fetch_row(res);
        std::vector<std::string> result;
        result.push_back(row[0]);
        result.push_back(row[1]);
        return result;
    } else {
        //genera un nuovo codice di 5 cifre numeriche e lo inserisce nella tabella temporary_identifier, verificandop che non sia già presente
        return generateCode(id);
    }
}

std::vector<std::string> ReceivePanel::generateCode(const int &id) {
    MYSQL conn = DatabaseManager::getConnection();
    std::string code;
    std::string query;
    MYSQL_RES* res;
    do {
        code = std::to_string(rand() % 100000);
        if(code.length() < 5){
            code = std::string(5 - code.length(), '0') + code;
        }
        query = "SELECT code FROM temporary_identifier WHERE code = '" + code + "'";
        if (mysql_query(&conn, query.c_str()) != 0) {
            throw std::runtime_error("Errore durante l'esecuzione della query: " + std::string(mysql_error(&conn)));
        }
        res = mysql_store_result(&conn);
    } while (mysql_num_rows(res) > 0);
    //se l'id_user è già presente nella tabella, aggiorna il codice e l'orario di scadenza, altrimenti inserisce un nuovo record
    query = "SELECT * FROM temporary_identifier WHERE id_user = " + std::to_string(id);
    if (mysql_query(&conn, query.c_str()) != 0) {
        throw std::runtime_error("Errore durante l'esecuzione della query: " + std::string(mysql_error(&conn)));
    }
    res = mysql_store_result(&conn);
    if (mysql_num_rows(res) > 0) {
        query = "UPDATE temporary_identifier SET code = '" + code + "', expiration_date = DATE_ADD(NOW(), INTERVAL 15 MINUTE) WHERE id_user = " + std::to_string(id);
    } else {
        query = "INSERT INTO temporary_identifier (id_user, code, expiration_date) VALUES (" + std::to_string(id) + ", '" + code + "', DATE_ADD(NOW(), INTERVAL 15 MINUTE))";
    }
    if (mysql_query(&conn, query.c_str()) != 0) {
        throw std::runtime_error("Errore durante l'esecuzione della query: " + std::string(mysql_error(&conn)));
    }
    //recupera il codice appena inserito e l'orario di scadenza con la query precedente
    query = "SELECT code, TIME(expiration_date) FROM temporary_identifier WHERE id_user = " + std::to_string(id) + " AND expiration_date > NOW()";
    if (mysql_query(&conn, query.c_str()) != 0) {
        throw std::runtime_error("Errore durante l'esecuzione della query: " + std::string(mysql_error(&conn)));
    }
    res = mysql_store_result(&conn);
    MYSQL_ROW row = mysql_fetch_row(res);
    std::vector<std::string> result;
    result.push_back(row[0]);
    result.push_back(row[1]);
    return result;
}
