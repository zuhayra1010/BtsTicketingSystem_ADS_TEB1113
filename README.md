# BtsTicketingSystem_ADS_TEB1113
# 🎫 BTS Ticketing System – Reducing Long Wait Times and Server Crashes During High-Demand Ticket Sales

https://img.shields.io/badge/Python-3.10+-blue
https://img.shields.io/badge/Data%20Structure-Queue-green
https://img.shields.io/badge/Algorithms%20Analysis-Orange
https://img.shields.io/badge/TEB1113-ADS-red

---

# 📖 Project Overview

This project was developed as part of the **TEB1113 Algorithm and Data Structure** course.

The system simulates a real-world online ticketing scenario where a highly popular BTS concert opens ticket sales and thousands of fans attempt to purchase tickets at the same moment. Such situations commonly lead to long waiting times, overloaded servers, and website crashes.

To study this problem, we designed and compared two ticket allocation approaches:

1. **Baseline Ticketing System**
   - No traffic management
   - Linear search seat allocation
   - High computational cost

2. **Optimized Ticketing System**
   - FIFO Queue implementation
   - Direct seat allocation using an index pointer
   - Significantly improved system performance

The goal of this project is to demonstrate how selecting an appropriate data structure can improve scalability, fairness, and efficiency during high-demand ticket sales.

---

# 🎯 Problem Statement

When ticket sales open for a BTS concert, thousands of users attempt to access the ticketing platform simultaneously.

For this project, the following scenario is simulated:

| Parameter | Value |
|------------|---------|
| Total Users | 10,000 |
| Available Seats | 5,000 |
| Event | BTS Concert Ticket Sale |
| System Type | Online Ticketing Platform |

Without traffic control, every user request reaches the server at the same time. The server must repeatedly search through seat records to find available seats, resulting in:

- Long waiting times
- Increased CPU usage
- High memory consumption
- System instability
- Potential server crashes

To address these issues, an optimized queue-based solution is introduced.

---

# 📂 Repository Structure

```text
bts-ticketing-system/
│
├── README.md
│
├── baseline/
│   └── baseline_ticketing.py
│
├── optimized/
│   └── optimized_ticketing.py
│
└── benchmark/
    └── compare_results.py
```

---

# 🏗️ System Architecture

## Baseline System

The baseline system allows all users to access the ticketing server simultaneously.

For every incoming request:

1. The system begins searching from Seat 0.
2. The seats array is checked one-by-one.
3. The first available seat is allocated.
4. The search stops and proceeds to the next user.

### Baseline Characteristics

| Feature | Baseline |
|----------|----------|
| Traffic Control | ❌ No |
| Queue Support | ❌ No |
| Waiting Room | ❌ No |
| Seat Allocation | Linear Search |
| Fairness | Low |
| Scalability | Poor |
| Server Stability | Low |

---

## Optimized System

The optimized system introduces a FIFO (First-In, First-Out) queue acting as a virtual waiting room.

Instead of allowing all users to access the server simultaneously:

1. User requests enter a queue.
2. Requests are processed according to arrival order.
3. Seats are assigned using a direct index pointer (`nextAvailableSeatIndex`).
4. No linear search is performed.

### Optimized Characteristics

| Feature | Optimized |
|----------|-----------|
| Traffic Control | ✅ Yes |
| Queue Support | ✅ Yes |
| Waiting Room | ✅ Yes |
| Seat Allocation | Direct Indexing |
| Fairness | High |
| Scalability | Excellent |
| Server Stability | High |

---

# ⚙️ Technologies Used

| Component | Technology |
|------------|------------|
| Language | Python 3 |
| Data Structure | Queue |
| Seat Storage | Array/List |
| Performance Measurement | time.perf_counter() |
| Version Control | Git |
| Repository Hosting | GitHub |

---

# 🚀 Installation

Clone the repository:

```bash
git clone https://github.com/yourusername/bts-ticketing-system.git
```

Navigate into the project folder:

```bash
cd bts-ticketing-system
```

Check Python version:

```bash
python --version
```

Recommended:

```text
Python 3.10+
```

No external libraries are required.

---

# ▶️ Running the Baseline System

