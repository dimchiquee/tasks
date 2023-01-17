#include "Functions/Functions.h"
#include "gtest/gtest.h"
TEST(ReadLineTest, ReadLine)
{
    EXPECT_EQ(encodeToBase64("A"),"QQ==");
    EXPECT_EQ(decodeFromBase64("cmFuZG9t"),"A");
    EXPECT_EQ(decodeFromBase64("cGl2a28="),"pivko")
    EXPECT_EQ(encodeToBase64("testing"),"dGVzdGluZw==");
    EXPECT_EQ(encodeToBase64(""),"");
    EXPECT_EQ(decodeFromBase64(""),"")
}
