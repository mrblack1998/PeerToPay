//
// Created by Edoardo Nero on 03/07/24.
//

#ifndef PEERTOPAY_REGISTERVIEW_H
#define PEERTOPAY_REGISTERVIEW_H

#include "wx/wx.h"

class RegisterView: public wxFrame {
public:
    explicit RegisterView(const wxString& title);
    wxButton* getLoginButton();
    wxButton* getRegisterButton();
    wxTextCtrl* getFirstNameField();
    wxTextCtrl* getLastNameField();
    wxTextCtrl* getEmailField();
    wxTextCtrl* getPasswordField();

private:
   // void OnRegister(wxCommandEvent& event);

    wxTextCtrl* nameField;
    wxTextCtrl* surnameField;
    wxTextCtrl* emailField;
    wxTextCtrl* passwordField;
    wxButton* loginButton;
    wxButton* registerButton;
};


#endif //PEERTOPAY_REGISTERVIEW_H
