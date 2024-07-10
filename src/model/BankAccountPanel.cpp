//
// Created by Edoardo Nero on 09/07/24.
//

#include "include/model/BankAccountPanel.h"
#include "iostream"

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
        return bankAccount;
    }
}

bool isAllDigits(const std::string& val) {
    return std::all_of(val.begin(), val.end(), ::isdigit);
}

bool isValidExpirationDate(const std::string& expirationDate) {
    if(expirationDate.length() != 5){
        return false;
    }
    if(expirationDate[2] != '/'){
        return false;
    }
    std::string month = expirationDate.substr(0, 2);
    std::string year = expirationDate.substr(3, 2);
    if(!isAllDigits(month) || !isAllDigits(year)){
        return false;
    }
    int monthInt = std::stoi(month);
    int yearInt = std::stoi(year);
    if(monthInt < 1 || monthInt > 12){
        return false;
    }
    if(yearInt < 21 || yearInt > 99){
        return false;
    }
    return true;
}

std::string formatBalance(const std::string& balance) {
    std::string balanceFormatted = balance;
    std::replace(balanceFormatted.begin(), balanceFormatted.end(), ',', '.');

    double number;
    try {
        number = std::stod(balanceFormatted);
    } catch (const std::invalid_argument& e) {
        throw std::invalid_argument("Balance non è un numero valido.");
    } catch (const std::out_of_range& e) {
        throw std::out_of_range("Balance è fuori dall'intervallo consentito.");
    }

    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2) << number;
    return stream.str();
}

bool BankAccountPanel::saveBankAccount(const int &id, const std::string &accountNumber, const std::string &expirationDate, const std::string &cvv, const std::string &balance) {
    //verificare se accountNumber è composto da tutti numeri
    if(!isAllDigits(accountNumber)){
        throw std::invalid_argument("Account number non è composto da soli numeri.");
    }
    if(!isValidExpirationDate(expirationDate)){
        throw std::invalid_argument("Data di scadenza non valida.");
    }
    if(!isAllDigits(cvv) || cvv.length() != 3){
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
            query = "UPDATE bank_account SET account_number = '" + accountNumber + "', expiration_date = '" + expirationDate + "', cvv = '" + cvv + "', balance = '" + formatBalance(balance) + "' WHERE id_user = " + std::to_string(id);
        } else {
            //se non esiste un conto corrente per l'utente, inserisce i dati
            query = "INSERT INTO bank_account (id_user, account_number, expiration_date, cvv, balance) VALUES (" + std::to_string(id) + ", '" + accountNumber + "', '" + expirationDate + "', '" + cvv + "', '" + formatBalance(balance) + "')";
        }
        //esegue la query
        if (mysql_query(&conn, query.c_str()) != 0) {
            throw std::runtime_error("Errore durante l'esecuzione della query: " + std::string(mysql_error(&conn)));
        } else {
            return true;
        }
    }
}