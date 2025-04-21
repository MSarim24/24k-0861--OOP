#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Flight {
private:
    string flightNumber;
    string departure, arrival;
    int capacity;
    int bookedSeats;
    unordered_map<string, string> seatMap;

public:
    Flight(string num, string dep, string arr, int cap)
        : flightNumber(num), departure(dep), arrival(arr), capacity(cap), bookedSeats(0) {}

    bool bookSeat(const string& passengerID) {
        if (bookedSeats >= capacity) return false;
        seatMap[passengerID] = "Economy";
        bookedSeats++;
        return true;
    }

    bool cancelSeat(const string& passengerID) {
        if (seatMap.find(passengerID) == seatMap.end()) return false;
        seatMap.erase(passengerID);
        bookedSeats--;
        return true;
    }

    bool upgradeSeat(const string& passengerID) {
        if (seatMap.find(passengerID) == seatMap.end()) return false;
        seatMap[passengerID] = "Business";
        return true;
    }

    void showFlightInfo() const {
        cout << flightNumber << " | From: " << departure << " To: " << arrival << " | Booked: " << bookedSeats << "/" << capacity << endl;
    }
};

class Passenger {
private:
    string id, name;

public:
    Passenger(string i, string n) : id(i), name(n) {}

    void requestBooking(Flight& flight) {
        if (flight.bookSeat(id)) cout << name << " booked successfully.\n";
        else cout << "Booking failed for " << name << ".\n";
    }

    void requestCancellation(Flight& flight) {
        if (flight.cancelSeat(id)) cout << name << " cancelled successfully.\n";
        else cout << "Cancellation failed for " << name << ".\n";
    }

    void requestUpgrade(Flight& flight) {
        if (flight.upgradeSeat(id)) cout << name << " upgraded successfully.\n";
        else cout << "Upgrade failed for " << name << ".\n";
    }
};

int main() {
    Flight f1("PK101", "Lahore", "Karachi", 2);
    Passenger p1("P001", "Ali");
    Passenger p2("P002", "Sara");
    Passenger p3("P003", "Umar");

    p1.requestBooking(f1);
    p2.requestBooking(f1);
    p3.requestBooking(f1); // should fail

    p1.requestUpgrade(f1);
    p2.requestCancellation(f1);
    p3.requestBooking(f1); // should succeed now

    f1.showFlightInfo();

    return 0;
}
