//
// Created by Edoardo Nero on 04/07/24.
//

#ifndef PEERTOPAY_LOGINCONTROLLER_H
#define PEERTOPAY_LOGINCONTROLLER_H

#include <include/model/Login.h>
#include <include/view/LoginView.h>
#include "include/controller/RegisterController.h"
#include "include/controller/UserController.h"

class LoginController{
    public:
        explicit LoginController(LoginView* view, Login* model);
        ~LoginController();
        void init();
        void SwitchToRegister(wxCommandEvent& event);
        void StartProgram();
        void OnLogin(wxCommandEvent& event);

    private:
        void OnClose(wxCloseEvent& event);
        Login* model;
        LoginView* view;
};
#endif //PEERTOPAY_LOGINCONTROLLER_H
