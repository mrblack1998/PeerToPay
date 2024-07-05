//
// Created by Edoardo Nero on 03/07/24.
//

#ifndef PEERTOPAY_LOGINVIEW_H
#define PEERTOPAY_LOGINVIEW_H

#include <wx/wx.h>
class LoginView: public wxFrame{
    public:
        explicit LoginView(const wxString& title);
        wxTextCtrl* getEmailField();
        wxTextCtrl* getPasswordField();
        wxCheckBox* getRememberMe();
        wxButton* getLoginButton();
        wxButton* getRegisterButton();

    private:
        void OnLogin(wxCommandEvent& event);

        wxTextCtrl* emailField;
        wxTextCtrl* passwordField;
        wxCheckBox* rememberMe;
        wxButton* loginButton;
        wxButton* registerButton;
};


#endif //PEERTOPAY_LOGINVIEW_H
