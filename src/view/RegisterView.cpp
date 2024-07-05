//
// Created by Edoardo Nero on 03/07/24.
//

#include "include/view/RegisterView.h"

RegisterView::RegisterView(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(500, 500)) {
    auto* panel = new wxPanel(this, wxID_ANY);

    auto* vbox = new wxBoxSizer(wxVERTICAL);

    nameField = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(200, 25));
    surnameField = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(200, 25));
    emailField = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(200, 25));
    passwordField = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(200, 25), wxTE_PASSWORD);
    loginButton = new wxButton(panel, wxID_ANY, "Login");
    registerButton = new wxButton(panel, wxID_ANY, "Register");

    vbox->Add(nameField, 0, wxEXPAND | wxALL, 5);
    vbox->Add(surnameField, 0, wxEXPAND | wxALL, 5);
    vbox->Add(emailField, 0, wxEXPAND | wxALL, 5);
    vbox->Add(passwordField, 0, wxEXPAND | wxALL, 5);
    vbox->Add(loginButton, 0, wxEXPAND | wxALL, 5);
    vbox->Add(registerButton, 0, wxEXPAND | wxALL, 5);

    panel->SetSizer(vbox);
}

wxButton* RegisterView::getLoginButton() {
    return loginButton;
}

wxButton* RegisterView::getRegisterButton() {
    return registerButton;
}
