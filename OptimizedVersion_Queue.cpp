#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

// ---------- Struct Definitions ----------

struct Seat {
    int id;
    bool isAvailable;
};

struct User {
    int id;
    string status; // e.g. "PENDING", "SUCCESS: Ticket Booked", "FAILED: Sold Out"
};

// ---------- Main Algorithm ----------

int main() {
    const int TOTAL_SEATS = 5000;
    const int TOTAL_USERS = 10000;

    // Initialize seats array: all seats start as available
    vector<Seat> seats(TOTAL_SEATS);
    for (int i = 0; i < TOTAL_SEATS; i++) {
        seats[i].id = i;
        seats[i].isAvailable = true;
    }

    // Initialize incoming user requests
    vector<User> incomingRequests(TOTAL_USERS);
    for (int i = 0; i < TOTAL_USERS; i++) {
        incomingRequests[i].id = i;
        incomingRequests[i].status = "PENDING";
    }

    int nextAvailableSeatIndex = 0;
    queue<User> userQueue;

    // Step 1: Users arrive and are placed into the waiting queue
    for (int i = 0; i < TOTAL_USERS; i++) {
        userQueue.push(incomingRequests[i]);
    }

    // Step 2: System processes users from the queue sequentially
    while (!userQueue.empty()) {
        User currentUser = userQueue.front();
        userQueue.pop();

        // Check if there are still seats left using the pointer index
        if (nextAvailableSeatIndex < TOTAL_SEATS) {
            // Instantly allocate the seat without searching loops
            seats[nextAvailableSeatIndex].isAvailable = false;
            currentUser.status = "SUCCESS: Ticket Booked";

            // Move the index pointer to the next empty seat
            nextAvailableSeatIndex = nextAvailableSeatIndex + 1;
        } else {
            // If pointer exceeds total seats, tickets are sold out
            currentUser.status = "FAILED: Sold Out";
        }

        // Optional: store result back if you need to track per-user outcome
        incomingRequests[currentUser.id].status = currentUser.status;
    }

    // ---------- Print Summary ----------
    int successCount = 0, failCount = 0;
    for (int i = 0; i < TOTAL_USERS; i++) {
        if (incomingRequests[i].status == "SUCCESS: Ticket Booked") {
            successCount++;
        } else {
            failCount++;
        }
    }

    cout << "===== Optimized Ticketing System Results =====" << endl;
    cout << "Total Users: " << TOTAL_USERS << endl;
    cout << "Total Seats: " << TOTAL_SEATS << endl;
    cout << "Tickets Booked (SUCCESS): " << successCount << endl;
    cout << "Tickets Failed (SOLD OUT): " << failCount << endl;
    cout << "Final nextAvailableSeatIndex: " << nextAvailableSeatIndex << endl;

    return 0;
}
