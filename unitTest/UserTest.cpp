//
// Created by Edoardo Nero on 13/07/24.
//
#include "gtest/gtest.h"
#include "../include/model/User.h"

class UserTest : public ::testing::Test {
protected:
    User* user;

    void SetUp() override {
        // Assuming User constructor takes email and password, and you have setters for name and surname or a method to directly set them for testing
        user = new User("edoardo@gmail.com", "123456");
        user->init();
    }

    void TearDown() override {
    }
};

TEST_F(UserTest, NameIsCorrect) {
    ASSERT_EQ(user->getName(), "Edoardo");
}

TEST_F(UserTest, SurnameIsCorrect) {
    ASSERT_EQ(user->getSurname(), "Nero");
}

TEST_F(UserTest, EmailIsCorrect) {
    ASSERT_EQ(user->getEmail(), "edoardo@gmail.com");
}

TEST_F(UserTest, IdIsCorrect) {
    ASSERT_EQ(user->getId(), 4);
}