/*#include <iostream>
#include "json/json.h"
#include "cariad.h"
namespace cariad {



bool LttsEngineer::parseFile(std::string path) {
    std::ifstream file(path, std::ifstream::binary);
    
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file " + path);
    }

    Json::Value root;
    file >> root;

    if (root.isNull()) {
        throw std::runtime_error("Error: invalid JSON structure in file " + path);
    }

    // Parsing name
    if (root.isMember("name")) {
        name_ = root["name"].asString();
    } else {
        throw std::runtime_error("Error: missing 'name' field in JSON");
    }

    // Parsing age
    if (root.isMember("age")) {
        age_ = root["age"].asInt();
    } else {
        throw std::runtime_error("Error: missing 'age' field in JSON");
    }

    // Parsing address
    if (root.isMember("address")) {
        const Json::Value address = root["address"];
        if (address.isMember("city") && address.isMember("zip")) {
            std::string city = address["city"].asString();
            int zip_code = address["zip"].asInt();
            address_ = std::make_pair(city, zip_code);
        } else {
            throw std::runtime_error("Error: missing 'city' or 'zip' field in 'address'");
        }
    } else {
        throw std::runtime_error("Error: missing 'address' field in JSON");
    }

    // Output for debug
    std::cout << "Name: " << name_ << "\n";
    std::cout << "Age: " << age_ << "\n";
    std::cout << "City: " << address_.first << "\n";

    // Parsing skills
    const Json::Value skills = root["skills"];
    if (skills.isArray()) {
        for (const auto& skill : skills) {
            programming_languages_.push_back(skill.asString());
        }
    } else {
        throw std::runtime_error("Error: 'skills' is not an array or missing");
    }

    return true;
}

}
*/