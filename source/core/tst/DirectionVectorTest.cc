#include <gtest.h>
#include <DirectionVector.h>

TEST(DirectionVectorTest, SinglePointHasZeroedDirection)
{
    DirectionVector dir(NDPoint({1,1}), NDPoint({1,1}));
    for(int i = 0; i < dir.size(); ++i)
    {
        EXPECT_EQ(0, dir[i]);
    }
}

TEST(DirectionVectorTest, HasCorrectSize)
{
    DirectionVector dir(NDPoint({1,2,3}), NDPoint({4,5,6}));
    EXPECT_EQ(3, dir.size());
}

TEST(DirectionVectorTest, CorrectVectorInAllDirections)
{
    DirectionVector dir1(NDPoint({1,1}), NDPoint({0,0}));
    EXPECT_EQ(std::vector<int>({1,1}), dir1.toVector());

    DirectionVector dir2(NDPoint({1,1}), NDPoint({0,1}));
    EXPECT_EQ(std::vector<int>({1,0}), dir2.toVector());

    DirectionVector dir3(NDPoint({1,1}), NDPoint({0,2}));
    EXPECT_EQ(std::vector<int>({1,-1}), dir3.toVector());

    DirectionVector dir4(NDPoint({1,1}), NDPoint({1,0}));
    EXPECT_EQ(std::vector<int>({0,1}), dir4.toVector());

    DirectionVector dir5(NDPoint({1,1}), NDPoint({1,2}));
    EXPECT_EQ(std::vector<int>({0,1}), dir5.toVector());

    DirectionVector dir6(NDPoint({1,1}), NDPoint({2,0}));
    EXPECT_EQ(std::vector<int>({1,-1}), dir6.toVector());

    DirectionVector dir7(NDPoint({1,1}), NDPoint({2,1}));
    EXPECT_EQ(std::vector<int>({1,0}), dir7.toVector());

    DirectionVector dir8(NDPoint({1,1}), NDPoint({2,2}));
    EXPECT_EQ(std::vector<int>({1,1}), dir8.toVector());

    DirectionVector dir3D(NDPoint({1,1,1}), NDPoint({0,1,2}));
    EXPECT_EQ(std::vector<int>({1,0,-1}), dir3D.toVector());
}

TEST(DirectionVectorTest, ContainsOnlySingularValues)
{
    DirectionVector dir2D(NDPoint({0,0}), NDPoint({2,2}));
    EXPECT_EQ(std::vector<int>({1,1}), dir2D.toVector());

    DirectionVector dir3D(NDPoint({1,2,3}), NDPoint({4,5,0}));
    EXPECT_EQ(std::vector<int>({1,1,-1}), dir3D.toVector());
}
