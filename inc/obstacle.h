#ifndef OBSTACLE_H
#define OBSTACLE_H
#include <vector>
#include <cstdint>

namespace UltraSonicSensorsDistance {
struct Point {
    float x , y , z;
};

class Obstacle {
    public:
        Obstacle() {   
        };

        void addPoint(Point point) { points_.push_back(point); };
            
        const std::vector<Point>  getPoints() const {return points_; } ;

    private:
        std::vector<Point> points_ ;
};

}

#endif
