//
// Created by Edoardo Nero on 06/07/24.
//

#ifndef PEERTOPAY_PSWCIPHER_H
#define PEERTOPAY_PSWCIPHER_H

#include "string"

class PswCipher {
public:
    PswCipher();
    ~PswCipher();
    static std::string encrypt(const std::string& psw);

};


#endif //PEERTOPAY_PSWCIPHER_H
