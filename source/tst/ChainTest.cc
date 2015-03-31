#include <gtest.h>
#include <Chain.h>

TEST(ChainTest, InitalizationWithSinglePoint)
{
    const NDPoint point({0,1,2});
    Chain chain(point);
    EXPECT_EQ(1, chain.size());
    EXPECT_EQ(point, chain.begin());
    EXPECT_EQ(point, chain.end());
}

TEST(ChainTest, InitializationWithTwoPoints)
{
    const NDPoint first ({0,0});
    const NDPoint second({2,0});
    Chain chain(first, second);
    EXPECT_EQ(3, chain.size());
    EXPECT_EQ(first, chain.begin());
    EXPECT_EQ(second, chain.end());
}

TEST(ChainTest, InitializationWithIncompatiblePoints)
{
    const NDPoint point2D({0,0});
    const NDPoint point3D({1,1,1});
    EXPECT_THROW(Chain(point2D, point3D), ExceptionModel::exception<Chain>);
}

TEST(ChainTest, CalculatesCorrectSizeInAllDirections)
{
    Chain chainE(NDPoint({0,0}), NDPoint({1,0}));
    EXPECT_EQ(2, chainE.size());

    Chain chainS(NDPoint({0,0}), NDPoint({0,2}));
    EXPECT_EQ(3, chainS.size());

    Chain chainSE(NDPoint({0,0}), NDPoint({3,3}));
    EXPECT_EQ(4, chainSE.size());

    Chain chainSW(NDPoint({0,4}), NDPoint({4,0}));
    EXPECT_EQ(5, chainSW.size());

    Chain chain5D(NDPoint({0,0,2,0,0}), NDPoint({0,0,5,0,0}));
    EXPECT_EQ(4, chain5D.size());
}
