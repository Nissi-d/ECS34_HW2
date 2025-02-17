#include <gtest/gtest.h>
#include "StringUtils.h"

TEST(StringUtilsTest, SliceTest){
    EXPECT_EQ(StringUtils::Slice("hello", 1, 4), "ell");
    EXPECT_EQ(StringUtils::Slice("hello", -3, -1), "ll");
    EXPECT_EQ(StringUtils::Slice("hello", 2, 0), "llo");
    EXPECT_EQ(StringUtils::Slice("hello", -5, 0), "hello");
    EXPECT_EQ(StringUtils::Slice("hello", 3, 2), "");  // Invalid range
}

TEST(StringUtilsTest, Capitalize){
    EXPECT_EQ(StringUtils::Capitalize("hello"), "Hello");
}

TEST(StringUtilsTest, Upper){
    EXPECT_EQ(StringUtils::Upper("hello"), "HELLO");
}

TEST(StringUtilsTest, Lower){
    EXPECT_EQ(StringUtils::Lower("HELLO"), "hello");

}

TEST(StringUtilsTest, LStrip){
    EXPECT_EQ(StringUtils::LStrip("    Hello World"), "Hello World");
    
}

TEST(StringUtilsTest, RStrip){
    EXPECT_EQ(StringUtils::RStrip(" Hello World    "), " Hello World");
    
}

TEST(StringUtilsTest, Strip){
    EXPECT_EQ(StringUtils::Strip("  Hello World    "), "Hello World");
    
}

TEST(StringUtilsTest, Center){
    EXPECT_EQ(StringUtils::Center("Hello", 10), "  Hello   ");
    EXPECT_EQ(StringUtils::Center("Hello", 11), "   Hello   ");
}

TEST(StringUtilsTest, LJust){
    EXPECT_EQ(StringUtils::LJust("  Hello World    ", 20), "  Hello World       ");
}

TEST(StringUtilsTest, RJust){
    EXPECT_EQ(StringUtils::RJust("  Hello World    ", 20), "     Hello World    ");
}

TEST(StringUtilsTest, Replace){
    EXPECT_EQ(StringUtils::Replace("hello world", "world", "there"), "hello there");
    EXPECT_EQ(StringUtils::Replace("aaa", "a", "b"), "bbb");
    
}

TEST(StringUtilsTest, Split){
    EXPECT_EQ(StringUtils::Split("hello world"), (std::vector<std::string>{"hello", "world"}));
    EXPECT_EQ(StringUtils::Split("  split  on   spaces  "), (std::vector<std::string>{"split", "on", "spaces"}));
    
}

TEST(StringUtilsTest, Join){
    EXPECT_EQ(StringUtils::Join(", ", {"apple", "banana", "cherry"}), "apple, banana, cherry");
    EXPECT_EQ(StringUtils::Join("-", {"a", "b", "c"}), "a-b-c");
}

TEST(StringUtilsTest, ExpandTabs){
    EXPECT_EQ(StringUtils::ExpandTabs("Hello\tWorld", 4), "Hello   World");
    EXPECT_EQ(StringUtils::ExpandTabs("A\tB\tC", 4), "A   B   C");
}

TEST(StringUtilsTest, EditDistance){
    EXPECT_EQ(StringUtils::EditDistance("kitten", "sitting"), 3); // k→s, e→i, +g
    EXPECT_EQ(StringUtils::EditDistance("flaw", "lawn"), 2);  // f→l, w→n
}
