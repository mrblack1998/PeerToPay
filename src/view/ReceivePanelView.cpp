//
// Created by Edoardo Nero on 09/07/24.
//

#include "include/view/ReceivePanelView.h"

ReceivePanelView::ReceivePanelView(wxPanel *panel) {
    this->panel = panel;
    this->panel->SetSize(800, 600);
    this->panel->SetPosition(wxPoint(0, 0));

    //scritta Ricevi denaro grande in alto
    auto * receiveMoney = new wxStaticText(this->panel, wxID_ANY, "Ricevi denaro", wxPoint(10, 30), wxSize(780, 30), wxALIGN_CENTER_HORIZONTAL);
    receiveMoney->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));

    auto * addressLabel = new wxStaticText(this->panel, wxID_ANY, "Codice: ", wxPoint(30, 95), wxSize(100, 30), wxALIGN_LEFT);
    addressLabel->SetFont(wxFont(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    this->code = new wxStaticText(this->panel, wxID_ANY, "", wxPoint(110, 90), wxSize(680, 30), wxTE_LEFT);

    auto * amountLabel = new wxStaticText(this->panel, wxID_ANY, "Scadrà alle ore:", wxPoint(30, 205), wxSize(100, 30), wxALIGN_LEFT);
    amountLabel->SetFont(wxFont(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    this->expirationDate = new wxStaticText(this->panel, wxID_ANY, "", wxPoint(10, 30));


    this->generateButton = new wxButton(panel, wxID_ANY, "Genera Codice", wxPoint(300, 280), wxSize(200, 300));

}

ReceivePanelView::~ReceivePanelView() {
    this->panel->Destroy();
}

wxPanel *ReceivePanelView::getPanel() {
    return this->panel;
}