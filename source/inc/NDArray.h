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
    explicit NDArray(std::vector<unsigned>&& dimensionsLengths);

    std::size_t size() const noexcept
    {
        return elements.size();
    }

protected:
    std::size_t calculateTotalNumberOfElements(const std::vector<unsigned>& dimensionsLengths);

    std::vector<T>          elements;
    std::vector<unsigned>   dimensions;
};

#include <NDArray.cc>

#endif /* NDARRAY_H_ */
