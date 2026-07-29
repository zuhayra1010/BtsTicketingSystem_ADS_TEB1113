# 🎫 BTS Ticketing System – Reducing Long Wait Times and Server Crashes During High-Demand Ticket Sales

## 📖 Overview

This project was developed for the **TEB1113 Algorithm and Data Structure** course.

The project simulates a real-world BTS concert ticket sale where a massive number of fans attempt to purchase tickets simultaneously when ticket sales open.

The purpose of this project is to compare two different ticket allocation approaches:

1. **Baseline Ticketing System**
   - No traffic control mechanism.
   - All users access the system simultaneously.
   - Seat allocation uses Linear Search.

2. **Optimized Ticketing System**
   - Uses a Queue (FIFO) as a virtual waiting room.
   - Users are processed sequentially.
   - Seat allocation uses a direct index pointer.

The comparison demonstrates how selecting the correct data structure can significantly improve system efficiency, fairness, and scalability during high-demand ticket sales.

---

# 🎯 Problem Scenario

A BTS concert ticket sale opens and receives an extremely high volume of requests.

### Simulation Configuration

| Parameter | Value |
|------------|----------|
| Total Users | 10,000 |
| Total Seats | 5,000 |
| Event | BTS Concert |
| Booking Type | Online Ticketing System |

Challenges encountered during high-demand sales:

- Long waiting times
- Server overload
- High CPU utilization
- Poor user experience
- Potential system crashes

---

# 📂 Repository Structure

```text
bts-ticketing-system/
│
├── README.md
│
├── baseline/
│   └── baseline_ticketing.cpp
│
├── optimized/
│   └── optimized_ticketing.cpp
```

---

# 🏗️ System Design

## 1️⃣ Baseline Ticketing System

### Description

The baseline system represents a traditional ticketing platform without any traffic management mechanism.

When ticket sales begin:

- All 10,000 users access the system simultaneously.
- Every user performs a Linear Search through the seats array.
- The search starts from Seat 0 every time.
- The first available seat is allocated.
- If no seat is found, the user receives a "Sold Out" message.

### Data Structures Used

| Data Structure | Purpose |
|---------------|---------|
| Vector\<Seat\> | Store seat information |
| Vector\<User\> | Store user information |

### Baseline Booking Process

```text
User Arrives
      ↓
Search Seat Array From Index 0
      ↓
Seat Found?
   ↓       ↓
 Yes       No
 ↓          ↓
Book Seat   Sold Out
```

### Advantages

✅ Easy to implement

✅ Low memory usage

### Disadvantages

❌ Slow seat allocation

❌ Large number of search operations

❌ Does not scale well under heavy traffic

❌ Higher risk of server overload

---

## 2️⃣ Optimized Ticketing System

### Description

The optimized version introduces a Queue (FIFO) to act as a virtual waiting room.

Instead of allowing all users to access the seat allocation system simultaneously:

1. Users enter a queue.
2. Requests are processed in arrival order.
3. Seats are allocated using a pointer called:

```cpp
nextAvailableSeatIndex
```

4. No linear search is required.

### Data Structures Used

| Data Structure | Purpose |
|---------------|---------|
| Queue\<User\> | Manage waiting users |
| Vector\<Seat\> | Store seat information |
| Vector\<User\> | Track booking status |

### Optimized Booking Process

```text
User Arrives
      ↓
Enter Queue
      ↓
Dequeue User
      ↓
Assign Seat Using Index Pointer
      ↓
Booking Completed
```

### Advantages

✅ Faster processing

✅ Fair ticket allocation

✅ Lower server workload

✅ Prevents traffic spikes

✅ Better scalability

### Disadvantages

❌ Requires additional memory for queue storage

---

# ⚙️ Technologies Used

| Technology | Purpose |
|------------|---------|
| C++ | System Development |
| STL Vector | Dynamic Seat & User Storage |
| STL Queue | Waiting Room Implementation |
| Git | Version Control |
| GitHub | Source Code Repository |

