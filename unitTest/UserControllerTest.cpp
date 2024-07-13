//
// Created by Edoardo Nero on 13/07/24.
//
#include <gtest/gtest.h>
#include "include/controller/UserController.h"
#include "include/model/User.h"
#include "include/view/UserView.h"

class UserControllerTest : public ::testing::Test {
protected:
    UserController* userController;
    UserView* userView;
    User* userModel;

    void SetUp() override {
        userView = new UserView("Test");
        userModel = new User("edoardo@gmail.com", "123456");
        userController = new UserController(userView, userModel);
        userController->init();
        // Perform any common setup, like initializing a database connection if necessary
    }

    void TearDown() override {
        // Clean up resources, like closing database connections
    }

    std::string demangle(const char* name) {
        int status = -1;
        std::unique_ptr<char, void(*)(void*)> res {
                abi::__cxa_demangle(name, NULL, NULL, &status),
                std::free
        };
        return (status == 0) ? res.get() : name;
    }

};

//Test lo switch tra i pannelli
TEST_F(UserControllerTest, TestSwitchPanel) {
    //Testo l'evento: clicca sul menu Home
    wxCommandEvent event(wxEVT_MENU, 100);
    userController->switchPanelTest(event);
    std::string panelType = demangle(typeid(std::any_cast<HomePanelView*>(userView->getCreatorObject())).name());
    ASSERT_EQ(panelType, "HomePanelView*");

    //Testo l'evento: clicca sul menu Send
    wxCommandEvent event2(wxEVT_MENU, 101);
    userController->switchPanelTest(event2);
    std::string panelType2 = demangle(typeid(std::any_cast<SendPanelView*>(userView->getCreatorObject())).name());
    ASSERT_EQ(panelType2, "SendPanelView*");

    //Testo l'evento: clicca sul menu Receive
    wxCommandEvent event3(wxEVT_MENU, 102);
    userController->switchPanelTest(event3);
    std::string panelType3 = demangle(typeid(std::any_cast<ReceivePanelView*>(userView->getCreatorObject())).name());
    ASSERT_EQ(panelType3, "ReceivePanelView*");

    //Testo l'evento: clicca sul menu Account
    wxCommandEvent event4(wxEVT_MENU, 103);
    userController->switchPanelTest(event4);
    std::string panelType4 = demangle(typeid(std::any_cast<BankAccountPanelView*>(userView->getCreatorObject())).name());
    ASSERT_EQ(panelType4, "BankAccountPanelView*");

    //Testo l'evento: clicca sul menu Logout
    wxCommandEvent event5(wxEVT_MENU, 104);
    userController->switchPanelTest(event5);
    std::string panelType5 = demangle(typeid(std::any_cast<HomePanelView*>(userView->getCreatorObject())).name());
    ASSERT_EQ(panelType5, "HomePanelView*");
}