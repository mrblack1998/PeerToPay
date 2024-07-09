//
// Created by Edoardo Nero on 09/07/24.
//

#ifndef PEERTOPAY_RECEIVEPANELVIEW_H
#define PEERTOPAY_RECEIVEPANELVIEW_H

#include "wx/wx.h"

class ReceivePanelView {
public:
    ReceivePanelView(wxPanel *panel);
    ~ReceivePanelView();
    wxPanel* getPanel();

private:
    wxPanel* panel;
    wxStaticText* code;
    wxStaticText* expirationDate;
    wxButton* generateButton;

};


#endif //PEERTOPAY_RECEIVEPANELVIEW_H
