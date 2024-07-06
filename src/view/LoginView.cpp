//
// Created by Edoardo Nero on 03/07/24.
//

#include "include/view/LoginView.h"

LoginView::LoginView(const wxString& title): wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(500, 400)){
    auto* panel = new wxPanel(this, wxID_ANY);

    auto* vbox = new wxBoxSizer(wxVERTICAL);

    //Titolo del progetto in alto
    auto* p2p = new wxStaticText(panel, wxID_ANY, wxT("Peer to Pay"));
    p2p->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    vbox->Add(p2p, 0, wxALIGN_CENTER | wxTOP, 10);

    //spazio tra titolo e campi di testo
    vbox->Add(-1, 20);

    //prima linea
    auto* hbox = new wxBoxSizer(wxHORIZONTAL);

    //label email
    auto* emailLabel = new wxStaticText(panel, wxID_ANY, wxT("Email"));
    hbox->Add(emailLabel, 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);
    emailField = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(500, 25));
    hbox->Add(emailField, 0, wxFIXED_MINSIZE, 98);

    //aggiungo la prima linea al vbox
    vbox->Insert(2, hbox, 0, wxEXPAND | wxALL, 10);

    //seconda linea
    hbox = new wxBoxSizer(wxHORIZONTAL);

    //label password
    auto* passwordLabel = new wxStaticText(panel, wxID_ANY, wxT("Pswd"));
    hbox->Add(passwordLabel, 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);
    passwordField = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(500, 25), wxTE_PASSWORD);
    hbox->Add(passwordField, 0, wxFIXED_MINSIZE, 98);

    //aggiungo la seconda linea al vbox
    vbox->Insert(3, hbox, 0, wxEXPAND | wxALL, 10);

    //Ricordami checkbox
    rememberMe = new wxCheckBox(panel, wxID_ANY, wxT("Ricordami al prossimo accesso"));
    vbox->Add(rememberMe, 0, wxALIGN_CENTER | wxALL, 10);

    //Login Btn
    loginButton = new wxButton(panel, wxID_ANY, wxT("Accedi"), wxDefaultPosition, wxSize(200, 40));
    vbox->Add(loginButton, 0, wxALIGN_CENTER | wxALL, 10);
    //Bind(wxEVT_BUTTON, &LoginView::OnLogin, this, loginButton->GetId());

    //Linea divisoria
    auto* line = new wxStaticText(panel, wxID_ANY, wxT("--- oppure ---"));
    vbox->Add(line, 0, wxALIGN_CENTER | wxALL, 5);

    //Register Btn
    registerButton = new wxButton(panel, wxID_ANY, wxT("Registrati"), wxDefaultPosition, wxSize(200, 40));
    vbox->Add(registerButton, 0, wxALIGN_CENTER | wxALL, 10);
    //Bind(wxEVT_BUTTON, &LoginView::OnRegister, this, registerButton->GetId());

    //Link alla repository GitHub
    auto* githubLink = new wxStaticText(panel, wxID_ANY, wxT("GitHub: https://github.com/mrblack1998/PeerToPay"));
    vbox->Add(githubLink, 0, wxALIGN_CENTER | wxTOP, 10);

    panel->SetSizer(vbox);
}

wxTextCtrl* LoginView::getEmailField() {
    return emailField;
}

wxTextCtrl* LoginView::getPasswordField() {
    return passwordField;
}

wxCheckBox* LoginView::getRememberMe() {
    return rememberMe;
}

wxButton* LoginView::getLoginButton() {
    return loginButton;
}

wxButton* LoginView::getRegisterButton() {
    return registerButton;
}

void LoginView::OnLogin(wxCommandEvent &event) {

}
