//
// Created by Edoardo Nero on 08/07/24.
//

#include "include/view/HomePanelView.h"

HomePanelView::HomePanelView(wxPanel *panel) {
    this->panel = panel;
    this->panel->SetSize(500, 400);
    this->panel->SetPosition(wxPoint(0, 0));

    this->balance = new wxStaticText(this->panel, wxID_ANY, "0.00 €", wxPoint(0, 30), wxSize(500, 30), wxALIGN_CENTER_HORIZONTAL);
    this->balance->SetFont(wxFont(35, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    this->transactions = new wxListBox(this->panel, wxID_ANY, wxPoint(20, 88), wxSize(460, 200), 0, nullptr, wxLB_SINGLE | wxLB_NEEDED_SB | wxLB_SORT);
    this->exportButton = new wxButton(this->panel, wxID_ANY, "Esporta Movimenti", wxPoint(150, 315), wxSize(200, 30));
    //this->panel->Show();
}

HomePanelView::~HomePanelView() {
    this->panel->Destroy();
}

wxPanel *HomePanelView::getPanel() {
    return this->panel;
}