//
// Created by Edoardo Nero on 09/07/24.
//

#include "include/view/BankAccountPanelView.h"

BankAccountPanelView::BankAccountPanelView(wxPanel *panel) {
    this->panel = panel;
    this->panel->SetSize(500, 400);
    this->panel->SetPosition(wxPoint(0, 0));

    auto * bankAccount = new wxStaticText(this->panel, wxID_ANY, "Gestisci Conto", wxPoint(0, 30), wxSize(500, 30), wxALIGN_CENTER_HORIZONTAL);
    bankAccount->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));

    auto * addressLabel = new wxStaticText(this->panel, wxID_ANY, "Numero Conto:", wxPoint(0, 88), wxSize(250, 30), wxALIGN_CENTER_HORIZONTAL);
    addressLabel->SetFont(wxFont(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    this->accountNumber = new wxTextCtrl(this->panel, wxID_ANY, "", wxPoint(250, 83), wxSize(230, 30), wxALIGN_CENTER_HORIZONTAL);
    this->accountNumber->SetFont(wxFont(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));

    auto * amountLabel = new wxStaticText(this->panel, wxID_ANY, "Data Scadenza:", wxPoint(0, 145), wxSize(250, 30), wxALIGN_CENTER_HORIZONTAL);
    amountLabel->SetFont(wxFont(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    this->expirationDate = new wxTextCtrl(this->panel, wxID_ANY, "", wxPoint(250, 140), wxSize(230, 30), wxALIGN_CENTER_HORIZONTAL);
    this->expirationDate->SetFont(wxFont(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));

    auto * cvvLabel = new wxStaticText(this->panel, wxID_ANY, "CVV:", wxPoint(0, 200), wxSize(250, 30), wxALIGN_CENTER_HORIZONTAL);
    cvvLabel->SetFont(wxFont(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    this->cvv = new wxTextCtrl(this->panel, wxID_ANY, "", wxPoint(250, 195), wxSize(230, 30), wxALIGN_CENTER_HORIZONTAL);
    this->cvv->SetFont(wxFont(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));

    auto * balanceLabel = new wxStaticText(this->panel, wxID_ANY, "Saldo (€):", wxPoint(0, 260), wxSize(250, 30), wxALIGN_CENTER_HORIZONTAL);
    balanceLabel->SetFont(wxFont(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    this->balance = new wxTextCtrl(this->panel, wxID_ANY, "", wxPoint(250, 255) , wxSize(230, 30), wxALIGN_CENTER_HORIZONTAL);
    this->balance->SetFont(wxFont(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));

    this->saveButton = new wxButton(panel, wxID_ANY, "Salva Modifiche", wxPoint(150, 320), wxSize(200, 30));

}

BankAccountPanelView::~BankAccountPanelView() {
    this->panel->Destroy();
}

wxPanel *BankAccountPanelView::getPanel() {
    return this->panel;
}