//
// Created by Edoardo Nero on 08/07/24.
//

#ifndef PEERTOPAY_SENDPANEL_H
#define PEERTOPAY_SENDPANEL_H

#include "DatabaseManager.h"
#include "string"
#include "sstream"
#include "iomanip"

class SendPanel {
public:
    SendPanel();
    ~SendPanel();
    static bool sendMoney(const int &id, const std::string &amount, const std::string &code);

};


#endif //PEERTOPAY_SENDPANEL_H
