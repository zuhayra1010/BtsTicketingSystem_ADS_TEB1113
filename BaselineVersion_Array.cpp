#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Representation of a single Seat
struct Seat {
    int id;
    bool isAvailable;
};

// Representation of a single User
struct User {
    int id;
    string status;
};

int main() {
    // Parameters from the proposal
    const int TOTAL_SEATS = 5000;
    const int TOTAL_USERS = 10000;

    // Initialize seats array (all available initially)
    vector<Seat> seats(TOTAL_SEATS);
    for (int i = 0; i < TOTAL_SEATS; i++) {
        seats[i].id = i;
        seats[i].isAvailable = true;
    }

    // Initialize users array
    vector<User> users(TOTAL_USERS);
    for (int u = 0; u < TOTAL_USERS; u++) {
        users[u].id = u;
        users[u].status = "PENDING";
    }

    // ============================================================
    // ALGORITHM BaselineTicketingSystem
    // ============================================================
    for (int u = 0; u < TOTAL_USERS; u++) {
        bool ticketSecured = false;

        // Loop through the seats array one by one (Linear Search)
        for (int i = 0; i < TOTAL_SEATS; i++) {
            if (seats[i].isAvailable == true) {
                seats[i].isAvailable = false;
                users[u].status = "SUCCESS: Ticket Booked";
                ticketSecured = true;
                break; // Stop searching and move to the next user
            }
        }

        // If the loop finishes and no seat was found
        if (ticketSecured == false) {
            users[u].status = "FAILED: Sold Out";
        }
    }
    // ============================================================
    // END ALGORITHM
    // ============================================================

    // Print summary to verify result
    int successCount = 0;
    int failedCount = 0;

    for (int u = 0; u < TOTAL_USERS; u++) {
        if (users[u].status == "SUCCESS: Ticket Booked") {
            successCount++;
        } else {
            failedCount++;
        }
    }

    cout << "--- Baseline Simulation Results ---" << endl;
    cout << "Total Requests Processed : " << TOTAL_USERS << endl;
    cout << "Successful Bookings      : " << successCount << endl;
    cout << "Failed / Sold Out        : " << failedCount << endl;

    return 0;
}