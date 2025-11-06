#ifndef SENSOR_H
#define SENSOR_H
#include <vector>
#include <cstdint>
#include <string>
#include <cmath>
#include <array>

namespace UltraSonicSensorsDistance {

class Sensor {
    public:

        struct Vec3 {
            double x, y, z;
            Vec3 operator-(const Vec3& o) const { return {x-o.x, y-o.y, z-o.z}; }
            double dot(const Vec3& o) const { return x*o.x + y*o.y + z*o.z; }
        };
        double deg2rad(double deg) { return deg * M_PI / 180.0; }

        std::array<std::array<double,3>,3> eulerToRotationMatrix(double yaw, double pitch, double roll) {
            double cy = cos(deg2rad(yaw)), sy = sin(deg2rad(yaw));
            double cp = cos(deg2rad(pitch)), sp = sin(deg2rad(pitch));
            double cr = cos(deg2rad(roll)), sr = sin(deg2rad(roll));

            return {{
                {cy*cp, cy*sp*sr - sy*cr, cy*sp*cr + sy*sr},
                {sy*cp, sy*sp*sr + cy*cr, sy*sp*cr - cy*sr},
                {-sp,   cp*sr,             cp*cr}
            }};
        }
        Vec3 rotateVec(const std::array<std::array<double,3>,3>& R, const Vec3& v) {
            return {
                R[0][0]*v.x + R[0][1]*v.y + R[0][2]*v.z,
                R[1][0]*v.x + R[1][1]*v.y + R[1][2]*v.z,
                R[2][0]*v.x + R[2][1]*v.y + R[2][2]*v.z
            };
        }
        double distanceToPoint(const Vec3& sensorPos, double yaw, double pitch, double roll, const Vec3& point) {
            auto R = eulerToRotationMatrix(yaw, pitch, roll);
            Vec3 forward{0,0,1};
            Vec3 beamDir = rotateVec(R, forward);
            Vec3 v = point - sensorPos;
            return v.dot(beamDir); // distance along beam
        }
        // Compute sensor world position
        Vec3 sensorWorldPosition(const Vec3& egoPos, double yaw_ego, double pitch_ego, double roll_ego, const Vec3& sensorOffset) {
            auto R = eulerToRotationMatrix(yaw_ego, pitch_ego, roll_ego);
            Vec3 offsetWorld = rotateVec(R, sensorOffset);
            return {egoPos.x + offsetWorld.x, egoPos.y + offsetWorld.y, egoPos.z + offsetWorld.z};
        };

        Sensor(std::string name,float x,float y,float z,float h,float p,float r,int max_range ,int min_range):
            name_(name),
        x(x),y(y),z(z),h(h),p(p),r(r),
        max_range_(max_range),
        min_range_(min_range)
        {
        };


        void setName(std::string name) { name_ = name; };
    
        const std::string  getName() const {return name_; } ;

        int max_range_;
        int min_range_;
        float x ;
        float y ;
        float z ;
        float h ;
        float p ;
        float r ;


    private:
        std::string name_ ;

};

}

#endif
