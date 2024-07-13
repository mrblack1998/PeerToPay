//
// Created by Edoardo Nero on 13/07/24.
//
#include "gtest/gtest.h"
#include "../include/model/SendPanel.h"

class SendPanelTest : public ::testing::Test {
protected:
    SendPanel* sendPanel;

    void SetUp() override {
        sendPanel = new SendPanel();
    }

    void TearDown() override {
        delete sendPanel;
    }
};

TEST_F(SendPanelTest, SendAmountGreaterThan1000) {
    bool result = true;
    try{
        result = sendPanel->sendMoney(1, "999999", "55555");
    }catch (std::exception& e){
        result = false;
    }
    ASSERT_FALSE(result);
}

TEST_F(SendPanelTest, SendNonNumericAmount) {
    bool result = true;
    try{
        result = sendPanel->sendMoney(1, "Amount", "55555");
    }catch (std::exception& e){
        result = false;
    }
    ASSERT_FALSE(result);
}

TEST_F(SendPanelTest, SendToInvalideCode) {
    bool result = true;
    try{
        result = sendPanel->sendMoney(1, "100", "qwert");
    }catch (std::exception& e){
        result = false;
    }
    ASSERT_FALSE(result);

}