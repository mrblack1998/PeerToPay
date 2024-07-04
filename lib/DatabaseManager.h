//
// Created by Edoardo Nero on 03/07/24.
//

#ifndef PEERTOPAY_DATABASEMANAGER_H
#define PEERTOPAY_DATABASEMANAGER_H

#include <mysql/mysql.h>
#include <string>

class DatabaseManager
{
public:
    DatabaseManager();
    ~DatabaseManager();
    static MYSQL getConnection();
    static MYSQL_RES* getUserData(const std::string& email, const std::string& password);   //recupero dati da tabella user
};


#endif //PEERTOPAY_DATABASEMANAGER_H
