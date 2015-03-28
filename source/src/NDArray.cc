#include <NDArray.h>
#include <ExceptionModel.h>

template<typename T>
NDArray<T>::NDArray(std::vector<std::size_t>&& dimensionsLengths) :
    dimensions(std::move(dimensionsLengths)),
    elements(calculateTotalNumberOfElements(dimensions))
{
    if(dimensions.size() == 0)
        THROW("attempted to create 0-dimensioned array");
    if(elements.size() == 0)
        THROW("at least one dimension's size is 0");
}

template<typename T>
size_t NDArray<T>::calculateTotalNumberOfElements(const std::vector<std::size_t>& dimensionsLengths)
{
    unsigned int numOfElements = 1;
    for(const auto dimensionLength : dimensionsLengths)
        numOfElements *= dimensionLength;

    return numOfElements;
}

template<typename T>
T& NDArray<T>::data(const std::vector<std::size_t>& indexes)
{
    validateAccess(indexes);
    std::size_t idx = calculateLinearIndex(indexes);
    return elements[idx];
}

template<typename T>
void NDArray<T>::validateAccess(const std::vector<std::size_t>& indexes)
{
    if (indexes.size() != dimensions.size())
        THROW("Access to invalid dimension");

    for (std::size_t it = 0; it < dimensions.size(); ++it)
        if (indexes[it] > dimensions[it] - 1)
            THROW("Access to invalid index");
}

template<typename T>
std::size_t NDArray<T>::calculateLinearIndex(const std::vector<std::size_t>& indexes)
{
    std::size_t idx = 0;
    unsigned int multiplier = 1;
    for (std::size_t it = 0; it < dimensions.size(); ++it)
    {
        idx += indexes[it] * multiplier;
        multiplier *= dimensions[it];
    }
    return idx;
}
