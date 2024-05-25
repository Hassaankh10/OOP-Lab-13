#include <iostream>
#include <string>

using namespace std;

// Abstract base class Event
class Event {
protected:
    string name;
    string date;
    string venue;

public:
    Event(string name, string date, string venue)
        : name(name), date(date), venue(venue) {}

    // Pure virtual function for calculating ticket price
    virtual float calculateTicketPrice() const = 0;

    // Getter methods
    string getName() const { return name; }
    string getDate() const { return date; }
    string getVenue() const { return venue; }
};

// Derived class for concerts
class Concert : public Event {
private:
    int seatingTier;

public:
    Concert(string name, string date, string venue, int seatingTier)
        : Event(name, date, venue), seatingTier(seatingTier) {}

    // Overridden method to calculate ticket price for concerts
    float calculateTicketPrice() const override {
        // Add pricing logic based on seating tier
        // For demonstration purposes, let's assume some simple pricing logic
        switch (seatingTier) {
            case 1:
                return 50.0;
            case 2:
                return 30.0;
            case 3:
                return 20.0;
            default:
                return 0.0; // Invalid seating tier
        }
    }
};

// Derived class for conferences
class Conference : public Event {
private:
    bool isSpeaker;

public:
    Conference(string name, string date, string venue, bool isSpeaker)
        : Event(name, date, venue), isSpeaker(isSpeaker) {}

    // Overridden method to calculate ticket price for conferences
    float calculateTicketPrice() const override {
        // Add pricing logic based on attendee type (attendee/speaker)
        // For demonstration purposes, let's assume some simple pricing logic
        if (isSpeaker) {
            return 100.0; // Speaker fee
        } else {
            return 200.0; // Attendee fee
        }
    }
};

// Derived class for exhibitions
class Exhibition : public Event {
private:
    string ticketCategory;

public:
    Exhibition(string name, string date, string venue, string ticketCategory)
        : Event(name, date, venue), ticketCategory(ticketCategory) {}

    // Overridden method to calculate ticket price for exhibitions
    float calculateTicketPrice() const override {
        // Add pricing logic based on ticket category
        // For demonstration purposes, let's assume some simple pricing logic
        if (ticketCategory == "Regular") {
            return 20.0;
        } else if (ticketCategory == "VIP") {
            return 50.0;
        } else {
            return 0.0; // Invalid ticket category
        }
    }
};

int main() {
    // Create an array of Event pointers
    const int numEvents = 3;
    Event* events[numEvents];

    // Populate the array with instances of different event types
    events[0] = new Concert("Rock Concert", "2024-05-20", "GlobaArena", 2);
    events[1] = new Conference("Business Conference", "2024-06-15", "GlobaArena", true);
    events[2] = new Exhibition("Art Exhibition", "2024-07-10", "GlobaArena", "Regular");

    // Demonstrate functionality by iterating through the array
    for (int i = 0; i < numEvents; ++i) {
        cout << "Event: " << events[i]->getName() << endl;
        cout << "Date: " << events[i]->getDate() << endl;
        cout << "Venue: " << events[i]->getVenue() << endl;
        cout << "Ticket Price: $" << events[i]->calculateTicketPrice() << endl;
        cout << endl;
    }

    // Free memory
    for (int i = 0; i < numEvents; ++i) {
        delete events[i];
    }

    return 0;
}
