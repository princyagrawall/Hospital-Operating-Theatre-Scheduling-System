# 🏥 HOSPITAL OPERATING THEATRE SCHEDULING SYSTEM

A C17-based Data Structures and Algorithms project designed to optimize hospital operating theatre scheduling through algorithmic resource allocation, scheduling strategies, and performance analysis.

---

## 📌 Project Overview

Hospital operating theatre scheduling involves allocating surgeries to limited resources while considering surgery priorities, durations, surgeon availability, theatre availability, and medical equipment requirements.

This project implements multiple algorithmic approaches to explore efficient resource allocation, minimize scheduling conflicts, and improve operating theatre utilization.

## 🎯 Objectives

- Develop an efficient hospital surgery scheduling system.
- Apply Data Structures and Algorithms to a real-world problem.
- Implement and compare multiple scheduling algorithms.
- Allocate surgeries based on priority and availability.
- Manage surgeons, operating theatres, and medical equipment.
- Minimize scheduling conflicts.
- Analyze algorithm performance through benchmarking.

---

## ⚙️ Technologies Used

- **Language:** C (C17)
- **Compiler:** GCC
- **Build System:** Makefile
- **Data Storage:** CSV
- **IDE:** Visual Studio Code
- **Version Control:** Git and GitHub

---

## 🧠 Algorithms Implemented

### 1. Greedy Algorithm – Priority-Based Scheduling
- Prioritizes surgeries based on their priority values.
- Allocates available operating theatres.
- Considers scheduling constraints.

### 2. Interval Partitioning
- Allocates surgeries based on their time intervals.
- Avoids overlapping surgeries in the same theatre.
- Aims to utilize available theatres efficiently.

### 3. Backtracking
- Explores different possible theatre assignments.
- Checks scheduling constraints.
- Backtracks when an allocation becomes invalid.

### 4. Branch and Bound
- Explores possible scheduling solutions using a search tree.
- Uses bounds to eliminate unpromising solutions.
- Attempts to find a high-priority feasible allocation.

### 5. Sorting and Searching
- Merge Sort
- Binary Search

---

## ✨ Features

### Hospital Resource Management
- Add and manage surgeries.
- Register surgeons and their specializations.
- Add operating theatres.
- Maintain medical equipment inventory.
- Track surgery duration and priority.

### Scheduling Management
- Generate priority-based schedules.
- Perform interval partitioning.
- Execute backtracking scheduling.
- Execute branch-and-bound scheduling.
- Display scheduled surgeries.
- Calculate theatre utilization.

### Performance Analysis
- Execute scheduling algorithms repeatedly.
- Measure execution time.
- Calculate average execution time.
- Compare algorithm performance.
- Store benchmark results in CSV format.

### Data Persistence
Hospital information is stored using CSV files inside the `data/` directory.

---

## 📂 Project Structure

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
│   └── theatres.csv
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

---

## 🚀 Getting Started

### Prerequisites

- GCC or a compatible C compiler
- Make
- Git

### 1. Clone the Repository

```bash
git clone <YOUR-GITHUB-REPOSITORY-URL>
