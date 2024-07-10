//
// Created by Edoardo Nero on 07/07/24.
//

#ifndef PEERTOPAY_USERVIEW_H
#define PEERTOPAY_USERVIEW_H

#include "wx/wx.h"
#include "HomePanelView.h"
#include <any>

class UserView: public wxFrame{
public:
    explicit UserView(const wxString& title);
    ~UserView() override;
    void init();
    void setPanelToUse(wxPanel* panel, const std::any& creatorObject);
    wxPanel* getPanel();
    std::any getCreatorObject();

private:
    wxMenuBar* menuBar;
    wxMenu* home;
    wxMenu* send;
    wxMenu* receive;
    wxMenu* account;
    wxMenu* logout;

    //Panel principale
    wxPanel* panel;
    std::any creatorObject;

};


#endif //PEERTOPAY_USERVIEW_H
