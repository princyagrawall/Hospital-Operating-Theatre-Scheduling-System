
# 🏥 HOSPITAL OPERATING THEATRE SCHEDULING SYSTEM

### Precision in Every Procedure, Care in Every Decision.

A C17-based Hospital Operating Theatre Scheduling System that applies **Data Structures and Algorithms** to optimize surgery allocation, manage hospital resources, reduce scheduling conflicts, and analyze algorithm performance.

---

## 📌 1. Project Overview

Operating theatres are among the most critical and limited resources in a hospital. Scheduling multiple surgeries requires careful coordination of surgeons, operating theatres, medical equipment, surgery durations, and priorities.

Manual scheduling can lead to resource conflicts, inefficient theatre utilization, and unnecessary delays.

The **Hospital Operating Theatre Scheduling System** addresses this problem through multiple algorithmic approaches implemented in C.

The system provides a menu-driven interface to manage hospital resources, schedule surgeries, compare algorithmic strategies, and evaluate their performance.

### Problem Statement

Given a set of surgeries with different priorities, durations, specialization requirements, and resource requirements, allocate available operating theatres while satisfying scheduling constraints.

### Proposed Solution

Implement and compare multiple algorithmic techniques to find feasible and efficient surgery schedules while considering resource availability and operational constraints.

---

## 🎯 2. Project Objectives

- Automate operating theatre scheduling.
- Implement multiple algorithmic approaches to solve scheduling problems.
- Allocate surgeries according to priority and availability.
- Avoid overlapping surgeries in the same operating theatre.
- Manage surgeons, theatres, and medical equipment.
- Explore recursive and optimization-based scheduling techniques.
- Compare algorithm performance through benchmarking.
- Analyze time complexity and practical execution time.
- Maintain hospital data using persistent CSV storage.

---

## ⚙️ 3. Technologies and Tools

| Technology | Purpose |
|---|---|
| C (C17) | Core implementation |
| GCC | Compilation |
| Makefile | Build automation |
| CSV | Persistent data storage |
| Git | Version control |
| GitHub | Repository hosting |
| VS Code | Development environment |
| macOS Terminal | Compilation and execution |

---

## 🧠 4. Algorithms Implemented

The project explores different algorithmic techniques for scheduling and resource allocation.

### 4.1 Greedy Priority-Based Scheduling

**Approach:** Greedy Algorithm

- Processes surgeries according to their priority.
- Attempts to allocate available surgeons and operating theatres.
- Checks scheduling feasibility before assigning resources.
- Makes locally optimal allocation decisions.

**Objective:** Schedule important surgeries while respecting available resources and time constraints.

### 4.2 Interval Partitioning

**Approach:** Greedy Algorithm

- Considers the time intervals of surgeries.
- Assigns surgeries to operating theatres.
- Prevents overlapping intervals in the same theatre.
- Aims to use the available theatres efficiently.

**Objective:** Allocate a collection of time intervals using an appropriate number of resources.

### 4.3 Backtracking

**Approach:** Recursive Search

- Explores possible operating theatre assignments.
- Checks whether an assignment satisfies scheduling constraints.
- Backtracks when an allocation becomes invalid.
- Searches for a feasible combination of assignments.

**Objective:** Explore alternative resource allocations instead of relying on a single greedy decision.

### 4.4 Branch and Bound

**Approach:** Optimization and State-Space Search

- Represents possible allocations as a search tree.
- Evaluates partial scheduling solutions.
- Uses bounds to eliminate unpromising branches.
- Attempts to find a high-priority feasible allocation.

**Objective:** Reduce unnecessary exploration while searching for a better scheduling solution.

### 4.5 Merge Sort

**Approach:** Divide and Conquer

- Divides data into smaller subproblems.
- Sorts the smaller portions recursively.
- Merges the sorted portions.
- Provides efficient sorting with predictable complexity.

**Time Complexity:** O(n log n)

### 4.6 Binary Search

**Approach:** Divide and Conquer

- Searches for an element in sorted data.
- Repeatedly divides the search interval into two halves.
- Reduces the search space at each step.

