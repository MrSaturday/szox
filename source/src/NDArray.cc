#include <NDArray.h>
#include <ExceptionModel.h>

template<typename T>
NDArray<T>::NDArray(std::vector<unsigned>&& dimensionsLengths) :
    elements(calculateTotalNumberOfElements(dimensionsLengths)),
    dimensions(std::move(dimensionsLengths))
{
    if(dimensions.size() == 0)
        THROW("attempted to create 0-dimensioned array");
    if(elements.size() == 0)
        THROW("at least one dimension's size is 0");
}

template<typename T>
size_t NDArray<T>::calculateTotalNumberOfElements(const std::vector<unsigned>& dimensionsLengths)
{
    unsigned int numOfElements = 1;
    for(const auto dimensionLength : dimensionsLengths)
        numOfElements *= dimensionLength;

    return numOfElements;
}
