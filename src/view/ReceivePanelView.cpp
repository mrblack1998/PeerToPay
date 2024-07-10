//
// Created by Edoardo Nero on 09/07/24.
//

#include "include/view/ReceivePanelView.h"

enum MenuIDs {
    ID_GENERATE = 106
};

ReceivePanelView::ReceivePanelView(wxPanel *panel, const std::vector<std::string>& parametri) {
    this->panel = panel;
    this->panel->SetSize(500, 400);
    this->panel->SetPosition(wxPoint(0, 0));

    std::string code = parametri[0];
    std::string expirationDate = parametri[1];

    if(code.empty()) {
        code = "- - - - -";
    }

    if(expirationDate.empty()) {
        expirationDate = "--:--:--";
    }

    //scritta Ricevi denaro grande in alto
    auto * receiveMoney = new wxStaticText(this->panel, wxID_ANY, "Ricevi denaro", wxPoint(0, 30), wxSize(500, 30), wxALIGN_CENTER_HORIZONTAL);
    receiveMoney->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));

    auto * addressLabel = new wxStaticText(this->panel, wxID_ANY, "Codice:", wxPoint(0, 105), wxSize(250, 30), wxALIGN_CENTER_HORIZONTAL);
    addressLabel->SetFont(wxFont(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    this->code = new wxStaticText(this->panel, wxID_ANY, code, wxPoint(250, 105), wxSize(230, 30), wxALIGN_CENTER_HORIZONTAL);
    this->code->SetFont(wxFont(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));

    auto * amountLabel = new wxStaticText(this->panel, wxID_ANY, "Scadrà alle ore:", wxPoint(0, 175), wxSize(250, 30), wxALIGN_CENTER_HORIZONTAL);
    amountLabel->SetFont(wxFont(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    this->expirationDate = new wxStaticText(this->panel, wxID_ANY, expirationDate, wxPoint(250, 175), wxSize(230, 30), wxALIGN_CENTER_HORIZONTAL);
    this->expirationDate->SetFont(wxFont(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));

    this->generateButton = new wxButton(panel, wxID_ANY, "Genera Codice", wxPoint(150, 280), wxSize(200, 30), wxALIGN_CENTER_HORIZONTAL);
    this->generateButton->SetId(ID_GENERATE);
}

ReceivePanelView::~ReceivePanelView() {
    this->panel->Destroy();
}

wxPanel *ReceivePanelView::getPanel() {
    return this->panel;
}

void ReceivePanelView::setCode(const std::string &code) {
    this->code->SetLabel(code);
}

void ReceivePanelView::setExpirationDate(const std::string &expirationDate) {
    this->expirationDate->SetLabel(expirationDate);
}