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

class UserController {
public:
    UserController(UserView* view, User* model);
    ~UserController();
    void init();

private:
    void switchPanel(wxCommandEvent& event);
    void onClose(wxCloseEvent& event);

    UserView* view;
    User* model;
};


#endif //PEERTOPAY_USERCONTROLLER_H
