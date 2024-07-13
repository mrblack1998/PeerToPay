//
// Created by Edoardo Nero on 07/07/24.
//

#include "include/model/User.h"

User::User(const std::string &email, const std::string &password) {
    this->id = 0;
    this->email = email;
    this->password = password;
    this->homePanel = new HomePanel();
    this->sendPanel = new SendPanel();
    this->receivePanel = new ReceivePanel();
    this->bankAccountPanel = new BankAccountPanel();
    init();
}

User::~User() = default;

void User::init() {
    MYSQL conn = DatabaseManager::getConnection();
    std::string query = "SELECT * FROM user WHERE email = '" + this->email + "' AND psw = '" + PswCipher::encrypt(password) + "'";
    if (mysql_query(&conn, query.c_str()) != 0) {
        throw std::runtime_error("Errore durante l'esecuzione della query: " + std::string(mysql_error(&conn)));
    }

    MYSQL_RES* res = mysql_store_result(&conn);
    if (mysql_num_rows(res) == 1) {
        MYSQL_ROW row = mysql_fetch_row(res);
        this->id = std::stoi(row[0]);
        this->name = row[3];
        this->surname = row[4];
    } else {
        throw std::runtime_error("Nessun utente trovato con queste credenziali");
    }
}

int User::getId() const {
    return id;
}

const std::string &User::getName() const {
    return name;
}

const std::string &User::getSurname() const {
    return surname;
}

const std::string &User::getEmail() const {
    return email;
}

HomePanel *User::getHomePanel() const {
    return homePanel;
}

SendPanel *User::getSendPanel() const {
    return sendPanel;
}

ReceivePanel *User::getReceivePanel() const {
    return receivePanel;
}

BankAccountPanel *User::getBankAccountPanel() const {
    return bankAccountPanel;
}