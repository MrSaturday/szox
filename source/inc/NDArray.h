/*
 * ndarray.h
 *
 *  Created on: Mar 25, 2015
 *      Author: sajmon
 */

#ifndef NDARRAY_H_
#define NDARRAY_H_

#include <vector>

template<typename T>
class NDArray
{
public:
    explicit NDArray(std::vector<std::size_t>&& dimensionsLengths);

    T& data(const std::vector<std::size_t>& indexes);

    std::size_t size() const noexcept
    {
        return elements.size();
    }

private:
    std::size_t calculateTotalNumberOfElements(const std::vector<std::size_t>& dimensionsLengths);
    std::size_t calculateLinearIndex(const std::vector<std::size_t>& indexes);
    void        validateAccess(const std::vector<std::size_t>& indexes);

    std::vector<std::size_t>    dimensions;
    std::vector<T>              elements;
};

#include <NDArray.cc>

#endif /* NDARRAY_H_ */
