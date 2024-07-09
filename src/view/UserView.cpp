//
// Created by Edoardo Nero on 07/07/24.
//

#include "include/view/UserView.h"

enum MenuIDs {
    ID_HOME = 100,
    ID_SEND = 101,
    ID_RECEIVE = 102,
    ID_ACCOUNT = 103,
    ID_LOGOUT = 104
};

UserView::UserView(const wxString& title): wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600)){
    //Menu bar con i seguenti elementi: Home, Invia, Ricevi, Conto e Logout
    menuBar = new wxMenuBar();
    home = new wxMenu();
    home->Append(ID_HOME, wxT("Home"));
    send = new wxMenu();
    send->Append(ID_SEND, wxT("Invia"));
    receive = new wxMenu();
    receive->Append(ID_RECEIVE, wxT("Ricevi"));
    account = new wxMenu();
    account->Append(ID_ACCOUNT, wxT("Conto"));
    logout = new wxMenu();
    logout->Append(ID_LOGOUT, wxT("Logout"));
    panel = nullptr;
    init();
}

UserView::~UserView() {
    delete menuBar;
    delete home;
    delete send;
    delete receive;
    delete account;
    delete logout;
    delete panel;
}

void UserView::init() {
    menuBar->Append(home, wxT("Home"));
    menuBar->Append(send, wxT("Invia"));
    menuBar->Append(receive, wxT("Ricevi"));
    menuBar->Append(account, wxT("Conto"));
    menuBar->Append(logout, wxT("Logout"));
    SetMenuBar(menuBar);
    Centre();
    setPanelToUse((new HomePanelView(new wxPanel(this, wxID_ANY)))->getPanel());
}

void UserView::setPanelToUse(wxPanel* panelToUse) {
    if (panel != nullptr) {
        panel->Show(false);
        panel->Destroy();
    }
    panel = panelToUse;
    panel->Show(true);
    panel->Layout();
}