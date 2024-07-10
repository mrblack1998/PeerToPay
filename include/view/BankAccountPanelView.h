//
// Created by Edoardo Nero on 09/07/24.
//

#ifndef PEERTOPAY_BANKACCOUNTPANELVIEW_H
#define PEERTOPAY_BANKACCOUNTPANELVIEW_H

#include "wx/wx.h"

class BankAccountPanelView {
public:
    explicit BankAccountPanelView(wxPanel *panel, const std::vector<std::string>& parametri);
    ~BankAccountPanelView();
    wxPanel* getPanel();
    std::string getAccountNumber();
    std::string getExpirationDate();
    std::string getCvv();
    std::string getBalance();

private:
    wxPanel* panel;
    wxTextCtrl* accountNumber;
    wxTextCtrl* expirationDate;
    wxTextCtrl* cvv;
    wxTextCtrl* balance;
    wxButton* saveButton;
};


#endif //PEERTOPAY_BANKACCOUNTPANELVIEW_H
