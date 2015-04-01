#ifndef CHAIN_H_
#define CHAIN_H_

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
            append(last.value());
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

    void append(const NDPoint& point)
    {
        if(point.dimensions() != dimensions)
            THROW("New point has incompatible number of dimensions");
        endPt = point;
    }

private:
    NDPoint beginPt;
    NDPoint endPt;
    std::size_t dimensions;
};

#endif /* INC_CHAIN_H_ */
