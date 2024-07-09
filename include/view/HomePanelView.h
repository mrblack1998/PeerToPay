//
// Created by Edoardo Nero on 08/07/24.
//

#ifndef PEERTOPAY_HOMEPANELVIEW_H
#define PEERTOPAY_HOMEPANELVIEW_H

#include "wx/wx.h"

class HomePanelView {
public:
    explicit HomePanelView(wxPanel* panel);
    ~HomePanelView();
    wxPanel* getPanel();

private:
    wxPanel* panel;
    wxStaticText* balance;
    wxListBox* transactions;
    wxButton* exportButton;

};


#endif //PEERTOPAY_HOMEPANELVIEW_H
