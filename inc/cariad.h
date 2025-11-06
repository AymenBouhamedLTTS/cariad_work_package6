#ifndef CARIAD_H
#define CARIAD_H
#include <fstream>
#include <vector>
#include <cstdint>
#include <string>

namespace cariad {

class LttsEngineer {
    public:
        using Address = std::pair<std::string,int>;

        LttsEngineer() {};

        void setName(const std::string& name) { name_ = name; };
        
        void setAge(const uint16_t& age) { age_ = age; };
        
        void setProgrammingLanguages(const std::vector<std::string>& programming_languages) { programming_languages_ = programming_languages; };
        
        void setAddress(const Address& address) { address_ = address; };

        bool parseFile(std::string path) {};
        
        const std::string getName() const { return name_ ;};

        const uint16_t getAge() const {return age_; } ;

        const std::vector<std::string> getProgrammingLanguages() const {return programming_languages_; } ;

        const Address getAddress() const {return address_ ; };

    private:
        std::string name_ ;
        uint16_t age_ ;
        std::vector<std::string> programming_languages_ ;
        Address address_;
};

}

#endif
