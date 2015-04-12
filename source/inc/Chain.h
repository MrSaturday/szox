#ifndef CHAIN_H_
#define CHAIN_H_

#include <cmath>
#include <algorithm>
#include <experimental/optional>
#include <NDPoint.h>
#include <ExceptionModel.h>

using std::experimental::optional;

class Chain
{
public:
    explicit Chain(const NDPoint& first, optional<NDPoint> last = optional<NDPoint>()) :
        beginPt(first), endPt(first), dimensions(first.dimensions())
    {
        if(last)
            if(!append(last.value()))
                THROW("Initializing with non-collinear points");
    }

    std::size_t size() const
    {
        for(int dim=0; dim<dimensions; dim++)
            if(begin().getCoordinate(dim) != end().getCoordinate(dim))
                return end().getCoordinate(dim) - begin().getCoordinate(dim) + 1;
        return 1;
    }

    const NDPoint& begin() const noexcept
    {
        return beginPt;
    }

    const NDPoint& end() const noexcept
    {
        return endPt;
    }

    bool append(const NDPoint& point)
    {
        //TODO: assert(point.dimensions() != dimensions)
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

private: // = assume all data passed here is valid
    bool isCollinear(const NDPoint& point)
    {
        std::vector<unsigned> diffs;
        for(unsigned int i=0; i<dimensions; ++i)
        {
            unsigned diff = std::abs(static_cast<int>(point.getCoordinate(i) - beginPt.getCoordinate(i)));
            if(diff)
                diffs.push_back(diff);
        }
        return std::all_of(diffs.begin(),
                           diffs.end(),
                           [&](const auto& elem){ return elem == diffs.front(); } );
    }

    bool validatePointToAppend(const NDPoint& point)
    {
        if(!isCollinear(point))
            return false;
        if(point < endPt && beginPt < point)
            return false;
        return true;
    }

    NDPoint beginPt;
    NDPoint endPt;
    std::size_t dimensions;
};

#endif /* INC_CHAIN_H_ */
