//
// Created by Edoardo Nero on 04/07/24.
//

#include "include/controller/LoginController.h"
#include "include/controller/RegisterController.h"

LoginController::LoginController(LoginView* view, Login* model) {
    this->view = view;
    this->model = model;
    this->view->Bind(wxEVT_BUTTON, &LoginController::OnLogin, this, view->getLoginButton()->GetId());
    this->view->Bind(wxEVT_BUTTON, &LoginController::SwitchToRegister, this, view->getRegisterButton()->GetId());
}

void LoginController::Init() {
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
    registerController->Init();
}

void LoginController::OnLogin(wxCommandEvent& event) {
    if(model->tryLogin(this->view->getEmailField()->GetValue().ToStdString(), this->view->getPasswordField()->GetValue().ToStdString(), this->view->getRememberMe()->IsChecked())){
        wxMessageBox("Login effettuato con successo", "Successo", wxICON_INFORMATION);
    }else{
        wxMessageBox("Credenziali errate", "Errore", wxICON_ERROR);
    }
}

