//
// Created by Edoardo Nero on 05/07/24.
//

#include "include/controller/RegisterController.h"
#include "include/controller/LoginController.h"

RegisterController::RegisterController(RegisterView* view, Register* model) : view(view), model(model) {
    //view->getRegisterButton()->Bind(wxEVT_BUTTON, &RegisterController::OnRegister, this);
    view->getLoginButton()->Bind(wxEVT_BUTTON, &RegisterController::SwitchToLogin, this);
}

void RegisterController::Init() {
    view->Show(true);
}

void RegisterController::SwitchToLogin(wxCommandEvent& event) {
    view->Show(false);
    auto* loginController = new LoginController(new LoginView("Peer to Pay - Login"),new Login());
    loginController->Init();
}