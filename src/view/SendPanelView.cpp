//
// Created by Edoardo Nero on 08/07/24.
//

#include "include/view/SendPanelView.h"

enum MenuIDs {
    ID_TRANSFER = 107
};

SendPanelView::SendPanelView(wxPanel* panel) {

    this->panel = panel;
    this->panel->SetSize(500, 400);
    this->panel->SetPosition(wxPoint(0, 0));

    //scritta Invia denaro grande in alto
    auto * sendMoney = new wxStaticText(this->panel, wxID_ANY, "Invia denaro", wxPoint(0, 30), wxSize(500, 30), wxALIGN_CENTER_HORIZONTAL);
    sendMoney->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    //sendMoney->SetBackgroundColour(wxColour(0, 0, 255));

    auto * addressLabel = new wxStaticText(this->panel, wxID_ANY, "Codice Destinatario", wxPoint(0, 105), wxSize(250, 30), wxALIGN_CENTER_HORIZONTAL);
    addressLabel->SetFont(wxFont(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    //addressLabel->SetBackgroundColour(wxColour(255, 0, 0));

    this->address = new wxTextCtrl(this->panel, wxID_ANY, "", wxPoint(250, 100), wxSize(230, 30), wxALIGN_CENTER_HORIZONTAL);
    this->address->SetFont(wxFont(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    //this->address->SetBackgroundColour(wxColour(0, 255, 0));

    auto * amountLabel = new wxStaticText(this->panel, wxID_ANY, "Importo (€)", wxPoint(0, 175), wxSize(250, 30), wxALIGN_CENTER_HORIZONTAL);
    amountLabel->SetFont(wxFont(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    //amountLabel->SetBackgroundColour(wxColour(255, 0, 0));
    this->amount = new wxTextCtrl(this->panel, wxID_ANY, "", wxPoint(250, 170), wxSize(230, 30), wxALIGN_CENTER_HORIZONTAL);
    this->amount->SetFont(wxFont(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    //this->amount->SetBackgroundColour(wxColour(0, 255, 0));

    this->sendButton = new wxButton(this->panel, wxID_ANY, "Trasferisci", wxPoint(150, 280), wxSize(200, 30), wxALIGN_CENTER_HORIZONTAL);
    this->sendButton->SetId(ID_TRANSFER);
}

SendPanelView::~SendPanelView() {
    this->panel->Destroy();
}

wxPanel *SendPanelView::getPanel() {
    return this->panel;
}

std::string SendPanelView::getAddress() {
    return this->address->GetValue().ToStdString();
}

std::string SendPanelView::getAmount() {
    return this->amount->GetValue().ToStdString();
}

void SendPanelView::clearFields() {
    this->address->Clear();
    this->amount->Clear();
}