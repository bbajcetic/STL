#include "vector/vector.h"

#include <gtest/gtest.h>
//#include <glog/logging.h>

class VectorTests : public ::testing::Test {
protected:
    int vectorSize;

    void SetUp() override {
        vectorSize = 1;
    }
    //void TearDown() override {}
};

// Test the constructor
TEST_F(VectorTests, Constructor) {
    vector<int> v;
    //ASSERT_NE(v, nullptr);
    EXPECT_EQ(v.size(), 0);
}

// Test some basic uses of vector
TEST_F(VectorTests, BasicUse1) {
    vector<int> v;
    v.push_back(7);
    v.push_back(4);
    v.push_back(1);
    v.pop_back();
    EXPECT_EQ(v.size(), 2);
    v.clear();
    EXPECT_EQ(v.size(), 0);
}
TEST_F(VectorTests, BasicUse2) {
    vector<int> v;
    // add 5 elements
    v.push_back(7);
    v.push_back(46);
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);

    //EXPECT_EQ(v[3], 3);
    //EXPECT_EQ(v[1], 46);
    //EXPECT_EQ(v[0], 7);
    EXPECT_EQ(v.size(), 5);
}

int main(int argc, char **argv) {
    //::google::InitGoogleLogging(argv[0]);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
