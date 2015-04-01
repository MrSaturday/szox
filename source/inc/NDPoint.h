#ifndef NDPOINT_H_
#define NDPOINT_H_

#include <vector>
#include <ExceptionModel.h>

class NDPoint
{
public:
    NDPoint(std::vector<unsigned>&& coordinates) :
        coords(std::move(coordinates))
    {
        if(coords.size() == 0)
            THROW("Initialization with no dimensions");
    }

    std::size_t dimensions() const
    {
        return coords.size();
    }

    unsigned getCoordinate(std::size_t dimension) const
    {
        if(dimension >= dimensions())
            THROW("Dimension overflow");
        return coords[dimension];
    }

    bool operator==(const NDPoint& other) const
    {
        return coords == other.coords;
    }

private:
    std::vector<unsigned> coords;
};

#endif /* NDPOINT_H_ */
