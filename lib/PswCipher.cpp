//
// Created by Edoardo Nero on 06/07/24.
//

#include "PswCipher.h"

PswCipher::PswCipher() = default;

PswCipher::~PswCipher() = default;

std::string PswCipher::encrypt(const std::string& psw) {
    std::string encryptedPsw;
    for (char i : psw) {
        encryptedPsw += i + 3;
    }
    return encryptedPsw;
}