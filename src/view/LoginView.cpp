//
// Created by Edoardo Nero on 03/07/24.
//

#include "include/view/LoginView.h"

LoginView::LoginView(const wxString& title)
        : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(300, 200))
{
    auto* panel = new wxPanel(this, wxID_ANY);

    auto* vbox = new wxBoxSizer(wxVERTICAL);

    auto* emailLabel = new wxStaticText(panel, wxID_ANY, wxT("Email"));
    vbox->Add(emailLabel, 0, wxALIGN_CENTER | wxTOP, 10);

    emailField = new wxTextCtrl(panel, wxID_ANY);
    vbox->Add(emailField, 0, wxEXPAND | wxALL, 10);

    auto* passwordLabel = new wxStaticText(panel, wxID_ANY, wxT("Password"));
    vbox->Add(passwordLabel, 0, wxALIGN_CENTER | wxTOP, 10);

    passwordField = new wxTextCtrl(panel, wxID_ANY);
    vbox->Add(passwordField, 0, wxEXPAND | wxALL, 10);

    wxButton* loginButton = new wxButton(panel, wxID_ANY, wxT("Login"));
    vbox->Add(loginButton, 0, wxALIGN_CENTER | wxALL, 10);
    Bind(wxEVT_BUTTON, &LoginView::OnLogin, this, loginButton->GetId());

    wxButton* registerButton = new wxButton(panel, wxID_ANY, wxT("Register"));
    vbox->Add(registerButton, 0, wxALIGN_CENTER | wxALL, 10);
    Bind(wxEVT_BUTTON, &LoginView::OnRegister, this, registerButton->GetId());

    panel->SetSizer(vbox);
}

void LoginView::OnLogin(wxCommandEvent& event) {
}

void LoginView::OnRegister(wxCommandEvent& event) {
}
