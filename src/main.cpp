#include <iostream>
#include <fstream>
#include <sstream>
#include "obstacle.h"

int main() {

    std::ifstream plyFile("../data/obstacle1.pl");
    std::string line;
    int numPoints = 0;
    bool headerEnded = false;

    size_t numVertices = 0;
    size_t numFaces = 0;

    // --- Parse header ---
    while (std::getline(plyFile, line)) {
        if (line.find("element vertex") != std::string::npos) {
            std::istringstream ss(line);
            std::string temp;
            ss >> temp >> temp >> numVertices;  // "element vertex <num>"
        } else if (line.find("end_header") != std::string::npos) {
            headerEnded = true;
            break;
        }
    }

    UltraSonicSensorsDistance::Obstacle obstacle;

    for (size_t i = 0; i < numVertices; ++i) {

        if (!std::getline(plyFile, line)) break;
        std::istringstream ss(line);
        UltraSonicSensorsDistance::Point p;
        ss >> p.x >> p.y >> p.z;
        obstacle.addPoint(p);
    }

    auto obstacle_data = obstacle.getPoints();
    for (const auto& p : obstacle.getPoints()) {
        std::cout << p.x << " " << p.y << " " << p.z << "\n";
    }


}
