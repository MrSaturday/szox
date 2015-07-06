#include <NDPoint.h>

NDPoint::NDPoint(std::vector<unsigned>&& coordinates):
    coords(std::move(coordinates))
{
    if(coords.size() == 0)
        THROW("Initialization with no dimensions");
}

unsigned NDPoint::getCoordinate(std::size_t dimension) const
{
    if(dimension >= dimensions())
        THROW("Dimension overflow");
    return coords[dimension];
}

bool NDPoint::operator<(const NDPoint& other) const
{
    if(other.dimensions() != dimensions())
        THROW("Incompatible dimensions");
    for(std::size_t dim=0; dim<dimensions(); dim++)
        if(getCoordinate(dim) < other.getCoordinate(dim))
            return true;
        else if(getCoordinate(dim) > other.getCoordinate(dim))
            return false;
    return false;
}
