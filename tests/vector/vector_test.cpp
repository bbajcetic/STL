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

// Test pushing and popping of array
TEST_F(VectorTests, PUSH_POP) {
    vector<int> v;
    v.push_back(5);
    v.push_back(3);
    v.push_back(9);
    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v[2], 9);
    EXPECT_EQ(v[0], 5);
    EXPECT_EQ(v[1], 3);

    v.pop_back();
    v.pop_back();
    EXPECT_EQ(v.size(), 1);
    EXPECT_EQ(v[0], 5);
    
    v.push_back(10);
    EXPECT_EQ(v[1], 10);
}

// Test size method of vector (after init, adding, popping, clearing)
TEST_F(VectorTests, SIZE) {
    vector<int> v;
    EXPECT_EQ(v.size(), 0);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    EXPECT_EQ(v.size(), 3);
    v.pop_back();
    EXPECT_EQ(v.size(), 2);
    v.push_back(10);
    EXPECT_EQ(v.size(), 3);
    v.clear();
    EXPECT_EQ(v.size(), 0);
}

// Test empty() (after init, adding and popping, clearing)
TEST_F(VectorTests, EMPTY) {
    vector<int> v;
    EXPECT_EQ(v.empty(), true);
    v.push_back(2);
    EXPECT_EQ(v.empty(), false);
    v.push_back(2);
    v.push_back(3);
    v.pop_back();
    EXPECT_EQ(v.empty(), false);
    v.pop_back();
    EXPECT_EQ(v.empty(), false);
    v.pop_back();
    EXPECT_EQ(v.empty(), true);
    v.push_back(3);
    v.push_back(13);
    v.push_back(23);
    EXPECT_EQ(v.empty(), false);
    v.clear();
    EXPECT_EQ(v.empty(), true);
}

// Test clearing of a vector (after init, after adding elements, test clear then add then clear)
TEST_F(VectorTests, CLEAR) {
    vector<int> v;
    EXPECT_EQ(v.size(), 0);
    v.clear();
    v.push_back(3);
    EXPECT_EQ(v.size(), 1);
    v.clear();
    EXPECT_EQ(v.size(), 0);
    v.push_back(2);
    v.clear();
    EXPECT_EQ(v.size(), 0);
}

// Test array capacity (after init, after pushing enough to make it double)
TEST_F(VectorTests, CAPACITY) {
    vector<int> v;
    EXPECT_EQ(v.size(), 0);
    EXPECT_EQ(v.capacity(), vectorBase::DEFAULT_CAPACITY);

    // min(100, capacity) to prevent infinite loop in case capacity is initialized to something crazy
    for (int i = 0; i < vectorBase::DEFAULT_CAPACITY; i++) {
        v.push_back(v.size());
    }
    EXPECT_EQ(v.size(), v.capacity());
    EXPECT_EQ(v.capacity(), vectorBase::DEFAULT_CAPACITY);
    v.push_back(v.size());
    EXPECT_EQ(v.capacity(), vectorBase::DEFAULT_CAPACITY * 2);
}

// Test accessing element and changing it
TEST_F(VectorTests, ACCESS) {
    vector<int> v;
    for (int i = 0; i < 50; i++) {
        v.push_back(i);
    }
    EXPECT_EQ(v.size(), 50);
    for (int i = 0; i < 50; i += 10) {
        v[i] = i * 2;
    }
    for (int i = 0; i < 50; i++) {
        if (i % 10 == 0) {
            EXPECT_EQ(v[i], i * 2);
        }
        else {
            EXPECT_EQ(v[i], i);
        }
    }
}




int main(int argc, char **argv) {
    //::google::InitGoogleLogging(argv[0]);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
