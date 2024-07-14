//
// Created by Edoardo Nero on 14/07/24.
//

#include <gtest/gtest.h>
#include "Utilities.h"

// Test suite per la classe Utilities
class UtilitiesTest : public ::testing::Test {
protected:
    Utilities* utilities{};
    void SetUp() override {
        utilities = new Utilities();
    }

    void TearDown() override {
    }
};

TEST_F(UtilitiesTest, IsAllDigits) {
    EXPECT_TRUE(utilities->isAllDigits("1234567890"));
    EXPECT_FALSE(utilities->isAllDigits("1234567890a"));
    EXPECT_FALSE(utilities->isAllDigits("1234567890."));
    EXPECT_FALSE(utilities->isAllDigits("aaaa"));
    EXPECT_FALSE(utilities->isAllDigits(" "));
    EXPECT_TRUE(utilities->isAllDigits(""));
    EXPECT_FALSE(utilities->isAllDigits("123,456"));
    EXPECT_FALSE(utilities->isAllDigits("123.456"));
}

TEST_F(UtilitiesTest, IsValidExpirationDate) {
    EXPECT_TRUE(utilities->isValidExpirationDate("12/21"));
    EXPECT_FALSE(utilities->isValidExpirationDate("12/2021"));
    EXPECT_FALSE(utilities->isValidExpirationDate("12/2"));
    EXPECT_FALSE(utilities->isValidExpirationDate("12/2a"));
    EXPECT_FALSE(utilities->isValidExpirationDate("12/2."));
    EXPECT_FALSE(utilities->isValidExpirationDate("12/aa"));
    EXPECT_FALSE(utilities->isValidExpirationDate("aa/12"));
    EXPECT_FALSE(utilities->isValidExpirationDate("aa/aa"));
    EXPECT_FALSE(utilities->isValidExpirationDate("/"));
    EXPECT_FALSE(utilities->isValidExpirationDate("2020/22"));
}

TEST_F(UtilitiesTest, CheckBalance) {
    EXPECT_EQ(utilities->checkBalance("1234567890"), "1234567890.00");
    EXPECT_EQ(utilities->checkBalance("1234567890."), "1234567890.00");
    EXPECT_EQ(utilities->checkBalance("1234567890.0"), "1234567890.00");
    EXPECT_EQ(utilities->checkBalance("1234567890.00"), "1234567890.00");
    EXPECT_EQ(utilities->checkBalance("1234567890.000"), "1234567890.00");
    EXPECT_EQ(utilities->checkBalance("1234567890.0000"), "1234567890.00");
    EXPECT_EQ(utilities->checkBalance("1234567890.0001"), "1234567890.00");
    EXPECT_EQ(utilities->checkBalance("1234567890.001"), "1234567890.00");
    EXPECT_EQ(utilities->checkBalance("1234567890.01"), "1234567890.01");
    EXPECT_EQ(utilities->checkBalance("1234567890.1"), "1234567890.10");
    EXPECT_EQ(utilities->checkBalance("1234567890.10"), "1234567890.10");
    EXPECT_EQ(utilities->checkBalance("1234567890.100"), "1234567890.10");
    EXPECT_EQ(utilities->checkBalance("1234567890.1000"), "1234567890.10");
    EXPECT_EQ(utilities->checkBalance("1234567890.1001"), "1234567890.10");
    EXPECT_EQ(utilities->checkBalance("1234567890.101"), "1234567890.10");
    EXPECT_EQ(utilities->checkBalance("1234567890.11"), "1234567890.11");
    EXPECT_EQ(utilities->checkBalance("1234567890.110"), "1234567890.11");
    EXPECT_EQ(utilities->checkBalance("1234567890.1100"), "1234567890.11");
    EXPECT_EQ(utilities->checkBalance("1234567890.1101"), "1234567890.11");
    EXPECT_EQ(utilities->checkBalance("1234567890.111"), "1234567890.11");
}