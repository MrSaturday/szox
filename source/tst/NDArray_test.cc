#include <NDArray.h>
#include <gtest.h>

TEST(NDArrayTest, InitializesToCorrectSize)
{
    NDArray<char> array1D({14});
    EXPECT_EQ(array1D.size(), 14);

    NDArray<short> array2D({4,4});
    EXPECT_EQ(array2D.size(), 4*4);

    NDArray<int> array3D({1,2,3});
    EXPECT_EQ(array3D.size(), 1*2*3);
}

TEST(NDArrayTest, InvalidInitializationNoDimensions)
{
    EXPECT_THROW(NDArray<int> dummy({}), ExceptionModel::exception<NDArray<int>>);
}

TEST(NDArrayTest, InvalidInitializationZeroSizeDimension)
{
    EXPECT_THROW(NDArray<int> dummy({0,1,2}), ExceptionModel::exception<NDArray<int>>);
}

TEST(NDArrayTest, InvalidInitializationZeroSize)
{
    EXPECT_THROW(NDArray<int> dummy({0,1,2}), ExceptionModel::exception<NDArray<int>>);
}
