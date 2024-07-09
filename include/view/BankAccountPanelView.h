//
// Created by Edoardo Nero on 09/07/24.
//

#ifndef PEERTOPAY_BANKACCOUNTPANELVIEW_H
#define PEERTOPAY_BANKACCOUNTPANELVIEW_H

#include "wx/wx.h"

class BankAccountPanelView {
public:
    BankAccountPanelView(wxPanel *panel);
    ~BankAccountPanelView();
    wxPanel* getPanel();

private:
    wxPanel* panel;
    wxTextCtrl* accountNumber;
    wxTextCtrl* expirationDate;
    wxTextCtrl* cvv;
    wxTextCtrl* balance;
    wxButton* saveButton;
};


#endif //PEERTOPAY_BANKACCOUNTPANELVIEW_H
