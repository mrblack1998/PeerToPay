//
// Created by Edoardo Nero on 05/07/24.
//

#ifndef PEERTOPAY_REGISTER_H
#define PEERTOPAY_REGISTER_H

#include "wx/wx.h"
#include "DatabaseManager.h"
#include "PswCipher.h"

class Register {
public:
    Register();
    ~Register();
    bool TryRegister(const std::string& firstName, const std::string& lastName, const std::string& email, const std::string& password);


};


#endif //PEERTOPAY_REGISTER_H
