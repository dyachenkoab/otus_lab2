#include <gtest/gtest.h>
#include "processing.h"

TEST(SplitTest, BasicAssertions) {
    const string s("1.1.1.1");
    const vector<string> ok {"1", "1", "1", "1"};
    auto v = split(s, '.');
    EXPECT_EQ(v, ok);
}

TEST(ReadFileTest, BasicAssertions) {
    vector<vector<string>> res;
    read_file(res);
    EXPECT_NE(res.empty(), true);
}

TEST(ComparatorTest, BasicAssertions) {
    const vector<string> first {"1", "1", "1", "1"};
    const vector<string> second {"2", "2", "2", "2"};
    bool isSecond_first = comparator(second, first);
    EXPECT_NE(isSecond_first, true);
}
