//
// Created by Edoardo Nero on 08/07/24.
//

#include "include/view/HomePanelView.h"

HomePanelView::HomePanelView(wxPanel *panel) {
    this->panel = panel;
    this->panel->SetSize(800, 600);
    this->panel->SetPosition(wxPoint(0, 0));

    this->balance = new wxStaticText(this->panel, wxID_ANY, "0.00 €", wxPoint(10, 37), wxSize(780, 30), wxALIGN_CENTER_HORIZONTAL);
    this->balance->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    this->transactions = new wxListBox(this->panel, wxID_ANY, wxPoint(150, 100), wxSize(500, 400), 0, nullptr, wxLB_SINGLE | wxLB_NEEDED_SB | wxLB_SORT);
    this->exportButton = new wxButton(this->panel, wxID_ANY, "Esporta transazioni", wxPoint(300, 525), wxSize(200, 20));
    //this->panel->Show();
}

HomePanelView::~HomePanelView() {
    this->panel->Destroy();
}

wxPanel *HomePanelView::getPanel() {
    return this->panel;
}