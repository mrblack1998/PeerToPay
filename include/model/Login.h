//
// Created by Edoardo Nero on 04/07/24.
//

#ifndef PEERTOPAY_LOGIN_H
#define PEERTOPAY_LOGIN_H

#include "string"
#include "fstream"
#include "DatabaseManager.h"
#include "PswCipher.h"

class Login{
    public:
        Login();
        ~Login();
        static bool tryLogin(const std::string& email, const std::string& password, bool rememberMe);
        static void storeCredenziali(const std::string& email, const std::string& password, bool rememberMe);
        void retrieveCredenziali();
        std::string getEmail();
        std::string getPassword();
        bool getRememberMe();

    private:
        std::string email;
        std::string password;
        bool rememberMe;  //Se true, salva le credenziali in un file di testo in caso di autenticazione riuscita

};
#endif //PEERTOPAY_LOGIN_H
