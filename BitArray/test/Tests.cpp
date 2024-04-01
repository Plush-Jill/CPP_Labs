#include "gtest/gtest.h"
#include "../src/BitArray/BitArray.h"

TEST(BitArrayBool, BitArrayBool__Test){
    auto a {BitArray(0)};
    EXPECT_EQ(a.empty(), true);
    for (int i {}; i < 5; ++i){
        a.pushBack(true);
    }
    EXPECT_EQ(a.empty(), false);

    EXPECT_EQ(a.toString(), "11111");
    a <<= 2;
    BitArray b = BitArray(a); ///11100
    BitArray c = BitArray(a); ///11100
    EXPECT_EQ(a.toString(), "11100");
    a = a & (c << 2);
    EXPECT_EQ(a.toString(), "10000");
    c = a; ///10000
    a >>= 4;
    EXPECT_EQ(a.toString(), "00001");
    a |= c;
    EXPECT_EQ(a.toString(), "10001");
    a &= b;
    EXPECT_EQ(a.toString(), "10000");
    a ^= b;
    EXPECT_EQ(a.toString(), "01100");
    EXPECT_EQ(a.count(), 2);
    a = (a >> 1) & a;
    EXPECT_EQ(a.toString(), "00100");
    a.clear();
    EXPECT_EQ(a.toString(), "");
    EXPECT_EQ(a.getSize(), 0);
    a.resize(5);
    EXPECT_EQ(a.toString(), "00000");
    a.swap(c);
    EXPECT_EQ(a.toString(), "10000");
    EXPECT_EQ(a.any(), true);
    EXPECT_EQ(a.none(), false);
    a.reset(0);
    EXPECT_EQ(a.any(), false);
    EXPECT_EQ(a.none(), true);
    a.set();
    EXPECT_EQ(a.toString(), "11111");
    a.set(2, false);
    EXPECT_EQ(a.toString(), "11011");
    a.reset();
    EXPECT_EQ(a.toString(), "00000");
    a.set(2, true);
    EXPECT_EQ(a[2], true);
    a = ~a;
    EXPECT_EQ(a.toString(), "11011");
    EXPECT_EQ(c == a, false);
    EXPECT_EQ(c != a, true);
    a.reset();
    a.set(0, true);
    c.set(0, true);
    EXPECT_EQ(c == a, true);
    EXPECT_EQ(c != a, false);
    EXPECT_EQ((a ^ c).toString(), "00000");
    EXPECT_EQ((a | b).toString(), "11100");
}