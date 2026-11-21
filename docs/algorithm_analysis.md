
# Algorithm Analysis

## 1. Introduction

The Hospital Operating Theatre Scheduling System uses different algorithmic techniques to allocate surgeries to available operating theatres.

The project demonstrates Greedy, Backtracking, Branch and Bound, Sorting, and Searching algorithms.

This document explains their working principles, pseudocode, applications, and time complexities.

---

## 2. Greedy Priority Scheduling

### Concept

Greedy Priority Scheduling selects the surgery with the highest priority first and attempts to assign it to an available operating theatre.

At each step, the algorithm makes a locally best choice based on surgery priority.

### Working

1. Read all available surgeries.
2. Sort surgeries according to priority.
3. Select the highest-priority surgery.
4. Check theatre availability and capacity.
5. Assign a suitable theatre if available.
6. Continue until all surgeries are considered.

### Pseudocode

```text
GREEDY-PRIORITY-SCHEDULING(surgeries, theatres)

1. Sort surgeries by decreasing priority.
2. FOR each surgery:
      FOR each theatre:
          IF theatre is available
             AND theatre has sufficient capacity
             AND no scheduling conflict exists:
                 Assign surgery to theatre.
                 Mark surgery as scheduled.
                 BREAK
3. Display the schedule.
```

### Complexity

- Sorting: O(n²) if Bubble Sort is used.
- Theatre assignment: O(n × t), where t is the number of theatres.
- Overall: O(n² + n × t) with Bubble Sort.

### Application

Used to give preference to high-priority surgeries.

---

## 3. Greedy Interval Partitioning

### Concept

Interval Partitioning allocates surgeries to operating theatres while ensuring that two overlapping surgeries are not assigned to the same theatre.

Each surgery is represented by a time interval consisting of its start time and end time.

### Working

1. Sort surgeries by starting time.
2. Select the next surgery.
3. Check the available theatres.
4. Find a theatre that is free during the surgery interval.
5. Assign the surgery to that theatre.
6. Continue until all surgeries are processed.

### Pseudocode

```text
INTERVAL-PARTITIONING(surgeries, theatres)

1. Sort surgeries by starting time.
2. FOR each surgery:
      FOR each theatre:
          IF theatre is available
             AND theatre has sufficient capacity
             AND theatre is free:
                 Assign surgery to theatre.
                 Update theatre's end time.
                 BREAK
3. Display the allocation.
```

### Complexity

- Sorting: O(n²) if Bubble Sort is used.
- Theatre allocation: O(n × t).
- Overall: O(n² + n × t).

### Application

Used to allocate surgeries with different starting times and durations without overlapping in the same theatre.

---

## 4. Backtracking

### Concept

Backtracking is a recursive algorithmic technique that explores different possible solutions.

In this project, it tries assigning surgeries to different operating theatres. If an assignment creates a conflict or prevents a valid complete allocation, it backtracks and tries another theatre.

### Working

1. Select the next surgery.
2. Try assigning it to an available theatre.
3. Check capacity and scheduling conflicts.
4. If the assignment is valid, move to the next surgery.
5. If no valid assignment is possible, undo the previous assignment.
6. Try another theatre.
7. Continue until a complete valid allocation is found or all possibilities are exhausted.

### Pseudocode

```text
BACKTRACK(index)

1. IF index == number of surgeries:
       RETURN SUCCESS

2. FOR each theatre:
       IF assignment is valid:
           Assign surgery to theatre.

           IF BACKTRACK(index + 1) succeeds:
               RETURN SUCCESS

           Undo assignment.

3. RETURN FAILURE
```

### Complexity

- Worst-case time complexity: O(t^n), where:
  - n = number of surgeries
  - t = number of theatres
- Recursive space complexity: O(n), excluding additional data structures.

### Application

Used to explore different theatre assignments and find a feasible schedule.

---

## 5. Branch and Bound

### Concept

Branch and Bound is an optimization technique that explores possible solutions while eliminating branches that cannot improve the current best solution.

In this project, it explores theatre assignments and uses an upper bound on the possible priority score to prune unpromising branches.

