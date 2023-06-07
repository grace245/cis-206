#include <iostream>
#include <vector>
#include <limits>

class Mountain {
private:
    std::string name;
    std::string country;
    double elevation;

public:
    Mountain(const std::string& name, const std::string& country, double elevation)
        : name(name), country(country), elevation(elevation) {}

    std::string getName() const {
        return name;
    }

    std::string getCountry() const {
        return country;
    }

    double getElevation() const {
        return elevation;
    }

    void setName(const std::string& name) {
        this->name = name;
    }

    void setCountry(const std::string& country) {
        this->country = country;
    }

    void setElevation(double elevation) {
        this->elevation = elevation;
    }

    double toMeters() const {
        return elevation / 3.2808;
    }
};

Mountain minElevation(const std::vector<Mountain>& mountains) {
    Mountain minMountain = mountains[0];
    for (const Mountain& mountain : mountains) {
        if (mountain.getElevation() < minMountain.getElevation()) {
            minMountain = mountain;
        }
    }
    return minMountain;
}

int main() {
    std::vector<Mountain> mountains = {
        Mountain("Chimborazo", "Ecuador", 20549),
        Mountain("Matterhorn", "Switzerland", 14692),
        Mountain("Olympus", "Greece (Macedonia)", 9573),
        Mountain("Everest", "Nepal", 29029),
        Mountain("Mount Marcy - Adirondacks", "United States", 5344),
        Mountain("Mount Mitchell - Blue Ridge", "United States", 6684),
        Mountain("Zugspitze", "Switzerland", 9719)
    };

    // Print mountain details and convert elevation to meters
    for (const Mountain& mountain : mountains) {
        std::cout << "Mountain: " << mountain.getName() << std::endl;
        std::cout << "Country: " << mountain.getCountry() << std::endl;
        std::cout << "Elevation (ft): " << mountain.getElevation() << std::endl;
        std::cout << "Elevation (m): " << mountain.toMeters() << std::endl;
        std::cout << std::endl;
    }

    // Find minimum elevation
    Mountain minElevationMountain = minElevation(mountains);
    std::cout << "Shortest Mountain: " << minElevationMountain.getName() << std::endl;
    std::cout << "Elevation (ft): " << minElevationMountain.getElevation() << std::endl;
    std::cout << "Elevation (m): " << minElevationMountain.toMeters() << std::endl;

    return 0;
}