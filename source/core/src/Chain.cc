#include <Chain.h>

#include <cmath>
#include <algorithm>

Chain::Chain(const NDPoint& first, optional<NDPoint> last) :
    beginPt(first), endPt(first), dimensions(first.dimensions())
{
    if(last)
        if(!append(last.value()))
            THROW("Initializing with non-collinear points");
}

std::size_t Chain::size() const
{
    for(std::size_t dim=0; dim<dimensions; dim++)
        if(begin().getCoordinate(dim) != end().getCoordinate(dim))
            return end().getCoordinate(dim) - begin().getCoordinate(dim) + 1;
    return 1;
}

bool Chain::append(const NDPoint& point)
{
    //TODO: assert(point.dimensions() == dimensions)
    if(point.dimensions() != dimensions)
        THROW("New point has incompatible number of dimensions");
    if(!validatePointToAppend(point))
        return false;

    if(point < beginPt)
        beginPt = point;
    else
        endPt = point;
    return true;
}

bool Chain::validatePointToAppend(const NDPoint & point) const
{
    if(!pointsPermissibleDirection(point))
        return false;
    if(!isCollinear(point))
        return false;
    if(point <= endPt && beginPt <= point)
        return false;
    return true;
}

bool Chain::pointsPermissibleDirection(const NDPoint & point) const
{
    std::vector<unsigned int> diffs;
    for(std::size_t dim = 0; dim < dimensions; ++dim)
    {
        int diff = point.getCoordinate(dim) - beginPt.getCoordinate(dim);
        if(diff)
            diffs.push_back(std::abs(diff));
    }
    return std::all_of(diffs.begin(),
                       diffs.end(),
                       [&](const auto& elem){ return elem == diffs.front(); } );
}

bool Chain::isCollinear(const NDPoint & point) const
{
    if(beginPt == endPt)
        return true;

    return DirectionVector(beginPt, endPt) == DirectionVector(point, beginPt);
}
