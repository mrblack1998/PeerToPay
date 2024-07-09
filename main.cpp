//
// Created by Edoardo Nero on 03/07/24.
//
#include "wx/wx.h"
#include "include/view/LoginView.h"
#include "lib/DatabaseManager.h"
#include "include/model/Login.h"
#include "include/controller/LoginController.h"

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    auto* loginController = new LoginController(new LoginView("Peer to Pay - Login"),new Login());
    loginController->init();

    return true;
}