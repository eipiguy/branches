#include "branches.hpp"
#include <gtest/gtest.h>

// fixture for constructor tests
class ChildTest : public ::testing::Test {
    protected:
    void SetUp() override {
        parentBranch = new Branch();
        parentBranch->appendChild();
    }
    void TearDown() override {
        delete parentBranch;
        delete newChild;
    }

    Branch* parentBranch = nullptr;
    Branch* newChild = nullptr;
};

TEST_F(ChildTest, ChildIsCreatedWithDefaultValues) {
    newChild = parentBranch->getLastChild();

    ASSERT_NE(parentBranch, nullptr);
    ASSERT_NE(newChild, nullptr);
    EXPECT_EQ(newChild->getDiam(), MIN_DIAM);
    EXPECT_EQ(newChild->getLength(), MIN_LENGTH);
    EXPECT_EQ(newChild->getParentPtr(), parentBranch);
    EXPECT_EQ(newChild->getDistFromParent(), 0);
    EXPECT_EQ(newChild->getAngleFromParent(), 0);
};

TEST_F(ChildTest, GetIndexAboveRangeGivesNull) {
    newChild = (*parentBranch)[1];

    ASSERT_NE(parentBranch, nullptr);
    EXPECT_EQ(newChild, nullptr);
};

TEST_F(ChildTest, GetNegativeIndexGivesNull) {
    newChild = (*parentBranch)[-1];

    ASSERT_NE(parentBranch, nullptr);
    EXPECT_EQ(newChild, nullptr);
};