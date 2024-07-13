//
// Created by Edoardo Nero on 13/07/24.
//

#include "gtest/gtest.h"
#include "../include/model/BankAccountPanel.h"

class BankAccountPanelTest : public ::testing::Test {
protected:
    BankAccountPanel* bankAccountPanel;

    void SetUp() override {
        bankAccountPanel = new BankAccountPanel();
        // Initialize your test environment here, e.g., mock database connections
    }

    void TearDown() override {
        // Clean up your test environment here, e.g., clear mock data
    }
};

TEST_F(BankAccountPanelTest, SaveBankAccountValidData) {
    // Provo a salvare un account bancario con dati validi per l'utente con id 1
    int id = 1;
    std::string accountNumber = "123456789";
    std::string expirationDate = "12/25";
    std::string cvv = "123";
    std::string balance = "1000.00";

    bool result = bankAccountPanel->saveBankAccount(id, accountNumber, expirationDate, cvv, balance);
    ASSERT_TRUE(result);

}

TEST_F(BankAccountPanelTest, SaveBankAccountInvalidData) {
    // Provo a salvare un account bancario con dati non validi per l'utente con id 1
    int id = 1;
    std::string accountNumber = "abc";
    std::string expirationDate = "invalid_date";
    std::string cvv = "12"; // Invalid CVV
    std::string balance = "invalid_balance";

    ASSERT_THROW({ bankAccountPanel->saveBankAccount(id, accountNumber, expirationDate, cvv, balance);}, std::invalid_argument);
}