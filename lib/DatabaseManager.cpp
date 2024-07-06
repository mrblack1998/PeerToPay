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