**Time Complexity:** O(log n)

---

## 📊 5. Algorithm Complexity Analysis

The following table presents the general theoretical complexity of the algorithmic techniques used in the project. Actual implementation complexity may depend on data structures and constraints.

| Algorithm | Best / Typical Complexity | Worst-Case Complexity |
|---|---|---|
| Greedy Priority Scheduling | Depends on sorting and allocation | Depends on implementation |
| Interval Partitioning | O(n log n) | O(n log n) with efficient sorting |
| Backtracking | Depends on search space | Exponential in general |
| Branch and Bound | Depends on pruning | Exponential in general |
| Merge Sort | O(n log n) | O(n log n) |
| Binary Search | O(1) | O(log n) |

**Note:** Theoretical complexity and measured execution time are different. Benchmark results depend on input size, resource constraints, implementation details, and hardware.

---

## 🏗️ 6. System Architecture

The project is organized into separate modules to improve readability, maintainability, and modularity.

### Main Components

| Module | Responsibility |
|---|---|
| `main.c` | Main application and menu interface |
| `domain.c` | Hospital entities and resource management |
| `validation.c` | Input and scheduling validation |
| `io.c` | CSV loading and saving |
| `scheduling.c` | Greedy and interval-based scheduling |
| `backtracking_scheduler.c` | Recursive scheduling |
| `benchmark.c` | Algorithm performance measurement |

### Algorithm Modules

| Directory | Implementation |
|---|---|
| `algorithms/greedy/` | Interval partitioning |
| `algorithms/backtracking/` | Hospital backtracking |
| `algorithms/branch_bound/` | Least-cost branch and bound |
| `algorithms/sorting/` | Merge sort |
| `algorithms/searching/` | Binary search |

---

## 🔄 7. System Workflow

The application follows a structured workflow:

1. Initialize the hospital management system.
2. Load existing hospital records from CSV files.
3. Register surgeries, surgeons, operating theatres, and equipment.
4. Validate the entered information.
5. Select a scheduling algorithm.
6. Generate a schedule based on the selected approach.
7. Display scheduled and unscheduled surgeries.
8. Calculate operating theatre utilization.
9. Benchmark scheduling algorithms.
10. Save updated records for future execution.

### Workflow Diagram

```text
             START
               |
               v
       Initialize Hospital
               |
               v
       Load Existing Data
               |
               v
       Manage Hospital Data
               |
               v
       Validate Information
               |
               v
       Select Algorithm
               |
       +-------+--------+
       |       |        |
       v       v        v
     Greedy  Backtrack  Branch &
       |       |        Bound
       +-------+--------+
               |
               v
       Generate Schedule
               |
               v
       Display Results
               |
               v
     Calculate Utilization
               |
               v
       Save Hospital Data
               |
               v
              EXIT
```

---

## 🏥 8. Hospital Entities

The system manages four major types of hospital entities.

### 8.1 Surgery

Each surgery contains information such as:

- Surgery ID
- Surgery name
- Duration
- Priority
- Start time
- End time
- Required specialization
- Required medical equipment
- Assigned surgeon
- Assigned operating theatre
- Scheduling status

### 8.2 Surgeon

Each surgeon contains:

- Surgeon ID
- Name
- Specialization
- Availability status

### 8.3 Operating Theatre

Each operating theatre contains:

- Theatre ID
- Theatre name
- Capacity
- Availability status

### 8.4 Medical Equipment

Each equipment record contains:

- Equipment ID
- Equipment name
- Equipment type
- Total quantity
- Available quantity

---

## 🔒 9. Scheduling Constraints

Scheduling decisions must respect important operational conditions.

| Constraint | Description |
|---|---|
| Surgery Duration | Every surgery must have a valid positive duration. |
| Priority | Surgery priority must be within the supported range. |
| Time Limit | Surgery must fit within the 24-hour scheduling window. |
| Surgeon Availability | A surgeon cannot perform overlapping surgeries. |
| Theatre Availability | An operating theatre cannot host overlapping surgeries. |
| Specialization | The assigned surgeon should match the required specialization. |
| Equipment Requirement | Required equipment must be available in sufficient quantity. |
| Resource Allocation | A surgery should be assigned only when its required resources are feasible. |

