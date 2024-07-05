//
// Created by Edoardo Nero on 03/07/24.
//

#include "DatabaseManager.h"
#include <stdexcept>

DatabaseManager::DatabaseManager(){}

DatabaseManager::~DatabaseManager() {}

MYSQL DatabaseManager::getConnection() {
    const char *host = "127.0.0.1"; //Con ip locale si forza l'utilizzo delle socket TCP/IP
    const char *user = "root";
    const char *password = "";
    const char *database = "peer_to_pay";
    MYSQL conn;
    mysql_init(&conn);
    mysql_options(&conn, MYSQL_READ_DEFAULT_GROUP, "peer_to_pay");
    if(!mysql_real_connect(&conn, host, user, password, database, 0, nullptr, 0)){
        throw std::runtime_error(std::string(mysql_error(&conn)));
    }
    return conn;
}

MYSQL_RES* DatabaseManager::getUserData(const std::string& email, const std::string& password) {
    MYSQL conn = getConnection();
    std::string query = "SELECT * FROM user WHERE email = '" + email + "' AND psw = '" + password + "'";
    if (mysql_query(&conn, query.c_str()) != 0) {
        throw std::runtime_error("Errore durante l'esecuzione della query: " + std::string(mysql_error(&conn)));
    }

    return mysql_store_result(&conn);
}