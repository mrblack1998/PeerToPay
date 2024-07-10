//
// Created by Edoardo Nero on 09/07/24.
//

#ifndef PEERTOPAY_RECEIVEPANELVIEW_H
#define PEERTOPAY_RECEIVEPANELVIEW_H

#include "wx/wx.h"

class ReceivePanelView {
public:
    ReceivePanelView(wxPanel *panel, const std::vector<std::string>& parametri);
    ~ReceivePanelView();
    wxPanel* getPanel();
    void setCode(const std::string& code);
    void setExpirationDate(const std::string& expirationDate);

private:
    wxPanel* panel;
    wxStaticText* code;
    wxStaticText* expirationDate;
    wxButton* generateButton;

};


#endif //PEERTOPAY_RECEIVEPANELVIEW_H
