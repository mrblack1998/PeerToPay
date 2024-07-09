//
// Created by Edoardo Nero on 05/07/24.
//

#include "include/controller/RegisterController.h"

RegisterController::RegisterController(RegisterView* view, Register* model) : view(view), model(model) {
    view->getRegisterButton()->Bind(wxEVT_BUTTON, &RegisterController::onRegister, this);
    view->getLoginButton()->Bind(wxEVT_BUTTON, &RegisterController::switchToLogin, this);
    view->Bind(wxEVT_CLOSE_WINDOW, &RegisterController::onClose, this);
}

void RegisterController::init() {
    view->Show(true);
}

void RegisterController::switchToLogin(wxCommandEvent& event) {
    view->Show(false);
    auto* loginController = new LoginController(new LoginView("Peer to Pay - Login"),new Login());
    loginController->init();
}

void RegisterController::onClose(wxCloseEvent &event) {
    view->Show(false);
    view->Destroy();
    exit(0);
}

void RegisterController::onRegister(wxCommandEvent &event) {
    if(view->getFirstNameField()->GetValue().IsEmpty() || view->getLastNameField()->GetValue().IsEmpty() || view->getEmailField()->GetValue().IsEmpty() || view->getPasswordField()->GetValue().IsEmpty()){
        wxMessageBox("Compilare tutti i campi", "Errore", wxICON_ERROR);
        return;
    }
    try{
        if(model->TryRegister(view->getFirstNameField()->GetValue().ToStdString(), view->getLastNameField()->GetValue().ToStdString(), view->getEmailField()->GetValue().ToStdString(), view->getPasswordField()->GetValue().ToStdString())){
            wxMessageBox("Registrazione effettuata con successo", "Successo", wxICON_INFORMATION);
            switchToLogin(event);
        }else{
            wxMessageBox("Email già presente nel database", "Errore", wxICON_ERROR);
        }
    }catch (std::exception& e){
        wxMessageBox(e.what(), "Errore", wxICON_ERROR);
    }
}