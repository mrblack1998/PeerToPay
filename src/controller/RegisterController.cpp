//
// Created by Edoardo Nero on 05/07/24.
//

#include "include/controller/RegisterController.h"
#include "include/controller/LoginController.h"

RegisterController::RegisterController(RegisterView* view, Register* model) : view(view), model(model) {
    view->getRegisterButton()->Bind(wxEVT_BUTTON, &RegisterController::OnRegister, this);
    view->getLoginButton()->Bind(wxEVT_BUTTON, &RegisterController::SwitchToLogin, this);
    view->Bind(wxEVT_CLOSE_WINDOW, &RegisterController::OnClose, this);
}

void RegisterController::Init() {
    view->Show(true);
}

void RegisterController::SwitchToLogin(wxCommandEvent& event) {
    view->Show(false);
    auto* loginController = new LoginController(new LoginView("Peer to Pay - Login"),new Login());
    loginController->Init();
}

void RegisterController::OnClose(wxCloseEvent &event) {
    view->Show(false);
    view->Destroy();
    exit(0);
}

void RegisterController::OnRegister(wxCommandEvent &event) {
    if(view->getFirstNameField()->GetValue().IsEmpty() || view->getLastNameField()->GetValue().IsEmpty() || view->getEmailField()->GetValue().IsEmpty() || view->getPasswordField()->GetValue().IsEmpty()){
        wxMessageBox("Compilare tutti i campi", "Errore", wxICON_ERROR);
        return;
    }
    try{
        if(model->TryRegister(view->getFirstNameField()->GetValue().ToStdString(), view->getLastNameField()->GetValue().ToStdString(), view->getEmailField()->GetValue().ToStdString(), view->getPasswordField()->GetValue().ToStdString())){
            wxMessageBox("Registrazione effettuata con successo", "Successo", wxICON_INFORMATION);
            SwitchToLogin(event);
        }else{
            wxMessageBox("Email già presente nel database", "Errore", wxICON_ERROR);
        }
    }catch (std::exception& e){
        wxMessageBox(e.what(), "Errore", wxICON_ERROR);
    }
}