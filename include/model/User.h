//
// Created by Edoardo Nero on 07/07/24.
//

#ifndef PEERTOPAY_USER_H
#define PEERTOPAY_USER_H

#include "string"

class User {
public:
    User(const std::string &email, const std::string &password);
    ~User();
    void init();
    int getId() const;
    const std::string &getName() const;
    const std::string &getSurname() const;
    const std::string &getEmail() const;

private:
    int id;
    std::string name;
    std::string surname;
    std::string email;
    std::string password;
};


#endif //PEERTOPAY_USER_H
