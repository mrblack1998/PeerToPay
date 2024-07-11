//
// Created by Edoardo Nero on 08/07/24.
//

#ifndef PEERTOPAY_HOMEPANEL_H
#define PEERTOPAY_HOMEPANEL_H

#include "vector"
#include "string"
#include "DatabaseManager.h"
#include "Transazione.h"

class HomePanel {
public:
    explicit HomePanel();
    ~HomePanel();
    static std::string getBalance(const int &id);
    static std::vector<Transazione> getTransactions(const int &id);

};


#endif //PEERTOPAY_HOMEPANEL_H
