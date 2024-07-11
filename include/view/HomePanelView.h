//
// Created by Edoardo Nero on 08/07/24.
//

#ifndef PEERTOPAY_HOMEPANELVIEW_H
#define PEERTOPAY_HOMEPANELVIEW_H

#include "wx/wx.h"
#include "wx/grid.h"
#include "Transazione.h"

class HomePanelView {
public:
    explicit HomePanelView(wxPanel* panel, const std::string & ab, const std::vector<Transazione> & transactions);
    ~HomePanelView();
    wxPanel* getPanel();

private:
    wxPanel* panel;
    wxStaticText* balance;
    wxGrid* transactions;
    wxButton* exportButton;

};


#endif //PEERTOPAY_HOMEPANELVIEW_H
