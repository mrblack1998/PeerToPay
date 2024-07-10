//
// Created by Edoardo Nero on 07/07/24.
//

#include "include/controller/UserController.h"

enum MenuIDs {
    ID_HOME = 100,
    ID_SEND = 101,
    ID_RECEIVE = 102,
    ID_ACCOUNT = 103,
    ID_LOGOUT = 104,
    ID_SAVE = 105
};

UserController::UserController(UserView* view, User* model) : view(view), model(model) {
    view->Bind(wxEVT_CLOSE_WINDOW, &UserController::onClose, this);
    // Bind dei menu
    view->Bind(wxEVT_MENU, &UserController::switchPanel, this, ID_HOME);
    view->Bind(wxEVT_MENU, &UserController::switchPanel, this, ID_SEND);
    view->Bind(wxEVT_MENU, &UserController::switchPanel, this, ID_RECEIVE);
    view->Bind(wxEVT_MENU, &UserController::switchPanel, this, ID_ACCOUNT);
    view->Bind(wxEVT_MENU, &UserController::switchPanel, this, ID_LOGOUT);
    // Bind dei pulsanti della GUI BankAccountPanelView
    view->Bind(wxEVT_BUTTON, &UserController::saveBankAccount, this, ID_SAVE);
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
    if(event.GetId() == ID_HOME){
        auto* panelCreator = new HomePanelView(new wxPanel(view));
        newPanel = panelCreator->getPanel();
        view->getPanel()->Show(false);
        view->setPanelToUse(newPanel, panelCreator);
    }else if(event.GetId() == ID_SEND){
        auto* panelCreator = new SendPanelView(new wxPanel(view));
        newPanel = panelCreator->getPanel();
        view->getPanel()->Show(false);
        view->setPanelToUse(newPanel, panelCreator);
    }else if(event.GetId() == ID_RECEIVE){
        auto* panelCreator = new ReceivePanelView(new wxPanel(view));
        newPanel = panelCreator->getPanel();
        view->getPanel()->Show(false);
        view->setPanelToUse(newPanel, panelCreator);
    }else if(event.GetId() == ID_ACCOUNT){
        auto* panelCreator = new BankAccountPanelView(new wxPanel(view), model->getBankAccountPanel()->getBankAccount(model->getId()));
        newPanel = panelCreator->getPanel();
        view->getPanel()->Show(false);
        view->setPanelToUse(newPanel, panelCreator);
    } else if(event.GetId() == ID_LOGOUT){
        newPanel = nullptr;
    }

    if (newPanel == nullptr) {
        view->Show(false);
        auto* loginController = new LoginController(new LoginView("Peer to Pay - Login"),new Login());
        loginController->init();
    }
}

UserController::~UserController() {
    delete view;
    delete model;
}

//BankAccountPanelView

void UserController::saveBankAccount(wxCommandEvent &event) {
    //controlla se il pannello è quello di BankAccountPanelView
    auto * bankAccountPanel = std::any_cast<BankAccountPanelView*>(view->getCreatorObject());
    std::string accountNumber = bankAccountPanel->getAccountNumber();
    std::string expirationDate = bankAccountPanel->getExpirationDate();
    std::string cvv = bankAccountPanel->getCvv();
    std::string balance = bankAccountPanel->getBalance();
    try {
        if (model->getBankAccountPanel()->saveBankAccount(model->getId(), accountNumber, expirationDate, cvv, balance)) {
            wxMessageBox("Conto salvato con successo.", "Successo", wxICON_INFORMATION);
        } else {
            wxMessageBox("Errore durante il salvataggio del conto.", "Errore", wxICON_ERROR);
        }
    } catch (const std::invalid_argument& e) {
        wxMessageBox(e.what(), "Errore", wxICON_ERROR);
    } catch (const std::out_of_range& e) {
        wxMessageBox(e.what(), "Errore", wxICON_ERROR);
    }
}