#ifndef NDPOINT_H_
#define NDPOINT_H_

#include <vector>

class NDPoint
{
public:
    NDPoint(std::vector<unsigned>&& coordinates);

    unsigned    getCoordinate(std::size_t dimension) const;
    std::size_t dimensions()              const { return coords.size(); }

    bool operator==(const NDPoint& other) const { return coords == other.coords; }
    bool operator!=(const NDPoint& other) const { return !(*this == other); }
    bool operator<=(const NDPoint& other) const { return (*this < other) || (*this == other); }
    bool operator< (const NDPoint& other) const;

private:
    std::vector<unsigned> coords;
};

#endif /* NDPOINT_H_ */