These constraints form the foundation for validating scheduling decisions.

---

## 💾 10. Data Storage and Persistence

The application uses CSV files to store hospital information.

All persistent records are maintained inside the `data/` directory.

| File | Stored Information |
|---|---|
| `surgeries.csv` | Surgery records |
| `surgeons.csv` | Surgeon records |
| `theatres.csv` | Operating theatre records |
| `equipment.csv` | Equipment inventory |
| `surgery_equipment.csv` | Individual equipment requirements for surgeries |

The system loads previously saved information when it starts and saves updated records during relevant operations.

This allows hospital data to remain available across application sessions without requiring a database server.

---

## 📂 11. Project Directory Structure

```text
Hospital-Operating-Theatre-Scheduling-System/
│
├── algorithms/
│   ├── backtracking/
│   │   └── hospital_backtracking.c
│   ├── branch_bound/
│   │   └── least_cost_branch_bound.c
│   ├── greedy/
│   │   └── interval_partitioning.c
│   ├── searching/
│   │   └── binary_search.c
│   └── sorting/
│       └── merge_sort.c
│
├── benchmarks/
│   └── benchmark_results.csv
│
├── data/
│   ├── equipment.csv
│   ├── surgeons.csv
│   ├── surgeries.csv
│   ├── theatres.csv
│   └── surgery_equipment.csv
│
├── docs/
│   ├── algorithm_analysis.md
│   ├── algorithm_comparison.md
│   ├── complexity_analysis.md
│   ├── project_report.md
│   └── test_cases.md
│
├── include/
│   ├── algorithms.h
│   ├── benchmark.h
│   ├── domain.h
│   ├── io.h
│   ├── scheduling.h
│   └── validation.h
│
├── src/
│   ├── main.c
│   ├── domain.c
│   ├── validation.c
│   ├── io.c
│   ├── scheduling.c
│   ├── backtracking_scheduler.c
│   └── benchmark.c
│
├── tests/
│   ├── test_algorithms.c
│   ├── test_branch_bound.c
│   ├── test_edge_cases.c
│   ├── test_hospital_backtracking.c
│   ├── test_interval_partitioning.c
│   ├── test_scheduling.c
│   └── test_scheduling_edge_cases.c
│
├── Makefile
└── README.md
```

---

## 🚀 12. Installation and Execution

### Prerequisites

- GCC or compatible C compiler
- Make
- Git
- macOS, Linux, or another compatible development environment

### Step 1: Clone the Repository

```bash
git clone <YOUR-GITHUB-REPOSITORY-URL>
```

### Step 2: Navigate to the Project

```bash
cd Hospital-Operating-Theatre-Scheduling-System
```

### Step 3: Compile the Project

```bash
make clean
make
```

### Step 4: Run the Application

```bash
./hospital_scheduler
```

---

## 🖥️ 13. Application Menu

The application provides a menu-driven interface.

```text
1.  Add Surgery
2.  Add Surgeon
3.  Add Operating Theatre
4.  Add Equipment
5.  Display Surgeries
6.  Display Surgeons
7.  Display Theatres
8.  Display Equipment
9.  Generate Priority-Based Schedule (Greedy)
10. Display Schedule
11. Calculate Theatre Utilization
12. Interval Partitioning
13. Backtracking Scheduling
14. Branch and Bound Scheduling
15. Benchmark Scheduling Algorithms
0.  Exit
```

---

## 📈 14. Performance Benchmarking

The project includes a benchmarking module to compare the execution time of scheduling algorithms.

Each algorithm is executed repeatedly, and the average execution time is calculated.

### Sample Benchmark Results

The following values were obtained during one benchmark run with five surgeries and 100 executions per algorithm.

| Algorithm | Average Execution Time |
|---|---:|
| Greedy Priority Scheduling | 34,600 ns |
| Interval Partitioning | 33,180 ns |
| Backtracking | 21,060 ns |
| Branch and Bound | 32,460 ns |

