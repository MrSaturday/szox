#include <gtest.h>
#include <NDPoint.h>

TEST(NDPointTest, InitalizestToCorrectNumberOfDimensions)
{
    NDPoint point1D({2});
    NDPoint point3D({4,4,4});
    EXPECT_EQ(1, point1D.dimensions());
    EXPECT_EQ(3, point3D.dimensions());
}

TEST(NDPointTest, AccessToAllDimensions)
{
    NDPoint point({0,1,2});
    EXPECT_EQ(0, point.getCoordinate(0));
    EXPECT_EQ(1, point.getCoordinate(1));
    EXPECT_EQ(2, point.getCoordinate(2));
}

TEST(NDPointTest, AccessToInvalidDimension)
{
    NDPoint point({0,0});
    EXPECT_THROW(point.getCoordinate(2), ExceptionModel::exception<NDPoint>);
}
