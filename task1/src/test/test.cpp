//
// Created by ns on 2019-03-11.
//

#include "test.h"
#include "gtest/gtest.h"

class Task1Test : public ::testing::Test {
private:
    double data1_;
public:
    // init data
    virtual void SetUp() {
        data1_ = 2.0;
    }
}

// テストフィクスチャを使うには、テストケース名とテストフィクスチャ名が一致していなければならない。
TEST_F(MyLibraryTest, Function1Test) {
    double result = Function1(data1_); // data1_にアクセスできる
    ...
}

TEST_F(MyLibraryTest, Class1Test) {
Class1 obj(data1_); // data1_にアクセスできる
...
}


