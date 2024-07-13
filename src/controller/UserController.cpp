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
    ID_SAVE = 105,
    ID_GENERATE = 106,
    ID_TRANSFER = 107,
    ID_EXPORT = 108
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
    //Bind dei pulsanti della GUI ReceivePanelView
    view->Bind(wxEVT_BUTTON, &UserController::generateCode, this, ID_GENERATE);
    //Bind dei pulsanti della GUI SendPanelView
    view->Bind(wxEVT_BUTTON, &UserController::sendMoney, this, ID_TRANSFER);
    //Bind dei pulsanti della GUI HomePanelView
    view->Bind(wxEVT_BUTTON, &UserController::exportTransactions, this, ID_EXPORT);
}

void UserController::init() {
    auto* panelCreator = new HomePanelView(new wxPanel(view), model->getHomePanel()->getBalance(model->getId()), model->getHomePanel()->getTransactions(model->getId()));
    wxPanel* newPanel = panelCreator->getPanel();
    view->getPanel()->Show(false);
    view->setPanelToUse(newPanel, panelCreator);
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
        auto* panelCreator = new HomePanelView(new wxPanel(view), model->getHomePanel()->getBalance(model->getId()), model->getHomePanel()->getTransactions(model->getId()));
        newPanel = panelCreator->getPanel();
        view->getPanel()->Show(false);
        view->setPanelToUse(newPanel, panelCreator);
    }else if(event.GetId() == ID_SEND){
        auto* panelCreator = new SendPanelView(new wxPanel(view));
        newPanel = panelCreator->getPanel();
        view->getPanel()->Show(false);
        view->setPanelToUse(newPanel, panelCreator);
    }else if(event.GetId() == ID_RECEIVE){
        auto* panelCreator = new ReceivePanelView(new wxPanel(view), model->getReceivePanel()->getCode(model->getId()));
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

//ReceivePanelView

void UserController::generateCode(wxCommandEvent &event) {
    auto * receivePanel = std::any_cast<ReceivePanelView*>(view->getCreatorObject());
    try {
        std::vector<std::string> parametri = model->getReceivePanel()->generateCode(model->getId());
        receivePanel->setCode(parametri[0]);
        receivePanel->setExpirationDate(parametri[1]);
    } catch (const std::invalid_argument& e) {
        wxMessageBox(e.what(), "Errore", wxICON_ERROR);
    } catch (const std::out_of_range& e) {
        wxMessageBox(e.what(), "Errore", wxICON_ERROR);
    }
}

//SendPanelView

void UserController::sendMoney(wxCommandEvent &event) {
    auto * sendPanel = std::any_cast<SendPanelView*>(view->getCreatorObject());
    std::string code = sendPanel->getAddress();
    std::string amount = sendPanel->getAmount();
    try {
        if (model->getSendPanel()->sendMoney(model->getId(), amount, code)) {
            wxMessageBox("Transazione completata con successo.", "Successo", wxICON_INFORMATION);
            sendPanel->clearFields();
        } else {
            wxMessageBox("Errore durante la transazione.", "Errore", wxICON_ERROR);
        }
    } catch (const std::invalid_argument& e) {
        wxMessageBox(e.what(), "Errore", wxICON_ERROR);
    } catch (const std::out_of_range& e) {
        wxMessageBox(e.what(), "Errore", wxICON_ERROR);
    }catch (const std::runtime_error& e) {
        wxMessageBox(e.what(), "Errore", wxICON_ERROR);
    }catch (const std::exception& e) {
        wxMessageBox(e.what(), "Errore", wxICON_ERROR);
    }
}

//HomePanelView
void UserController::exportTransactions(wxCommandEvent &event) {
    std::vector<Transazione> transactions = model->getHomePanel()->getTransactions(model->getId());
    //crea il file txt con i movimenti (1 per riga)
    std::ofstream file("movimenti.txt");
    //la prima riga contiene i nomi delle colonne
    file << "ID - Mittente - Destinatario - Importo - Tipo - Data e Orario" << std::endl;
    for (const auto& transaction : transactions) {
        //importo in formato 0.00
        std::string importo = std::to_string(transaction.getImporto());
        if(importo.find('.') != std::string::npos) {
            importo = importo.substr(0, importo.find('.') + 3);
        }else{
            importo += ".00";
        }
        importo += " €";
        //data in formato gg/mm/aa hh:mm
        std::string data = transaction.getData();
        data = data.substr(0, data.find(' '));
        data = data.substr(8, 2) + "/" + data.substr(5, 2) + "/" + data.substr(2, 2) + " " + transaction.getData().substr(11, 5);
        //salvo la riga nel file
        file << transaction.getId() << " - " << transaction.getMittente() << " - " << transaction.getDestinatario() << " - " << importo << " - " << (transaction.getTipo() ? "Entrata" : "Uscita") << " - " << data << std::endl;
    }
    file.close();
    wxMessageBox("Movimenti esportati con successo.", "Successo", wxICON_INFORMATION);
}

//Test

void UserController::switchPanelTest(wxCommandEvent& event) {
    switchPanel(event);
}