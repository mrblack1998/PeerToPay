//
// Created by Edoardo Nero on 13/07/24.
//
#include "gtest/gtest.h"
#include "../include/model/Register.h"

class RegisterTest : public ::testing::Test {
protected:
    Register* reg;

    void SetUp() override {
        reg = new Register();
    }

    void TearDown() override {
    }
};

TEST_F(RegisterTest, RegisterWithUsedEmail) {
    std::string email = "edoardo@gmail.com";
    std::string password = "password123";
    bool result = reg->TryRegister("Edoardo", "Nero", email, password);
    ASSERT_FALSE(result);
}