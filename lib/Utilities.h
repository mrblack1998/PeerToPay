//
// Created by Edoardo Nero on 14/07/24.
//

#ifndef PEERTOPAY_UTILITIES_H
#define PEERTOPAY_UTILITIES_H

#include <string>
#include "sstream"
#include "iomanip"

class Utilities {
public:
    static std::string checkBalance(const std::string& balance);
    static bool isAllDigits(const std::string& val);
    static bool isValidExpirationDate(const std::string& expirationDate);
};


#endif //PEERTOPAY_UTILITIES_H
