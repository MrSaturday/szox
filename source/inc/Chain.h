#ifndef CHAIN_H_
#define CHAIN_H_

#include <NDPoint.h>
#include <ExceptionModel.h>

class Chain
{
public:
    explicit Chain(const NDPoint& point) :
        beginPt(point), endPt(point), dimensions(point.dimensions())
    {
    }

    Chain(const NDPoint& first, const NDPoint& last) :
        beginPt(first), endPt(last), dimensions(first.dimensions())
    {
        if(beginPt.dimensions() != endPt.dimensions())
            THROW("Initialization with dimension-incompatible points");
    }

    std::size_t size() const
    {
        for(int dim=0; dim<dimensions; dim++)
            if(begin().getCoordinate(dim) != end().getCoordinate(dim))
                return end().getCoordinate(dim) - begin().getCoordinate(dim) + 1;
        return 1;
    }

    const NDPoint& begin() const
    {
        return beginPt;
    }

    const NDPoint& end() const
    {
        return endPt;
    }
private:
    NDPoint beginPt;
    NDPoint endPt;
    std::size_t dimensions;
};

#endif /* INC_CHAIN_H_ */
