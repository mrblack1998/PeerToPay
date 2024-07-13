//
// Created by Edoardo Nero on 13/07/24.
//

#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include "../include/model/Login.h"

class LoginTest : public ::testing::Test {
protected:
    void SetUp() override {
        std::remove("credenziali.txt");
    }

    void TearDown() override {
        std::remove("credenziali.txt");
    }

    bool checkFileContent(const std::string& expectedContent) {
        std::ifstream file("credenziali.txt");
        std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        return content == expectedContent;
    }
};

TEST_F(LoginTest, TestSaveCredentials) {
    Login login;
    std::string email = "test@example.com";
    std::string password = "password";
    bool rememberMe = true;

    login.storeCredenziali(email, password, rememberMe);

    std::string expectedContent = "1\ntest@example.com\npassword";
    ASSERT_TRUE(checkFileContent(expectedContent));
}

TEST_F(LoginTest, TestTryLogin) {
    Login login;
    std::string email = "incorrect@email.com";
    std::string password = "incorrectPassword";
    bool rememberMe = true;

    ASSERT_FALSE(login.tryLogin(email, password, rememberMe));

    email = "edoardo@gmail.com";
    password = "123456";
    ASSERT_TRUE(login.tryLogin(email, password, rememberMe));
}