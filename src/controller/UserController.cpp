//
// Created by Edoardo Nero on 07/07/24.
//

#include "include/controller/UserController.h"

enum MenuIDs {
    ID_HOME = 100,
    ID_SEND = 101,
    ID_RECEIVE = 102,
    ID_ACCOUNT = 103,
    ID_LOGOUT = 104
};

UserController::UserController(UserView* view, User* model) : view(view), model(model) {
    view->Bind(wxEVT_CLOSE_WINDOW, &UserController::onClose, this);
    view->Bind(wxEVT_MENU, &UserController::switchPanel, this, ID_HOME);
    view->Bind(wxEVT_MENU, &UserController::switchPanel, this, ID_SEND);
    view->Bind(wxEVT_MENU, &UserController::switchPanel, this, ID_RECEIVE);
    view->Bind(wxEVT_MENU, &UserController::switchPanel, this, ID_ACCOUNT);
    view->Bind(wxEVT_MENU, &UserController::switchPanel, this, ID_LOGOUT);
}

void UserController::init() {
    view->Show(true);
}

void UserController::onClose(wxCloseEvent &event) {
    view->Show(false);
    view->Destroy();
    exit(0);
}

void UserController::switchPanel(wxCommandEvent &event) {
    wxPanel* newPanel = nullptr;
    switch (event.GetId()) {
        case ID_HOME:
            newPanel = (new HomePanelView(new wxPanel(view)))->getPanel();
            break;
        case ID_SEND:
            newPanel = (new SendPanelView(new wxPanel(view)))->getPanel();
            break;
        case ID_RECEIVE:
            newPanel = (new ReceivePanelView(new wxPanel(view)))->getPanel();
            std::cout << "Receive" << std::endl;
            break;
        case ID_ACCOUNT:
            newPanel = (new BankAccountPanelView(new wxPanel(view)))->getPanel();
            std::cout << "Account" << std::endl;
            break;
        case ID_LOGOUT:
            std::cout << "Logout" << std::endl;
            // Gestisci il logout qui
            break;
        default:
            return; // Nessuna azione se l'ID non corrisponde
    }
    if (newPanel != nullptr) {
        view->setPanelToUse(newPanel);
    }
}

UserController::~UserController() {
    delete view;
    delete model;
}
