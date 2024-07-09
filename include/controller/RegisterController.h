//
// Created by Edoardo Nero on 05/07/24.
//

#ifndef PEERTOPAY_REGISTERCONTROLLER_H
#define PEERTOPAY_REGISTERCONTROLLER_H

#include "include/model/Register.h"
#include "include/view/RegisterView.h"
#include "include/controller/LoginController.h"

class RegisterController {
public:
    RegisterController(RegisterView* view, Register* model);
    void init();
    void switchToLogin(wxCommandEvent& event);
    void onRegister(wxCommandEvent& event);

private:
    void onClose(wxCloseEvent& event);

    RegisterView* view;
    Register* model;
};


#endif //PEERTOPAY_REGISTERCONTROLLER_H