---

# 🚀 Compilation & Execution

## Baseline System

Navigate to the baseline folder:

```bash
cd baseline
```

Compile:

```bash
g++ baseline_ticketing.cpp -o baseline
```

Run:

```bash
./baseline
```

---

## Optimized System

Navigate to the optimized folder:

```bash
cd optimized
```

Compile:

```bash
g++ optimized_ticketing.cpp -o optimized
```

Run:

```bash
./optimized
```

---

# 📊 Example Output

## Baseline Output

```text
--- Baseline Simulation Results ---

Total Requests Processed : 10000
Successful Bookings      : 5000
Failed / Sold Out        : 5000
```

---

## Optimized Output

```text
===== Optimized Ticketing System Results =====

Total Users: 10000
Total Seats: 5000
Tickets Booked (SUCCESS): 5000
Tickets Failed (SOLD OUT): 5000
Final nextAvailableSeatIndex: 5000
```

---

# 📈 Feature Comparison

| Feature | Baseline | Optimized |
|----------|----------|----------|
| Traffic Control | ❌ No | ✅ Yes |
| Queue Support | ❌ No | ✅ Yes |
| Waiting Room | ❌ No | ✅ Yes |
| Linear Search | ✅ Yes | ❌ No |
| Direct Seat Allocation | ❌ No | ✅ Yes |
| Fairness | Low | High |
| Scalability | Poor | Excellent |
| Server Stability | Low | High |

---

# 🧮 Complexity Analysis

## Baseline Algorithm

### Time Complexity

```text
O(N × M)
```

Where:

- N = Number of Users
- M = Number of Seats

Reason:

- Outer loop iterates through all users.
- Inner loop performs Linear Search through seats.

Worst-case:

```text
10,000 Users × 5,000 Seats
≈ 50,000,000 operations
```

### Space Complexity

```text
O(1)
```

No additional data structure grows with input size.

---

## Optimized Algorithm

### Time Complexity

```text
O(N)
```

Reason:

- Users are enqueued once.
- Users are dequeued once.
- Seat assignment uses direct indexing.

No nested search loop exists.

### Space Complexity

```text
O(N)
```

The queue stores incoming user requests before they are processed.

---

# 📌 Why Queue Was Chosen

Queue follows the **FIFO (First-In, First-Out)** principle.

Benefits include:

- Fair ticket distribution
- Controlled traffic flow
- Reduced server load
- Better user experience
- Predictable waiting order
- Prevention of sudden traffic spikes

This makes Queue the most suitable data structure for handling BTS concert ticket sales.

---

# 🎓 Learning Outcomes

Through this project, we learned:

- Data Structure Selection
- Queue Implementation
- Linear Search Analysis
- Algorithm Optimization
- Time Complexity Analysis
- Space Complexity Analysis
- Real-World Application of Algorithms
- Performance Comparison Techniques

---

# 👥 Project Members

| No. | Name | Student ID |
|------|------|------------|
| 1 | Tuan Nur Afifah Khaira Zulfa binti Tuan Zaki | 24006290 |
| 2 | Farhana binti Yakmin Zada | 24006288 |
| 3 | Nur Insyirah Binti Zaini | 24005781 |
| 4 | Zuhayra Nasrin binti Mohd Zairin | 24006191 |

---

# 📚 Course Information

| Item | Details |
|--------|----------|
| Faculty | Faculty of Science and Information Technology |
| Department | Computer Information Sciences |
| Programme | Bachelor of Computer Science (Hons) |
| Course Code | TEB1113 |
| Course Title | Algorithm and Data Structure |
| Semester | May 2026 |

---

# 📝 License

This repository is submitted for academic purposes as part of the TEB1113 Algorithm and Data Structure coursework.

© 2026 BTS Ticketing System Project Team
