//
// Created by Edoardo Nero on 05/07/24.
//

#include "include/model/Register.h"

Register::Register() = default;

Register::~Register() = default;

bool Register::TryRegister(const std::string &firstName, const std::string &lastName, const std::string &email, const std::string &password) {
    MYSQL conn = DatabaseManager::getConnection();
    //controlla se l'email è già presente nel database
    std::string query = "SELECT * FROM user WHERE email = '" + email + "'";
    //se la query non va a buon fine, lancia un'eccezione
    if (mysql_query(&conn, query.c_str()) != 0) {
        throw std::runtime_error("Errore durante l'esecuzione della query: " + std::string(mysql_error(&conn)));
    }else{
        //se la query va a buon fine, controlla se l'email è già presente nel database
        MYSQL_RES* res = mysql_store_result(&conn);
        if (mysql_num_rows(res) == 0) {
            //se l'email non è presente nel database, inserisce i dati nel database
            query = "INSERT INTO user (first_name, last_name, email, psw) VALUES ('" + firstName + "', '" + lastName + "', '" + email + "', '" + PswCipher::encrypt(password) + "')";
            if (mysql_query(&conn, query.c_str()) != 0) {
                throw std::runtime_error("Errore durante l'esecuzione della query: " + std::string(mysql_error(&conn)));
            }
            return true;
        } else {
            return false;
        }
    }
}
