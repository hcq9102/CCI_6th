// https://godbolt.org/z/a6br5EWzj

#include <iostream>
#include <vector>
#include <optional>
#include <string>

using namespace std;

class Spot {
private:
    int spotNum;
    bool isOccupied;

public:
    Spot(int num) : spotNum(num), isOccupied(false) {}

    bool isAvailable() const {
        return !isOccupied;
    }

    void occupy() {
        isOccupied = true;
    }

    void vacate() {
        isOccupied = false;
    }

    int getSpotNumber() const {
        return spotNum;
    }
};

class Vehicle {
private:
    string licensePlate;
    string vehicleType;

public:
    Vehicle(string plate, string type) : licensePlate(plate), vehicleType(type) {}

    string getLicensePlate() const {
        return licensePlate;
    }

    string getVehicleType() const {
        return vehicleType;
    }
};

class ParkingLot {
private:
    vector<Spot> spots;

public:
    void addSpot(const Spot& spot) {
        spots.push_back(spot);
    }

    optional<Spot*> findAvailableSpot() {
        for (auto& spot : spots) {
            if (spot.isAvailable()) {
                return &spot; // 返回 Spot 对象的引用
            }
        }
        return nullopt; // 没有找到可用车位
    }



    bool parkVehicle(Vehicle& vehicle) {
        auto spotOpt = findAvailableSpot();
        if (spotOpt) {
            Spot* spot = *spotOpt; // deref 解引用 std::optional<Spot*>
            spot->occupy();
            cout << "Vehicle with license plate " << vehicle.getLicensePlate() << " parked at spot " << spot->getSpotNumber() << endl;
            return true;
        }
        return false;
    }

    bool exitVehicle(Vehicle& vehicle) {
        for (auto& spot : spots) {
            if (!spot.isAvailable()) {
                spot.vacate();
                cout << "Vehicle with license plate " << vehicle.getLicensePlate() << " exited from spot " << spot.getSpotNumber() << endl;
                return true;
            }
        }
        return false;
    }
};

int main() {
    ParkingLot parkingLot;

    // 创建车位
    Spot spot1(1);
    Spot spot2(2);
    Spot spot3(3);
    Spot spot4(4);

    // 将车位添加到车库
    parkingLot.addSpot(spot1);
    parkingLot.addSpot(spot2);
    parkingLot.addSpot(spot3);
    parkingLot.addSpot(spot4);

    // 创建车辆
    Vehicle vehicle1("ABC123", "Small Car");
    Vehicle vehicle2("XYZ789", "Large Car");
    Vehicle vehicle3("EDF699", "Small Car");
    Vehicle vehicle4("PQU599", "Large Car");

    // 停车
    cout << "Parking vehicles..." << endl;

    if (parkingLot.parkVehicle(vehicle1)) {
        cout << "Vehicle 1 (License Plate: " << vehicle1.getLicensePlate() << ") parked successfully!" << endl;
    } else {
        cout << "No available spot for Vehicle 1." << endl;
    }

    if (parkingLot.parkVehicle(vehicle2)) {
        cout << "Vehicle 2 (License Plate: " << vehicle2.getLicensePlate() << ") parked successfully!" << endl;
    } else {
        cout << "No available spot for Vehicle 2." << endl;
    }

    if (parkingLot.parkVehicle(vehicle3)) {
        cout << "Vehicle 3 (License Plate: " << vehicle3.getLicensePlate() << ") parked successfully!" << endl;
    } else {
        cout << "No available spot for Vehicle 3." << endl;
    }

    if (parkingLot.parkVehicle(vehicle4)) {
        cout << "Vehicle 4 (License Plate: " << vehicle4.getLicensePlate() << ") parked successfully!" << endl;
    } else {
        cout << "No available spot for Vehicle 4." << endl;
    }

    // 查找空车位
    auto availableSpot = parkingLot.findAvailableSpot();
    if (availableSpot) {
        cout << "Found an available spot with number: " << (*availableSpot)->getSpotNumber() << endl;
    } else {
        cout << "No available spot found." << endl;
    }

    // 取车
    cout << "Exiting vehicles..." << endl;

    if (parkingLot.exitVehicle(vehicle1)) {
        cout << "Vehicle 1 (License Plate: " << vehicle1.getLicensePlate() << ") removed successfully!" << endl;
    } else {
        cout << "Vehicle 1 was not found." << endl;
    }

    if (parkingLot.exitVehicle(vehicle2)) {
        cout << "Vehicle 2 (License Plate: " << vehicle2.getLicensePlate() << ") removed successfully!" << endl;
    } else {
        cout << "Vehicle 2 was not found." << endl;
    }

    if (parkingLot.exitVehicle(vehicle3)) {
        cout << "Vehicle 3 (License Plate: " << vehicle3.getLicensePlate() << ") removed successfully!" << endl;
    } else {
        cout << "Vehicle 3 was not found." << endl;
    }

    if (parkingLot.exitVehicle(vehicle4)) {
        cout << "Vehicle 4 (License Plate: " << vehicle4.getLicensePlate() << ") removed successfully!" << endl;
    } else {
        cout << "Vehicle 4 was not found." << endl;
    }

    return 0;
}