### Working

1. Start with the first surgery.
2. Generate possible theatre assignments.
3. Check whether each assignment is valid.
4. Calculate the current priority score.
5. Estimate the maximum possible score from the remaining surgeries.
6. If the estimated score cannot exceed the best score, prune that branch.
7. Otherwise, continue exploring.
8. Store the best allocation found.

### Pseudocode

```text
BRANCH-AND-BOUND(index, currentScore)

1. IF index == number of surgeries:
       Update best solution if currentScore is better.
       RETURN

2. Calculate upper bound.

3. IF upper bound <= bestScore:
       RETURN

4. FOR each theatre:
       IF assignment is valid:
           Assign surgery to theatre.

           BRANCH-AND-BOUND(
               index + 1,
               currentScore + surgery priority
           )

           Undo assignment.

5. Explore skipping the surgery if the implementation allows it.
```

### Complexity

- Worst-case time complexity: Exponential, O((t + 1)^n) if each surgery can be assigned to one of t theatres or skipped.
- Space complexity: O(n) for recursive depth, excluding auxiliary structures.
- Actual performance depends on the effectiveness of pruning.

### Application

Used to search for a high-priority feasible allocation while avoiding unnecessary exploration of unpromising branches.

---

## 6. Merge Sort

### Concept

Merge Sort is a Divide and Conquer sorting algorithm.

It divides an array into smaller subarrays, sorts them recursively, and merges the sorted subarrays.

### Working

1. Divide the array into two halves.
2. Recursively sort both halves.
3. Merge the sorted halves.
4. Continue until the complete array is sorted.

### Pseudocode

```text
MERGE-SORT(array, low, high)

1. IF low < high:
       mid = (low + high) / 2

       MERGE-SORT(array, low, mid)
       MERGE-SORT(array, mid + 1, high)

       MERGE(array, low, mid, high)
```

### Complexity

- Best case: O(n log n)
- Average case: O(n log n)
- Worst case: O(n log n)
- Auxiliary space: O(n)

### Application

Can be used to sort surgery records based on priority, start time, or ID.

---

## 7. Binary Search

### Concept

Binary Search is an efficient searching algorithm used to find an element in a sorted array.

It repeatedly divides the search interval into two halves.

### Working

1. Initialize the low and high positions.
2. Find the middle element.
3. Compare its ID with the target ID.
4. If both match, return the position.
5. If the target is smaller, search the left half.
6. Otherwise, search the right half.
7. Repeat until the element is found or the search interval becomes empty.

### Pseudocode

```text
BINARY-SEARCH(array, target)

1. low = 0
2. high = n - 1

3. WHILE low <= high:
       mid = low + (high - low) / 2

       IF array[mid] == target:
           RETURN mid

       ELSE IF array[mid] < target:
           low = mid + 1

       ELSE:
           high = mid - 1

4. RETURN NOT FOUND
```

### Complexity

- Best case: O(1)
- Average case: O(log n)
- Worst case: O(log n)
- Space complexity: O(1) for iterative implementation.

### Application

Used in the standalone demonstration to search for a surgery using its ID. The input records must be sorted by ID.

---

## 8. Summary of Algorithms

| Algorithm | Technique | Worst-Case Time Complexity |
|---|---|---|
| Priority Scheduling | Greedy | O(n² + nt) |
| Interval Partitioning | Greedy | O(n² + nt) |
| Backtracking | Recursive Search | O(t^n) |
| Branch and Bound | Optimization | O((t+1)^n) |
| Merge Sort | Divide and Conquer | O(n log n) |
| Binary Search | Searching | O(log n) |

Where:

- n = Number of surgeries
- t = Number of operating theatres

---

## 9. Conclusion

Different algorithmic techniques provide different approaches to the hospital scheduling problem.

Greedy algorithms provide quick scheduling decisions, Backtracking explores possible assignments, and Branch and Bound reduces unnecessary search using pruning.

Merge Sort and Binary Search demonstrate efficient sorting and searching techniques.

Together, these algorithms illustrate the practical application of Design and Analysis of Algorithms in hospital resource management.
