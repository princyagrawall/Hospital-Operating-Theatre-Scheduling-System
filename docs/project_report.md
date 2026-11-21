
# Hospital Operating Theatre Scheduling System

## 1. Project Title

**Hospital Operating Theatre Scheduling System Using Design and Analysis of Algorithms**

## 2. Abstract

The Hospital Operating Theatre Scheduling System is a C-based application designed to manage and optimize the scheduling of surgeries in a hospital.

The system helps allocate surgeries to available operating theatres while considering factors such as surgery duration, priority, theatre capacity, and availability.

It implements different algorithmic techniques, including Greedy, Backtracking, and Branch and Bound, to explore scheduling solutions. It also uses sorting and searching techniques to support efficient data processing.

The main objective is to reduce scheduling conflicts, improve theatre utilization, and make hospital operation management more efficient.

## 3. Introduction

Operating theatres are important resources in hospitals. Multiple surgeries may need to be performed during the same period, but the number of available theatres is limited.

Manual scheduling can lead to conflicts, inefficient resource utilization, and delays.

This project provides a computerized solution that uses Design and Analysis of Algorithms (DAA) techniques to organize and schedule surgeries efficiently.

The system is developed using the C programming language and follows a modular programming approach.

## 4. Problem Statement

Hospitals need to schedule multiple surgeries using limited operating theatres and resources.

The major challenges include:

- Limited availability of operating theatres.
- Different surgery durations and priorities.
- Overlapping surgery timings.
- Limited theatre capacity.
- Efficient allocation of available resources.

The project aims to develop an algorithm-based system that helps solve these scheduling challenges.

## 5. Objectives

- To develop a computerized hospital scheduling system.
- To allocate surgeries to available operating theatres.
- To prioritize surgeries based on their importance.
- To reduce overlapping surgery schedules.
- To implement and compare different DAA techniques.
- To improve operating theatre utilization.
- To provide a simple menu-driven interface.

## 6. Existing System

In traditional hospital scheduling, surgeries are often assigned manually.

This approach may result in:

- Scheduling conflicts.
- Poor utilization of operating theatres.
- Difficulty managing multiple surgeries.
- Increased administrative workload.
- Delays in surgery allocation.

## 7. Proposed System

The proposed system uses algorithmic techniques to assist in scheduling surgeries.

It provides the following features:

- Add and manage surgery details.
- Add surgeons and operating theatres.
- Maintain equipment information.
- Generate priority-based schedules.
- Perform interval partitioning.
- Apply Backtracking for theatre allocation.
- Apply Branch and Bound for optimized allocation.
- Display schedules and calculate theatre utilization.
- Store and retrieve hospital data using CSV files.

## 8. Technologies Used

| Component | Technology |
|---|---|
| Programming Language | C |
| Standard | C17 |
| Compiler | GCC / Apple Clang |
| IDE | Visual Studio Code |
| Operating System | macOS |
| Build Tool | Makefile |
| Version Control | Git and GitHub |
| Data Storage | CSV files |

## 9. System Requirements

### Hardware Requirements

- Laptop or Desktop Computer
- Minimum 4 GB RAM
- Basic storage space

### Software Requirements

- macOS / Windows / Linux
- C compiler (GCC or Clang)
- Visual Studio Code
- Terminal
- Git

## 10. Project Architecture

The project follows a modular structure.

### Main Modules

1. **Main Module:** Provides the menu-driven interface and connects different operations.
2. **Domain Module:** Defines data structures for surgeries, surgeons, theatres, and equipment.
3. **Validation Module:** Validates user-entered information.
4. **Input/Output Module:** Loads and saves hospital data using CSV files.
5. **Scheduling Module:** Implements scheduling operations and displays results.
6. **Backtracking Module:** Performs recursive theatre allocation.
7. **Branch and Bound Module:** Searches for promising scheduling solutions.

## 11. Algorithms Used

### 11.1 Greedy Priority Scheduling

The Greedy approach schedules surgeries according to their priority.

The surgery with the highest priority is considered first, and an available suitable theatre is assigned.

**Application:** Helps prioritize important surgeries.

### 11.2 Interval Partitioning

Interval Partitioning is used to allocate surgeries to operating theatres while avoiding overlapping time intervals in the same theatre.

**Application:** Helps manage multiple surgeries with different starting times and durations.

### 11.3 Backtracking

Backtracking explores possible theatre assignments recursively.

If an assignment creates a conflict or prevents a valid complete allocation, the algorithm goes back and tries another assignment.

**Application:** Helps find a feasible allocation of surgeries to theatres.

### 11.4 Branch and Bound

Branch and Bound explores possible theatre assignments while pruning branches that cannot improve the current best solution.

**Application:** Helps search for a high-priority feasible scheduling solution.

### 11.5 Merge Sort

Merge Sort is a Divide and Conquer sorting algorithm that divides data into smaller parts, sorts them, and merges them.

**Application:** Can be used to sort surgery records efficiently.

### 11.6 Binary Search

Binary Search searches for a particular surgery ID in a sorted collection by repeatedly dividing the search interval into two halves.

**Application:** Supports efficient searching of surgery records.

## 12. System Workflow

1. Start the application.
2. Load previously saved hospital data.
3. Display the main menu.
4. Add surgeries, surgeons, theatres, and equipment.
5. Select a scheduling algorithm.
6. Generate the surgery schedule.
7. Display the allocated surgeries.
8. Calculate theatre utilization.
9. Save updated data.
10. Exit the application.

## 13. Expected Results

The system is designed to:

- Store and manage hospital information.
- Generate surgery schedules using different algorithms.
- Reduce theatre scheduling conflicts.
- Allocate available theatres to surgeries.
- Display scheduling information.
- Calculate operating theatre utilization.

Actual performance and scheduling results depend on the input data and the implemented algorithm.

## 14. Limitations

- The system currently uses a basic CSV-based storage mechanism.
- Surgeon availability and detailed equipment compatibility may require further integration.
- The scheduling algorithms use simplified resource-allocation constraints.
- The application does not provide a graphical user interface.
- Real-time hospital data integration is not included.

## 15. Future Scope

The project can be enhanced by:

- Developing a graphical user interface.
- Integrating a database such as MySQL or PostgreSQL.
- Considering surgeon specialization and availability during every scheduling operation.
- Adding equipment compatibility and inventory constraints.
- Supporting emergency surgery scheduling.
- Adding real-time notifications.
- Improving scheduling through additional optimization techniques.

## 16. Conclusion

The Hospital Operating Theatre Scheduling System demonstrates the practical application of Design and Analysis of Algorithms in healthcare management.

By implementing Greedy, Backtracking, Branch and Bound, sorting, and searching techniques, the project provides different approaches to handling operating theatre scheduling problems.

The system demonstrates how algorithmic problem-solving can help organize hospital resources, reduce scheduling conflicts, and improve the efficiency of operating theatre management.

## 17. References

1. Introduction to Algorithms – Thomas H. Cormen et al.
2. Fundamentals of Data Structures and Algorithms.
3. C Programming Language – Brian W. Kernighan and Dennis M. Ritchie.
4. GCC Compiler Documentation.
5. Course materials for Design and Analysis of Algorithms.

