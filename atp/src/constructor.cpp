#include "branches.hpp"
#include <gtest/gtest.h>

// fixture for constructor tests
class ConstructorTest : public ::testing::Test {
    protected:
    void TearDown() override {
        delete newBranch;
    }

    Branch* newBranch = nullptr;
};

TEST_F(ConstructorTest, DefaultValuesSetCorrectly) {
    newBranch = new Branch();
    ASSERT_NE(newBranch, nullptr);
    EXPECT_EQ(newBranch->getDiam(), MIN_DIAM);
    EXPECT_EQ(newBranch->getLength(), MIN_LENGTH);
    EXPECT_EQ(newBranch->getParentPtr(), nullptr);
};

TEST_F(ConstructorTest, StartingValuesAsGiven) {
    double startingDiam = 4;
    double startingLength = 2;
    
    newBranch = new Branch(startingDiam, startingLength);
    ASSERT_NE(newBranch, nullptr);
    EXPECT_EQ(newBranch->getDiam(), startingDiam);
    EXPECT_EQ(newBranch->getLength(), startingLength);
    EXPECT_EQ(newBranch->getParentPtr(), nullptr);
};

TEST_F(ConstructorTest, InitialValuesLessThanMinSetToMin) {
    newBranch = new Branch(MIN_DIAM - 1, MIN_LENGTH - 1);
    ASSERT_NE(newBranch, nullptr);
    EXPECT_EQ(newBranch->getDiam(), MIN_DIAM);
    EXPECT_EQ(newBranch->getLength(), MIN_LENGTH);
    EXPECT_EQ(newBranch->getParentPtr(), nullptr);
};