//
// Created by Edoardo Nero on 04/07/24.
//
    #include "include/model/Login.h"

    Login::Login(){
        this->rememberMe = false;
    }

    Login::~Login() = default;

    bool Login::tryLogin(const std::string& email, const std::string& password, bool rememberMe) {
        MYSQL conn = DatabaseManager::getConnection();
        std::string query = "SELECT * FROM user WHERE email = '" + email + "' AND psw = '" + PswCipher::encrypt(password) + "'";
        if (mysql_query(&conn, query.c_str()) != 0) {
            throw std::runtime_error("Errore durante l'esecuzione della query: " + std::string(mysql_error(&conn)));
        }

        MYSQL_RES* res = mysql_store_result(&conn);
        if (mysql_num_rows(res) == 0) {
            return false;
        } else {
            storeCredenziali(email, password, rememberMe);
            return true;
        }
    }

    void Login::storeCredenziali(const std::string& email, const std::string& password, bool rememberMe) {
        std::ofstream file("credenziali.txt");
        if (file.is_open()) {
            file << rememberMe << "\n" << email << "\n" << password;
            file.close();
        }
    }

    void Login::retrieveCredenziali() {
        std::ifstream file("credenziali.txt");
        if (file.is_open()) {
            file >> this->rememberMe >> this->email >> this->password;
            file.close();
        }
    }

    std::string Login::getEmail() {
        return this->email;
    }

    std::string Login::getPassword() {
        return this->password;
    }

    bool Login::getRememberMe() {
        return this->rememberMe;
    }