From the project root directory:

```bash
python baseline/baseline_ticketing.py
```

or

```bash
cd baseline
python baseline_ticketing.py
```

---

# ▶️ Running the Optimized System

```bash
python optimized/optimized_ticketing.py
```

---

# ▶️ Running the Benchmark Comparison

```bash
python benchmark/compare_results.py
```

The benchmark script executes both systems and compares:

- Execution Time
- Number of Operations
- Successful Bookings
- Failed Bookings
- Overall Performance

---

# 📊 Sample Output

## Baseline System

```text
==================================================
BASELINE TICKETING SYSTEM
==================================================
Total Seats           : 5000
Total Users           : 10000
Tickets Assigned      : 5000
Failed Requests       : 5000
Comparisons           : 37502500
Execution Time        : 1.287423 seconds
==================================================
```

---

## Optimized System

```text
==================================================
OPTIMIZED TICKETING SYSTEM
==================================================
Total Seats           : 5000
Total Users           : 10000
Tickets Assigned      : 5000
Failed Requests       : 5000
Operations            : 10000
Execution Time        : 0.009812 seconds
==================================================
```

---

# 📈 Performance Comparison

| Metric | Baseline System | Optimized System |
|----------|----------------|------------------|
| Total Users | 10,000 | 10,000 |
| Total Seats | 5,000 | 5,000 |
| Seat Allocation Method | Linear Search | Direct Index |
| Queue Used | ❌ No | ✅ Yes |
| Waiting Room | ❌ No | ✅ Yes |
| Search Operations | ~37,500,000 | ~10,000 |
| Server Load | Very High | Low |
| Fairness | Low | High |
| Scalability | Poor | Excellent |
| Disaster Risk | High | Low |

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

Every user potentially performs a search through the entire seat array.

For:

```text
10,000 Users
5,000 Seats
```

The system performs approximately:

```text
37,502,500 comparisons
```

This creates significant processing overhead and increases the likelihood of server crashes during peak traffic.

### Space Complexity

```text
O(1)
```

Only a small fixed number of additional variables is required.

---

## Optimized Algorithm

### Time Complexity

```text
O(N)
```

Each user is:

1. Enqueued once
2. Dequeued once
3. Assigned a seat immediately

All operations execute in constant time.

### Space Complexity

```text
O(N)
```

The queue stores incoming user requests while they wait to be processed.

---

# ✅ Key Improvements Achieved

| Improvement | Baseline | Optimized |
|------------|----------|-----------|
| Traffic Regulation | ❌ | ✅ |
| Fair Ticket Distribution | ❌ | ✅ |
| Server Crash Prevention | ❌ | ✅ |
| Waiting Room Support | ❌ | ✅ |
| Fast Seat Assignment | ❌ | ✅ |
| Scalable to High Demand | ❌ | ✅ |

---

# 🎓 Learning Outcomes

Through this project, we gained practical experience in:

- Queue Data Structures
- Algorithm Design
- Computational Complexity Analysis
- Performance Benchmarking
- System Optimization Techniques
- Big-O Analysis
- Real-World Application of Data Structures

We also demonstrated how an optimized Queue-based solution can significantly outperform a traditional linear-search ticketing system under high-demand conditions.

---

# 👥 Project Members

| No. | Name | Student ID |
|------|--------|-----------|
| 1 | Tuan Nur Afifah Khaira Zulfa binti Tuan Zaki | 24006290 |
| 2 | Farhana binti Yakmin Zada | 24006288 |
| 3 | Nur Insyirah Binti Zaini | 24005781 |
| 4 | Zuhayra Nasrin binti Mohd Zairin | 24006191 |

---

# 📚 Course Information

| Item | Details |
|---------|---------|
| Faculty | Faculty of Science and Information Technology |
| Department | Computer Information Sciences |
| Programme | Bachelor of Computer Science (Hons) |
| Course Code | TEB1113 |
| Course Title | Algorithm and Data Structure |
| Semester | May 2026 |

---

# 📝 License

This repository was developed for educational purposes as part of the TEB1113 Algorithm and Data Structure coursework.

© 2026 BTS Ticketing System Project Team
