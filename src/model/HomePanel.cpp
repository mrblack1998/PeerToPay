//
// Created by Edoardo Nero on 08/07/24.
//

#include "include/model/HomePanel.h"

HomePanel::HomePanel() = default;

HomePanel::~HomePanel() = default;

std::string HomePanel::getBalance(const int &id) {
    MYSQL conn = DatabaseManager::getConnection();
    std::string result;
    std::string query = "SELECT balance FROM bank_account, user WHERE bank_account.id_user = user.id AND user.id = " + std::to_string(id);
    MYSQL_RES *res;
    MYSQL_ROW row;
    if (mysql_query(&conn, query.c_str()) != 0) {
        throw std::runtime_error("Errore durante l'esecuzione della query: " + std::string(mysql_error(&conn)));
    }
    res = mysql_store_result(&conn);
    if (res) {
        row = mysql_fetch_row(res);
        result = row[0];
    }else{
        result = "0.00";
    }
    mysql_free_result(res);
    mysql_close(&conn);
    return result;
}

std::vector<Transazione> HomePanel::getTransactions(const int &id) {
    MYSQL conn = DatabaseManager::getConnection();
    std::vector<Transazione> result;
    std::string query;
    MYSQL_RES *res;
    MYSQL_ROW row;
    std::string user = "Tu";

    //recupero le transazioni in cui l'utente è il mittente
    query = "SELECT transaction.id, first_name, last_name, amount, date FROM transaction, user WHERE user.id=transaction.id_receiver AND transaction.id_sender = " + std::to_string(id);
    if (mysql_query(&conn, query.c_str()) != 0) {
        throw std::runtime_error("Errore durante l'esecuzione della query: " + std::string(mysql_error(&conn)));
    }
    res = mysql_store_result(&conn);
    if (res) {
        while ((row = mysql_fetch_row(res))) {
            //prendi nome e cognome del destinatario e unisci i due campi
            std::string destinatario = std::string(row[1]) + " " + std::string(row[2]);
            std::string data = std::string(row[4]);
            result.emplace_back(std::stoi(row[0]), data, user, destinatario, std::stod(row[3]), false);
        }
    }
    //recupero le transazioni in cui l'utente è il destinatario
    query = "SELECT transaction.id, first_name, last_name, amount, date FROM transaction, user WHERE user.id=transaction.id_sender AND transaction.id_receiver = " + std::to_string(id);
    if (mysql_query(&conn, query.c_str()) != 0) {
        throw std::runtime_error("Errore durante l'esecuzione della query: " + std::string(mysql_error(&conn)));
    }
    res = mysql_store_result(&conn);
    if (res) {
        while ((row = mysql_fetch_row(res))) {
            //prendi nome e cognome del mittente e unisci i due campi
            std::string mittente = std::string(row[1]) + " " + std::string(row[2]);
            //scrivi la data e l'orario nella forma gg/mm/aaaa hh:mm:ss
            std::string data = std::string(row[4]);
            result.emplace_back(std::stoi(row[0]), data, mittente, user, std::stod(row[3]), true);
        }
    }
    mysql_free_result(res);
    mysql_close(&conn);
    return result;
}