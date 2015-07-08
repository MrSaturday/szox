#include <DirectionVector.h>

#include <cmath>

DirectionVector::DirectionVector(const NDPoint & begin, const NDPoint & end)  :
    v(begin.dimensions(), 0),
    scalingFactor(1)
{
    calculateDirectionVector(createVectorHooks(begin, end));
}

void DirectionVector::calculateDirectionVector(const std::pair<NDPoint, NDPoint> & hooks)
{
    for (std::size_t dim = 0; dim < v.size(); ++dim)
    {
        int diff = hooks.second.getCoordinate(dim) - hooks.first.getCoordinate(dim);
        updateScalingFactor(diff);
        v[dim] = diff / scalingFactor;
    }
}

void DirectionVector::updateScalingFactor(const int diff)
{
//  TODO
//  if(scalingFactor != 1)
//     assert(std::abs(diff) == scalingFactpr)
    if(diff != 0)
        scalingFactor = std::abs(diff);;
}

std::pair<NDPoint, NDPoint>
DirectionVector::createVectorHooks(const NDPoint & p1, const NDPoint & p2)
{
    if(p2 < p1)
        return std::make_pair(p2, p1);
    return std::make_pair(p1, p2);
}
