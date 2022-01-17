#include "branches.hpp"
#include <gtest/gtest.h>

// fixture for constructor tests
class ConstructorTest : public ::testing::Test {
    protected:
    void TearDown() override {
        delete newNode;
    }

    Node* newNode = nullptr;
};

TEST_F(ConstructorTest, DefaultValuesSetCorrectly) {
    newNode = new Node();
    ASSERT_NE(newNode, nullptr);
    EXPECT_EQ(newNode->getParentPtr(), nullptr);
    EXPECT_EQ(newNode->getDistanceAlongParent(), 0);
    EXPECT_EQ(newNode->getAngleFromParentPlane(), 0);
};