#include <iostream>
#include <string>

using namespace std;

// Base class Flight
class Flight {
protected:
    string flightNumber;
    string departureAirport;
    string arrivalAirport;
    string departureTime;
    string arrivalTime;
    string airline;

public:
    Flight(string flightNumber, string departureAirport, string arrivalAirport,
           string departureTime, string arrivalTime, string airline)
        : flightNumber(flightNumber), departureAirport(departureAirport),
          arrivalAirport(arrivalAirport), departureTime(departureTime),
          arrivalTime(arrivalTime), airline(airline) {}

    // Virtual function for booking
    virtual void book() const = 0;

    // Overloaded operator for tax addition
    virtual double operator+(double amount) const {
        // Default implementation applies no tax
        return amount;
    }

    // Getter methods
    string getFlightNumber() const { return flightNumber; }
    string getDepartureAirport() const { return departureAirport; }
    string getArrivalAirport() const { return arrivalAirport; }
    string getDepartureTime() const { return departureTime; }
    string getArrivalTime() const { return arrivalTime; }
    string getAirline() const { return airline; }
};

// Derived class for StandardFlight
class StandardFlight : public Flight {
private:
    int standardSeatingCapacity;

public:
    StandardFlight(string flightNumber, string departureAirport, string arrivalAirport,
                   string departureTime, string arrivalTime, string airline,
                   int standardSeatingCapacity)
        : Flight(flightNumber, departureAirport, arrivalAirport, departureTime, arrivalTime, airline),
          standardSeatingCapacity(standardSeatingCapacity) {}

    void book() const override {
        cout << "Booking a standard flight" << endl;
        // Additional booking logic specific to standard flights
    }

    double operator+(double amount) const override {
        // Add 20% tax for standard flights
        return amount * 1.20;
    }
};

// Derived class for PremiumFlight
class PremiumFlight : public Flight {
private:
    int premiumSeatingCapacity;
    bool gourmetMeals;

public:
    PremiumFlight(string flightNumber, string departureAirport, string arrivalAirport,
                  string departureTime, string arrivalTime, string airline,
                  int premiumSeatingCapacity, bool gourmetMeals)
        : Flight(flightNumber, departureAirport, arrivalAirport, departureTime, arrivalTime, airline),
          premiumSeatingCapacity(premiumSeatingCapacity), gourmetMeals(gourmetMeals) {}

    void book() const override {
        cout << "Booking a premium flight" << endl;
        // Additional booking logic specific to premium flights
    }

    double operator+(double amount) const override {
        // Add 50% tax for premium flights
        return amount * 1.50;
    }
};

// Derived class for LuxuryFlight
class LuxuryFlight : public Flight {
private:
    int luxurySeatingCapacity;
    bool exclusiveLoungeAccess;

public:
    LuxuryFlight(string flightNumber, string departureAirport, string arrivalAirport,
                 string departureTime, string arrivalTime, string airline,
                 int luxurySeatingCapacity, bool exclusiveLoungeAccess)
        : Flight(flightNumber, departureAirport, arrivalAirport, departureTime, arrivalTime, airline),
          luxurySeatingCapacity(luxurySeatingCapacity), exclusiveLoungeAccess(exclusiveLoungeAccess) {}

    void book() const override {
        cout << "Booking a luxury flight" << endl;
        // Additional booking logic specific to luxury flights
    }

    double operator+(double amount) const override {
        // No additional tax for luxury flights
        return amount;
    }
};

// Generic booking system using templates
template<class T>
void bookFlight(const T& flight) {
    flight.book();
}

int main() {
    StandardFlight stdFlight("SF123", "JFK", "LAX", "12:00", "15:00", "Airline A", 200);
    PremiumFlight premFlight("PF456", "LAX", "JFK", "16:00", "19:00", "Airline B", 100, true);
    LuxuryFlight luxFlight("LF789", "LHR", "CDG", "08:00", "10:00", "Airline C", 50, true);

    bookFlight(stdFlight);
    bookFlight(premFlight);
    bookFlight(luxFlight);

    // Example of applying taxes using overloaded operators
    double totalAmount = 500.0;
    totalAmount = stdFlight + totalAmount;
    totalAmount = premFlight + totalAmount;
    totalAmount = luxFlight + totalAmount;

    cout << "Total amount with taxes: $" << totalAmount << endl;

    return 0;
}
