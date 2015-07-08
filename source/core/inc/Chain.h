#ifndef CHAIN_H_
#define CHAIN_H_

#include <NDPoint.h>

#include <experimental/optional>

using std::experimental::optional;


class Chain
{
public:
    explicit        Chain(const NDPoint& first,
                          optional<NDPoint> last = optional<NDPoint>());

    std::size_t     size()  const;
    bool            append(const NDPoint & point);
    const NDPoint & begin() const noexcept { return beginPt; }
    const NDPoint & end()   const noexcept { return endPt; }

private: // = assume all data passed here is valid

    bool validatePointToAppend(const NDPoint& point) const;
    bool pointsPermissibleDirection(const NDPoint& point) const;
    bool isCollinear(const NDPoint& point) const;

    NDPoint beginPt;
    NDPoint endPt;
    std::size_t dimensions;
};

#endif /* CHAIN_H_ */

