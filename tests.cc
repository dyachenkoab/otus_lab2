#include <gtest/gtest.h>
#include "processing.h"

TEST(SplitTest, BasicAssertions) {
    const string s("1.1.1.1");
    const vector<int> ok {1, 1, 1, 1};
    auto v = split(s, '.');
    EXPECT_EQ(v, ok);
}

TEST(ReadFileTest, BasicAssertions) {
    vector<vector<int>> res;
    read_file(res);
    EXPECT_NE(res.empty(), true);
}

TEST(ComparatorTest, BasicAssertions) {
    const vector<int> first {1, 1, 1, 1};
    const vector<int> second {1, 1, 1, 2};
    bool isSecond_first = comparator(second, first);
    EXPECT_EQ(isSecond_first, true);
}
