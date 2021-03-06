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
    EXPECT_DEATH(NDArray<int> dummy({}), "");
}

TEST(NDArrayTest, InvalidInitializationZeroSizeDimension)
{
    EXPECT_DEATH(NDArray<int> dummy({0,1,2}), "");
}

TEST(NDArrayTest, FillUpArray)
{
    NDArray<int> array({2,3,4});
    int number = 0;
    for(std::size_t i=0; i<2; i++)
        for(std::size_t j=0; j<3; j++)
            for(std::size_t k=0; k<3; k++)
                array.data({i,j,k}) = number++;
    number = 0;
    for(std::size_t i=0; i<2; i++)
        for(std::size_t j=0; j<3; j++)
            for(std::size_t k=0; k<3; k++)
                EXPECT_EQ(number++, array.data({i,j,k}));
}

TEST(NDArrayTest, AccessToInvalidDimension)
{
    NDArray<int> array({3,3,3});
    EXPECT_DEATH(array.data({0,0})     = 42, "");
    EXPECT_DEATH(array.data({0,0,0,0}) = 42, "");
}

TEST(NDArrayTest, ArrayOverflowInOneDimension)
{
    NDArray<int> array({3,3,3});
    EXPECT_DEATH(array.data({2,3,2}) = 42, "");
}
