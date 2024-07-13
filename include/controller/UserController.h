//
// Created by Edoardo Nero on 07/07/24.
//

#ifndef PEERTOPAY_USERCONTROLLER_H
#define PEERTOPAY_USERCONTROLLER_H

#include "include/view/UserView.h"
#include "include/model/User.h"
#include "include/view/HomePanelView.h"
#include "include/view/SendPanelView.h"
#include "include/view/ReceivePanelView.h"
#include "include/view/BankAccountPanelView.h"
#include "include/controller/LoginController.h"

class UserController {
public:
    UserController(UserView* view, User* model);
    ~UserController();
    void init();
    void switchPanelTest(wxCommandEvent& event);

private:
    void switchPanel(wxCommandEvent& event);
    void onClose(wxCloseEvent& event);
    void saveBankAccount(wxCommandEvent& event);
    void generateCode(wxCommandEvent& event);
    void sendMoney(wxCommandEvent& event);
    void exportTransactions(wxCommandEvent& event);

    UserView* view;
    User* model;
};


#endif //PEERTOPAY_USERCONTROLLER_H
