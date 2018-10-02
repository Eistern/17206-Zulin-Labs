#include <gtest/gtest.h>
#include "tritSet/tritSet.h"

TEST(single_Trit, logic_AND) {
    EXPECT_EQ(Trit::FALSE & Trit::UNKNOWN, Trit::FALSE);
    EXPECT_EQ(Trit::FALSE & Trit::FALSE, Trit::FALSE);
    EXPECT_EQ(Trit::FALSE & Trit::TRUE, Trit::FALSE);

    EXPECT_EQ(Trit::UNKNOWN & Trit::UNKNOWN, Trit::UNKNOWN);
    EXPECT_EQ(Trit::UNKNOWN & Trit::TRUE, Trit::UNKNOWN);

    EXPECT_EQ(Trit::TRUE & Trit::TRUE, Trit::TRUE);
}

TEST(single_Trit, logic_OR) {
    EXPECT_EQ(Trit::TRUE | Trit::UNKNOWN, Trit::TRUE);
    EXPECT_EQ(Trit::TRUE | Trit::FALSE, Trit::TRUE);
    EXPECT_EQ(Trit::TRUE | Trit::TRUE, Trit::TRUE);

    EXPECT_EQ(Trit::UNKNOWN | Trit::UNKNOWN, Trit::UNKNOWN);
    EXPECT_EQ(Trit::UNKNOWN | Trit::FALSE, Trit::UNKNOWN);

    EXPECT_EQ(Trit::FALSE | Trit::FALSE, Trit::FALSE);
}

TEST(single_Trit, logic_NOT) {
    EXPECT_EQ(~Trit::FALSE, Trit::TRUE);
    EXPECT_EQ(~Trit::UNKNOWN, Trit::UNKNOWN);
    EXPECT_EQ(~Trit::TRUE, Trit::FALSE);
}

TEST(tritSet_basic, construct) {
    tritSet _new(1000);
    size_t allocatedLength = _new.capacity();
    EXPECT_TRUE(allocatedLength >= 1000*2 / 8 / sizeof(unsigned int));
}

TEST(tritSet_basic, access_and_input) {
    tritSet _test(100);

    _test[10] = Trit::TRUE;
    EXPECT_EQ(_test[10], Trit::TRUE);

    _test[10] = Trit::FALSE;
    EXPECT_EQ(_test[10], Trit::FALSE);

    _test[11] = Trit::TRUE;
    EXPECT_EQ(_test[11], Trit::TRUE);
    EXPECT_EQ(_test[10], Trit::FALSE);
}

TEST(tritSet_basic, length) {
    tritSet _test(100);
    EXPECT_EQ(_test.length(), 1);

    _test[0] = Trit::TRUE;
    EXPECT_EQ(_test.length(), 1);
    _test[1] = Trit::FALSE;
    EXPECT_EQ(_test.length(), 2);
    _test[20] = Trit::TRUE;
    EXPECT_EQ(_test.length(), 21);
    _test[20] = Trit::UNKNOWN;
    EXPECT_EQ(_test.length(), 2);
}

TEST(tritSet_basic, cardinality) {
    tritSet _test(10);
    EXPECT_EQ(_test.cardinality(Trit::UNKNOWN), 1);

    _test[0] = Trit::TRUE;
    EXPECT_EQ(_test.cardinality(Trit::UNKNOWN), 0);
    EXPECT_EQ(_test.cardinality(Trit::TRUE), 1);

    _test[2] = Trit::TRUE;
    EXPECT_EQ(_test.cardinality(Trit::UNKNOWN), 1);
    EXPECT_EQ(_test.cardinality(Trit::TRUE), 2);

    std::unordered_map<Trit, int, std::hash<Trit>> _testMap = _test.cardinality();
    EXPECT_EQ(_testMap[Trit::UNKNOWN], 1);
    EXPECT_EQ(_testMap[Trit::TRUE], 2);
    EXPECT_EQ(_testMap[Trit::FALSE], 0);
}

TEST(tritSet_basic, trim) {
    tritSet _test(10);
    for (int i = 4; i < 10; ++i)
        _test[i] = Trit::TRUE;

    _test.trim(5);
    for (int i = 5; i < 10; ++i)
        EXPECT_EQ(_test[i], Trit::UNKNOWN);
}

TEST(tritSet_logic, logic_AND) {
    tritSet _test1(10), _test2(20);
    _test1[0] = Trit::FALSE;
    _test2[2] = Trit::TRUE;

    tritSet _test3 = _test1 & _test2;
    EXPECT_EQ(_test3.capacity(), _test2.capacity());
    EXPECT_EQ(_test3[0], Trit::FALSE);
    EXPECT_EQ(_test3[1], Trit::UNKNOWN);
    EXPECT_EQ(_test3[2], Trit::UNKNOWN);
}

TEST(tritSet_logic, logic_OR) {
    tritSet _test1(10), _test2(20);
    _test1[0] = Trit::FALSE;
    _test2[2] = Trit::TRUE;

    tritSet _test3 = _test1 | _test2;
    EXPECT_EQ(_test3.capacity(), _test2.capacity());
    EXPECT_EQ(_test3[0], Trit::UNKNOWN);
    EXPECT_EQ(_test3[1], Trit::UNKNOWN);
    EXPECT_EQ(_test3[2], Trit::TRUE);
}

TEST(tritSet_logic, logic_NOT) {
    tritSet _test1(10);
    _test1[0] = Trit::FALSE;
    _test1[2] = Trit::TRUE;

    tritSet _test2 = ~_test1;
    EXPECT_EQ(_test1.capacity(), _test2.capacity());
    EXPECT_EQ(_test2[0], Trit::TRUE);
    EXPECT_EQ(_test2[1], Trit::UNKNOWN);
    EXPECT_EQ(_test2[2], Trit::FALSE);
}

TEST(tritSet_memory, resize_input) {
    tritSet _test(10);
    int startCapacity = _test.capacity();

    _test[5] = Trit::FALSE;
    EXPECT_TRUE(_test.capacity() == startCapacity);
    _test[20] = Trit::UNKNOWN;
    EXPECT_TRUE(_test.capacity() == startCapacity);
    _test[30] = Trit::TRUE;
    EXPECT_TRUE(_test.capacity() > startCapacity);
    EXPECT_EQ(_test[30], Trit::TRUE);
}

TEST(tritSet_memory, out_of_range_access) {
    tritSet _test(10);
    int startCapacity = _test.capacity();

    EXPECT_FALSE(_test[20] == Trit::FALSE);
    EXPECT_EQ(_test.capacity(), startCapacity);
}

TEST (tritSet_memory, shrink) {
    tritSet _test(10);
    int startCapacity = _test.capacity();

    _test[50] = Trit::TRUE;
    int newCapacity = _test.capacity();
    _test[100] = Trit::TRUE;
    EXPECT_TRUE(_test.capacity() > newCapacity);

    _test[100] = Trit::UNKNOWN;
    _test.shrink();
    EXPECT_EQ(_test.capacity(), newCapacity);

    _test[50] = Trit::UNKNOWN;
    _test.shrink();
    EXPECT_EQ(_test.capacity(), startCapacity);
}

