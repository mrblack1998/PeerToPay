//
// Created by Edoardo Nero on 09/07/24.
//

#include "include/view/BankAccountPanelView.h"

BankAccountPanelView::BankAccountPanelView(wxPanel *panel) {
    this->panel = panel;
    this->panel->SetSize(800, 600);
    this->panel->SetPosition(wxPoint(0, 0));

    auto * bankAccount = new wxStaticText(this->panel, wxID_ANY, "Gestisci Conto", wxPoint(10, 30), wxSize(780, 30), wxALIGN_CENTER_HORIZONTAL);
    bankAccount->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));

    auto * addressLabel = new wxStaticText(this->panel, wxID_ANY, "Numero Conto: ", wxPoint(30, 95), wxSize(100, 30), wxALIGN_LEFT);
    addressLabel->SetFont(wxFont(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    this->accountNumber = new wxTextCtrl(this->panel, wxID_ANY, "", wxPoint(230, 90), wxSize(250, 30), wxTE_LEFT);
    this->accountNumber->SetFont(wxFont(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));

    auto * amountLabel = new wxStaticText(this->panel, wxID_ANY, "Data Scadenza:", wxPoint(30, 160), wxSize(100, 30), wxALIGN_LEFT);
    amountLabel->SetFont(wxFont(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    this->expirationDate = new wxTextCtrl(this->panel, wxID_ANY, "", wxPoint(230, 155), wxSize(250, 30), wxTE_LEFT);
    this->expirationDate->SetFont(wxFont(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));

    auto * cvvLabel = new wxStaticText(this->panel, wxID_ANY, "CVV:", wxPoint(30, 225), wxSize(100, 30), wxALIGN_LEFT);
    cvvLabel->SetFont(wxFont(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    this->cvv = new wxTextCtrl(this->panel, wxID_ANY, "", wxPoint(230, 220), wxSize(250, 30), wxTE_LEFT);
    this->cvv->SetFont(wxFont(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));

    auto * balanceLabel = new wxStaticText(this->panel, wxID_ANY, "Saldo (€):", wxPoint(30, 290), wxSize(100, 30), wxALIGN_LEFT);
    balanceLabel->SetFont(wxFont(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    this->balance = new wxTextCtrl(this->panel, wxID_ANY, "", wxPoint(230, 285) , wxSize(250, 30), wxTE_LEFT);
    this->balance->SetFont(wxFont(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));

    this->saveButton = new wxButton(panel, wxID_ANY, "Salva Modifiche", wxPoint(300, 380), wxSize(200, 300));

}

BankAccountPanelView::~BankAccountPanelView() {
    this->panel->Destroy();
}

wxPanel *BankAccountPanelView::getPanel() {
    return this->panel;
}