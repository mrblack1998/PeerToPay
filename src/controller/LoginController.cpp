//
// Created by Edoardo Nero on 04/07/24.
//
#include "include/controller/LoginController.h"

LoginController::LoginController(LoginView* view, Login* model) {
    this->view = view;
    this->model = model;
    this->view->Bind(wxEVT_BUTTON, &LoginController::OnLogin, this, view->getLoginButton()->GetId());
    this->view->Bind(wxEVT_BUTTON, &LoginController::SwitchToRegister, this, view->getRegisterButton()->GetId());
    this->view->Bind(wxEVT_CLOSE_WINDOW, &LoginController::OnClose, this);
}

void LoginController::init() {
    this->model->retrieveCredenziali();
    if(this->model->getRememberMe()){
        this->view->getEmailField()->SetValue(this->model->getEmail());
        this->view->getPasswordField()->SetValue(this->model->getPassword());
        this->view->getRememberMe()->SetValue(this->model->getRememberMe());
    }
    StartProgram();
}

void LoginController::StartProgram(){
    this->view->Show(true);
}

void LoginController::SwitchToRegister(wxCommandEvent& event) {
    this->view->Show(false);
    auto* registerController = new RegisterController(new RegisterView("Peer to Pay - Register"),new Register());
    registerController->init();
}

void LoginController::OnLogin(wxCommandEvent& event) {
    try{
        if(model->tryLogin(this->view->getEmailField()->GetValue().ToStdString(), this->view->getPasswordField()->GetValue().ToStdString(), this->view->getRememberMe()->IsChecked())){
            this->view->Show(false);
            auto* userController = new UserController(new UserView("Peer to Pay - Dashboard"), new User(this->view->getEmailField()->GetValue().ToStdString(),this->view->getPasswordField()->GetValue().ToStdString()));
            userController->init();
        }else{
            wxMessageBox("Credenziali errate", "Errore", wxICON_ERROR);
        }
    }catch(std::exception &e){
        wxMessageBox(e.what(), "Errore", wxICON_ERROR);
    }

}

void LoginController::OnClose(wxCloseEvent &event) {
    this->view->Show(false);
    this->view->Destroy();
    exit(0);
}