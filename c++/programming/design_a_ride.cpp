#include <iostream>
#include <vector>
#include <string>

// Forward declarations
class User;
class Driver;

// Enum for ride status
enum class RideStatus {
    REQUESTED,
    ONGOING,
    COMPLETED
};

// Class to represent a ride
class Ride {
public:
    Ride(User* user, Driver* driver, double fare) : user(user), driver(driver), fare(fare), status(RideStatus::REQUESTED) {}

    void startRide() {
        if (status == RideStatus::REQUESTED) {
            status = RideStatus::ONGOING;
            std::cout << "Ride started. Enjoy your journey!\n";
        } else {
            std::cout << "Ride cannot be started. Invalid status.\n";
        }
    }

    void completeRide() {
        if (status == RideStatus::ONGOING) {
            status = RideStatus::COMPLETED;
            std::cout << "Ride completed. Thank you!\n";
        } else {
            std::cout << "Ride cannot be completed. Invalid status.\n";
        }
    }

    double getFare() const {
        return fare;
    }

private:
    User* user;
    Driver* driver;
    double fare;
    RideStatus status;
};

// Class to represent a user
class User {
public:
    User(const std::string& name) : name(name) {}

    const std::string& getName() const {
        return name;
    }

    void requestRide(Driver* driver, double fare) {
        Ride ride(this, driver, fare);
        rides.push_back(ride);
        ride.startRide();
    }

    void viewRideHistory() const {
        std::cout << "Ride history for " << name << ":\n";
        for (const Ride& ride : rides) {
            std::cout << "Status: ";
            switch (static_cast<int>(ride.getStatus())) {
                case 0:
                    std::cout << "Requested";
                    break;
                case 1:
                    std::cout << "Ongoing";
                    break;
                case 2:
                    std::cout << "Completed";
                    break;
                default:
                    std::cout << "Unknown";
                    break;
            }
            std::cout << ", Fare: " << ride.getFare() << "\n";
        }
    }

private:
    std::string name;
    std::vector<Ride> rides;
};

// Class to represent a driver
class Driver {
public:
    Driver(const std::string& name) : name(name) {}

    const std::string& getName() const {
        return name;
    }

private:
    std::string name;
};

int main() {
    // Create users and a driver
    User user1("Alice");
    User user2("Bob");
    Driver driver1("Charlie");

    // Users request rides
    user1.requestRide(&driver1, 20.0);
    user2.requestRide(&driver1, 15.0);

    // View ride history for users
    user1.viewRideHistory();
    user2.viewRideHistory();

    return 0;
}
