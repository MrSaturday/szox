#include <NDPoint.h>

#include <cassert>

NDPoint::NDPoint(std::vector<unsigned>&& coordinates):
    coords(std::move(coordinates))
{
    assert(coords.size() != 0);
}

unsigned NDPoint::getCoordinate(std::size_t dimension) const
{
    assert(dimension < dimensions());
    return coords[dimension];
}

bool NDPoint::operator<(const NDPoint& other) const
{
    assert(other.dimensions() == dimensions());
    for(std::size_t dim = 0; dim < dimensions(); dim++)
        if(getCoordinate(dim) < other.getCoordinate(dim))
            return true;
        else if(getCoordinate(dim) > other.getCoordinate(dim))
            return false;
    return false;
}
