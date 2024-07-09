//
// Created by Edoardo Nero on 07/07/24.
//

#include "include/model/User.h"

User::User(const std::string &email, const std::string &password) {
    this->id = 0;
    this->email = email;
    this->password = password;
}

User::~User() = default;

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