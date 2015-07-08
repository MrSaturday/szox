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
    EXPECT_DEATH(Chain(point2D, point3D), "");
}

TEST(ChainTest, InitializationWithNonCollinearPoints)
{
    const NDPoint point1({0,0});
    const NDPoint point2({1,2});
    EXPECT_DEATH(Chain(point1, point2), "");
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

TEST(ChainTest, AppendToSinglePoint)
{
    Chain chain(NDPoint({0,0}));
    EXPECT_TRUE(chain.append(NDPoint({1,0})));
    EXPECT_EQ(NDPoint({0,0}), chain.begin());
    EXPECT_EQ(NDPoint({1,0}), chain.end());
    EXPECT_EQ(2, chain.size());
}

TEST(ChainTest, AppendInFrontOfASinglePoint)
{
    Chain chain(NDPoint({1,1}));
    EXPECT_TRUE(chain.append(NDPoint({0,0})));
    EXPECT_EQ(NDPoint({0,0}), chain.begin());
    EXPECT_EQ(NDPoint({1,1}), chain.end());
    EXPECT_EQ(2, chain.size());
}

TEST(ChainTest, AppendIntoMiddleOfAChain)
{
    Chain chain(NDPoint({0,0}), NDPoint({0,2}));
    EXPECT_FALSE(chain.append(NDPoint({0,1})));
}

TEST(ChainTest, AppendIntoEdgeOfAChain)
{
    Chain chain(NDPoint({1,2,3}), NDPoint({4,5,6}));
    EXPECT_FALSE(chain.append(NDPoint({1,2,3})));
    EXPECT_FALSE(chain.append(NDPoint({4,5,6})));
}

TEST(ChainTest, NotAppendedToCollinearBeginPtButNonCollnearChain)
{
    Chain chain(NDPoint({1,1}), NDPoint({2,2}));
    EXPECT_FALSE(chain.append(NDPoint({0,2})));
}
