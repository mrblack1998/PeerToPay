//
// Created by Edoardo Nero on 08/07/24.
//

#include "include/view/SendPanelView.h"

SendPanelView::SendPanelView(wxPanel* panel) {

    this->panel = panel;
    this->panel->SetSize(800, 600);
    this->panel->SetPosition(wxPoint(0, 0));

    //scritta Invia denaro grande in alto
    auto * sendMoney = new wxStaticText(this->panel, wxID_ANY, "Invia denaro", wxPoint(10, 30), wxSize(780, 30), wxALIGN_CENTER_HORIZONTAL);
    sendMoney->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));

    auto * addressLabel = new wxStaticText(this->panel, wxID_ANY, "Codice", wxPoint(30, 95), wxSize(100, 30), wxALIGN_LEFT);
    addressLabel->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    this->address = new wxTextCtrl(this->panel, wxID_ANY, "", wxPoint(110, 90), wxSize(680, 30), wxTE_LEFT);
    this->address->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));

    auto * amountLabel = new wxStaticText(this->panel, wxID_ANY, "Importo", wxPoint(30, 205), wxSize(100, 30), wxALIGN_LEFT);
    amountLabel->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    this->amount = new wxTextCtrl(this->panel, wxID_ANY, "", wxPoint(110, 200), wxSize(680, 30), wxTE_LEFT);
    this->amount->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));

    this->sendButton = new wxButton(this->panel, wxID_ANY, "Trasferisci", wxPoint(300, 280), wxSize(200, 300));
}

SendPanelView::~SendPanelView() {
    this->panel->Destroy();
}

wxPanel *SendPanelView::getPanel() {
    return this->panel;
}