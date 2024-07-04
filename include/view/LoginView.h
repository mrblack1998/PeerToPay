//
// Created by Edoardo Nero on 03/07/24.
//

#ifndef PEERTOPAY_LOGINVIEW_H
#define PEERTOPAY_LOGINVIEW_H

#include <wx/wx.h>
class LoginView: public wxFrame{
    public:
        LoginView(const wxString& title);

    private:
        void OnLogin(wxCommandEvent& event);
        void OnRegister(wxCommandEvent& event);

        wxTextCtrl* emailField;
        wxTextCtrl* passwordField;
};


#endif //PEERTOPAY_LOGINVIEW_H
