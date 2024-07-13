//
// Created by Edoardo Nero on 13/07/24.
//

#include "gtest/gtest.h"
#include "../include/model/ReceivePanel.h"

class ReceivePanelTest : public ::testing::Test {
protected:
    ReceivePanel* receivePanel;

    void SetUp() override {
        receivePanel = new ReceivePanel();
    }

    void TearDown() override {
    }
};

TEST_F(ReceivePanelTest, GenerateTemporaryCode) {
    std::vector<std::string> code = ReceivePanel::generateCode(1);
    ASSERT_EQ(code[0].size(), 5);
    for (int i = 0; i < code[0].length(); i++) {
        ASSERT_TRUE(isdigit(code[0][i]));
    }
    //recupera il codice generato e verifica che sia presente nella tabella temporary_identifier
    std::vector<std::string> newCode = ReceivePanel::getCode(1);
    ASSERT_EQ(code[0], newCode[0]);
    //genera un nuovo codice di 5 cifre numeriche e verifica che sia diverso da quello precedente
    newCode = receivePanel->generateCode(1);
    ASSERT_NE(code[0], newCode[0]);
}