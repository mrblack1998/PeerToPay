//
// Created by Edoardo Nero on 03/07/24.
//

#include "include/view/RegisterView.h"

RegisterView::RegisterView(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(500, 400)) {
    auto* panel = new wxPanel(this, wxID_ANY);

    auto* vbox = new wxBoxSizer(wxVERTICAL);

    //Titolo del progetto in alto
    auto* p2p = new wxStaticText(panel, wxID_ANY, wxT("Peer to Pay"));
    p2p->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    vbox->Add(p2p, 0, wxALIGN_CENTER | wxTOP, 10);

    //prima linea
    auto* hbox = new wxBoxSizer(wxHORIZONTAL);

    hbox->Add(-1, 0);
    vbox->Insert(1, hbox, 0, wxEXPAND | wxALL, 0);

    //label nome
    auto* nameLabel = new wxStaticText(panel, wxID_ANY, wxT("Nome"));
    hbox->Add(nameLabel, 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);
    nameField = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(30, 43), wxSize(180, 25));
    hbox->Add(nameField, 0, wxFIXED_MINSIZE, 98);

    hbox->AddSpacer(10);

    //label cognome
    auto* surnameLabel = new wxStaticText(panel, wxID_ANY, wxT("Cognome"));
    hbox->Add(surnameLabel, 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);
    surnameField = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(200, 25));
    hbox->Add(surnameField, 0, wxFIXED_MINSIZE, 98);

    //aggiungo la prima linea al vbox
    vbox->Insert(2, hbox, 0, wxEXPAND | wxALL, 10);

    //seconda linea
    hbox = new wxBoxSizer(wxHORIZONTAL);

    //label email
    auto* emailLabel = new wxStaticText(panel, wxID_ANY, wxT("Email"));
    hbox->Add(emailLabel, 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);
    emailField = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(500, 25));
    hbox->Add(emailField, 0, wxFIXED_MINSIZE, 98);

    //aggiungo la seconda linea al vbox
    vbox->Insert(3, hbox, 0, wxEXPAND | wxALL, 10);

    //terza linea
    hbox = new wxBoxSizer(wxHORIZONTAL);

    //label password
    auto* passwordLabel = new wxStaticText(panel, wxID_ANY, wxT("Pswd"));
    hbox->Add(passwordLabel, 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);
    passwordField = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(500, 25), wxTE_PASSWORD);
    hbox->Add(passwordField, 0, wxFIXED_MINSIZE, 98);

    //aggiungo la terza linea al vbox
    vbox->Insert(4, hbox, 0, wxEXPAND | wxALL, 10);


    registerButton = new wxButton(panel, wxID_ANY, "Registrati", wxDefaultPosition, wxSize(200, 40));
    vbox->Add(registerButton, 0, wxALIGN_CENTER | wxALL, 5);

    //Linea divisoria
    auto* line = new wxStaticText(panel, wxID_ANY, wxT("--- oppure ---"));
    vbox->Add(line, 0, wxALIGN_CENTER | wxALL, 5);

    loginButton = new wxButton(panel, wxID_ANY, "Accedi", wxDefaultPosition, wxSize(200, 40));
    vbox->Add(loginButton, 0, wxALIGN_CENTER | wxALL, 5);

    panel->SetSizer(vbox);
}

wxTextCtrl* RegisterView::getFirstNameField() {
    return nameField;
}

wxTextCtrl* RegisterView::getLastNameField() {
    return surnameField;
}

wxTextCtrl* RegisterView::getEmailField() {
    return emailField;
}

wxTextCtrl* RegisterView::getPasswordField() {
    return passwordField;
}

wxButton* RegisterView::getLoginButton() {
    return loginButton;
}

wxButton* RegisterView::getRegisterButton() {
    return registerButton;
}