### Benchmark Methodology

- Use the same hospital dataset for each algorithm.
- Execute each algorithm multiple times.
- Measure execution time using a monotonic clock.
- Calculate average execution time.
- Save the results in CSV format.

**Important:** These are sample measurements from one execution environment, not universal performance rankings. A small dataset may produce results that differ significantly from larger scheduling problems.

Benchmark output is saved in:

`benchmarks/benchmark_results.csv`

---

## 🧪 15. Testing and Validation

The project contains separate test programs to verify individual modules and scheduling behavior.

### Testing Areas

- Surgery validation
- Surgeon and theatre validation
- Scheduling correctness
- Interval overlap detection
- Backtracking allocation
- Branch and Bound behavior
- Algorithm correctness
- Edge-case handling

### Important Test Scenarios

| Test Scenario | Expected Behavior |
|---|---|
| Valid surgery details | Surgery is accepted |
| Invalid surgery duration | Validation fails |
| Invalid priority | Validation fails |
| Overlapping theatre assignments | Conflict is detected |
| Overlapping surgeon assignments | Conflict is detected |
| Insufficient equipment | Allocation should be rejected where equipment checks are integrated |
| No available theatre | Surgery remains unscheduled |
| Non-overlapping surgeries | Can share the same theatre at different times |

Test programs are maintained in the `tests/` directory.

---

## 📚 16. Data Structures and Concepts Used

The project applies several fundamental concepts from Data Structures and Algorithms.

- Structures (`struct`) for hospital entities.
- Arrays for storing surgeries and resources.
- Recursion for backtracking.
- Sorting for organizing scheduling data.
- Binary search for efficient searching.
- Greedy strategy for priority-based decisions.
- Divide and conquer for sorting and interval processing.
- State-space search for Branch and Bound.
- Time complexity analysis.
- Algorithm benchmarking.
- File handling for persistent storage.

---

## ⚠️ 17. Current Scope and Limitations

The current implementation is an academic scheduling prototype.

- Scheduling algorithms have different levels of constraint integration.
- Equipment requirements are maintained separately, and full equipment-aware validation across every scheduling algorithm remains a development goal.
- Some algorithms focus primarily on theatre allocation.
- Specialization matching depends on the available surgeon records.
- Benchmark results depend on dataset size and system configuration.
- The application currently uses a command-line interface.

The project is designed to be extended with additional constraints and more advanced scheduling capabilities.

---

## 🔮 18. Future Enhancements

Potential improvements include:

- Integrate complete equipment-aware validation into every scheduling algorithm.
- Improve surgeon specialization matching.
- Add emergency surgery handling.
- Support dynamic rescheduling when resources become unavailable.
- Introduce more advanced optimization strategies.
- Add graphical visualization of operating theatre schedules.
- Generate detailed hospital scheduling reports.
- Support larger datasets.
- Improve input validation and error handling.
- Develop a graphical user interface.

---

## 👩‍💻 19. Academic Project Information

| Field | Details |
|---|---|
| Project Title | Hospital Operating Theatre Scheduling System |
| Programming Language | C17 |
| Subject Area | Design and Analysis of Algorithms |
| Domain | Hospital Management |
| Application | Surgery Scheduling and Resource Allocation |
| Development Approach | Modular Programming |
| Storage | CSV File Handling |

**Project Focus:** Applying algorithmic techniques to a real-world resource allocation and scheduling problem.

---

## ⭐ 20. Conclusion

The Hospital Operating Theatre Scheduling System demonstrates how different algorithmic approaches can be applied to a practical hospital management problem.

By implementing Greedy Algorithms, Interval Partitioning, Backtracking, Branch and Bound, Sorting, and Searching, the project explores different strategies for solving scheduling and resource allocation challenges.

It also provides an opportunity to study algorithm complexity, compare practical execution times, and understand the trade-offs between different problem-solving techniques.

---

**Built with C17 | Designed around Algorithms | Focused on Smarter Scheduling**

⭐ If you find this project interesting, consider giving the repository a star!
