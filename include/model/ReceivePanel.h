//
// Created by Edoardo Nero on 09/07/24.
//

#ifndef PEERTOPAY_RECEIVEPANEL_H
#define PEERTOPAY_RECEIVEPANEL_H

#include "DatabaseManager.h"
#include "string"

class ReceivePanel {
public:
    ReceivePanel();
    ~ReceivePanel();
    static std::vector<std::string> getCode(const int &id);
    static std::vector<std::string> generateCode(const int &id);

};


#endif //PEERTOPAY_RECEIVEPANEL_H
