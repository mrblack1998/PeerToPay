//
// Created by Edoardo Nero on 07/07/24.
//

#ifndef PEERTOPAY_USER_H
#define PEERTOPAY_USER_H

#include "string"
#include "HomePanel.h"
#include "SendPanel.h"
#include "ReceivePanel.h"
#include "BankAccountPanel.h"
#include "DatabaseManager.h"
#include "PswCipher.h"

class User {
public:
    User(const std::string &email, const std::string &password);
    ~User();
    void init();
    int getId() const;
    const std::string &getName() const;
    const std::string &getSurname() const;
    const std::string &getEmail() const;
    HomePanel* getHomePanel() const;
    SendPanel* getSendPanel() const;
    ReceivePanel* getReceivePanel() const;
    BankAccountPanel* getBankAccountPanel() const;

private:
    int id;
    std::string name;
    std::string surname;
    std::string email;
    std::string password;
    HomePanel* homePanel;
    SendPanel* sendPanel;
    ReceivePanel* receivePanel;
    BankAccountPanel* bankAccountPanel;

};


#endif //PEERTOPAY_USER_H
