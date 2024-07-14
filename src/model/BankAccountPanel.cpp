//
// Created by Edoardo Nero on 09/07/24.
//

#include "include/model/BankAccountPanel.h"

BankAccountPanel::BankAccountPanel() = default;

BankAccountPanel::~BankAccountPanel() = default;

std::vector<std::string> BankAccountPanel::getBankAccount(const int &id) {
    MYSQL conn = DatabaseManager::getConnection();
    std::string query = "SELECT account_number, expiration_date, cvv, balance FROM bank_account WHERE id_user = " + std::to_string(id);
    if (mysql_query(&conn, query.c_str()) != 0) {
        throw std::runtime_error("Errore durante l'esecuzione della query: " + std::string(mysql_error(&conn)));
    }

    std::vector<std::string> bankAccount;
    MYSQL_RES* res = mysql_store_result(&conn);
    if (mysql_num_rows(res) == 1) {
        MYSQL_ROW row = mysql_fetch_row(res);
        bankAccount.emplace_back(row[0]);
        bankAccount.emplace_back(row[1]);
        bankAccount.emplace_back(row[2]);
        bankAccount.emplace_back(row[3]);
        return bankAccount;
    } else {
        bankAccount.emplace_back("");
        bankAccount.emplace_back("");
        bankAccount.emplace_back("");
        bankAccount.emplace_back("");
        return bankAccount;
    }
}

bool BankAccountPanel::saveBankAccount(const int &id, const std::string &accountNumber, const std::string &expirationDate, const std::string &cvv, const std::string &balance) {
    if(!Utilities::isAllDigits(accountNumber)){
        throw std::invalid_argument("Account number non è composto da soli numeri.");
    }
    if(!Utilities::isValidExpirationDate(expirationDate)){
        throw std::invalid_argument("Data di scadenza non valida.");
    }
    if(!Utilities::isAllDigits(cvv) || cvv.length() != 3){
        throw std::invalid_argument("CVV non valido.");
    }

    MYSQL conn = DatabaseManager::getConnection();
    //verifica se esiste già un conto corrente per l'utente
    std::string query = "SELECT * FROM bank_account WHERE id_user = " + std::to_string(id);
    if (mysql_query(&conn, query.c_str()) != 0) {
        throw std::runtime_error("Errore durante l'esecuzione della query: " + std::string(mysql_error(&conn)));
    }else{
        MYSQL_RES* res = mysql_store_result(&conn);
        if (mysql_num_rows(res) == 1) {
            //se esiste già un conto corrente per l'utente, aggiorna i dati
            query = "UPDATE bank_account SET account_number = '" + accountNumber + "', expiration_date = '" + expirationDate + "', cvv = '" + cvv + "', balance = '" + Utilities::checkBalance(balance) + "' WHERE id_user = " + std::to_string(id);
        } else {
            //se non esiste un conto corrente per l'utente, inserisce i dati
            query = "INSERT INTO bank_account (id_user, account_number, expiration_date, cvv, balance) VALUES (" + std::to_string(id) + ", '" + accountNumber + "', '" + expirationDate + "', '" + cvv + "', '" + Utilities::checkBalance(balance) + "')";
        }
        //esegue la query
        if (mysql_query(&conn, query.c_str()) != 0) {
            throw std::runtime_error("Errore durante l'esecuzione della query: " + std::string(mysql_error(&conn)));
        } else {
            return true;
        }
    }
}