#ifndef DIRECTION_VECTOR_H_
#define DIRECTION_VECTOR_H_

#include <NDPoint.h>

#include <vector>

class DirectionVector
{
public:
    explicit    DirectionVector(const NDPoint & begin, const NDPoint & end);

    std::size_t         size()       const          { return v.size(); }
    std::vector<int>    toVector()   const          { return v; }

    int  operator[](std::size_t idx) const          { return v[idx]; }
    bool operator==(const DirectionVector& other)   { return v == other.toVector(); }
    bool operator!=(const DirectionVector& other)   { return !(*this == other); }

private:
    void                        calculateDirectionVector(const std::pair<NDPoint, NDPoint>& hooks);
    void                        updateScalingFactor(const int diff);
    std::pair<NDPoint, NDPoint> createVectorHooks(const NDPoint& p1, const NDPoint& p2);

    std::vector<int>    v;
    int                 scalingFactor;
};

#endif /* DIRECTION_VECTOR_H_ */

