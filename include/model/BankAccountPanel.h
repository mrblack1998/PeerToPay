//
// Created by Edoardo Nero on 09/07/24.
//

#ifndef PEERTOPAY_BANKACCOUNTPANEL_H
#define PEERTOPAY_BANKACCOUNTPANEL_H

#include "vector"
#include "string"
#include "sstream"
#include "iomanip"
#include "DatabaseManager.h"
#include "Utilities.h"

class BankAccountPanel: public Utilities {
public:
    BankAccountPanel();
    ~BankAccountPanel();
    static std::vector<std::string> getBankAccount(const int &id);
    static bool saveBankAccount(const int &id, const std::string &accountNumber, const std::string &expirationDate, const std::string &cvv, const std::string &balance);

};


#endif //PEERTOPAY_BANKACCOUNTPANEL_H
