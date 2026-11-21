
# Complexity Analysis

## 1. Introduction

Complexity analysis is used to measure the efficiency of an algorithm in terms of time and memory.

In the Hospital Operating Theatre Scheduling System, different algorithms are implemented to schedule surgeries, allocate theatres, sort records, and search for information.

The performance of these algorithms is analyzed using Time Complexity and Space Complexity.

### Types of Complexity

**1. Time Complexity:** Measures the amount of time an algorithm takes as the input size increases.

**2. Space Complexity:** Measures the amount of additional memory required by an algorithm.

---

## 2. Greedy Priority Scheduling

### Description

The Greedy Priority Scheduling algorithm sorts surgeries according to their priority and assigns them to available operating theatres.

### Time Complexity

Assuming Bubble Sort is used for sorting:

- Best Case: O(n²)
- Average Case: O(n²)
- Worst Case: O(n²)

The theatre assignment requires O(n × t) time.

Therefore:

**Overall Time Complexity: O(n² + n × t)**

### Space Complexity

The algorithm uses a limited number of additional variables and arrays for theatre information.

**Auxiliary Space: O(t)**

Where:
- n = Number of surgeries
- t = Number of theatres

---

## 3. Greedy Interval Partitioning

### Description

Interval Partitioning assigns surgeries to operating theatres based on their starting and ending times while avoiding overlapping intervals in the same theatre.

### Time Complexity

Assuming Bubble Sort is used:

- Sorting: O(n²)
- Theatre allocation: O(n × t)

**Overall Time Complexity: O(n² + n × t)**

### Space Complexity

An additional array stores the ending time of each theatre.

**Auxiliary Space: O(t)**

Where:
- n = Number of surgeries
- t = Number of theatres

---

## 4. Backtracking

### Description

Backtracking recursively tries different theatre assignments. If an assignment is invalid, the algorithm reverses it and tries another possibility.

### Time Complexity

For n surgeries and t available theatres, each surgery may have up to t possible theatre assignments.

**Worst-Case Time Complexity: O(t^n)**

The actual execution time may be lower because invalid assignments are rejected during the search.

### Space Complexity

The recursive function can go up to n levels deep.

**Auxiliary Space: O(n)**

Where:
- n = Number of surgeries
- t = Number of theatres

---

## 5. Branch and Bound

### Description

Branch and Bound explores possible theatre assignments and uses an upper bound to eliminate branches that cannot improve the current best solution.

### Time Complexity

If each surgery can be assigned to one of t theatres or skipped, the worst-case number of possibilities is:

**Worst-Case Time Complexity: O((t + 1)^n)**

Pruning may reduce the actual number of explored possibilities.

### Space Complexity

The recursive search can reach a depth of n.

**Auxiliary Space: O(n)**

Where:
- n = Number of surgeries
- t = Number of theatres

---

## 6. Merge Sort

### Description

Merge Sort is a Divide and Conquer algorithm that divides an array into smaller parts, sorts them, and merges the sorted parts.

### Time Complexity

| Case | Complexity |
|---|---|
| Best Case | O(n log n) |
| Average Case | O(n log n) |
| Worst Case | O(n log n) |

### Space Complexity

Merge Sort requires additional memory for merging subarrays.

**Auxiliary Space: O(n)**

---

## 7. Binary Search

### Description

Binary Search searches for an element in a sorted array by repeatedly dividing the search interval into two halves.

### Time Complexity

| Case | Complexity |
|---|---|
| Best Case | O(1) |
| Average Case | O(log n) |
| Worst Case | O(log n) |

### Space Complexity

The iterative implementation uses only a few variables.

**Auxiliary Space: O(1)**

---

## 8. Overall Complexity Comparison

| Algorithm | Best Case | Average Case | Worst Case |
|---|---|---|---|
| Greedy Priority Scheduling | O(n² + nt) | O(n² + nt) | O(n² + nt) |
| Interval Partitioning | O(n² + nt) | O(n² + nt) | O(n² + nt) |
| Backtracking | O(1) for immediate completion | Exponential | O(t^n) |
| Branch and Bound | Depends on pruning | Exponential | O((t+1)^n) |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) |
| Binary Search | O(1) | O(log n) | O(log n) |

Where:

- n = Number of surgeries
- t = Number of operating theatres

Note: The scheduling complexities above assume the stated sorting and assignment implementations. Exact complexities should be checked against the final source code.

---

## 9. Comparison of Growth Rates

The common time complexity classes are:

| Complexity | Meaning |
|---|---|
| O(1) | Constant time |
| O(log n) | Logarithmic time |
| O(n) | Linear time |
| O(n log n) | Linearithmic time |
| O(n²) | Quadratic time |
| O(2^n) | Exponential time |

Algorithms with lower growth rates generally perform better as input size increases, although actual performance also depends on implementation and input data.

---

## 10. Conclusion

Complexity analysis helps evaluate the efficiency of different algorithms used in the project.

Greedy algorithms generally provide faster scheduling decisions, while Backtracking and Branch and Bound may require more computation because they explore multiple possible assignments.

Merge Sort provides efficient sorting, and Binary Search provides efficient searching in sorted data.

Understanding time and space complexity helps in selecting appropriate algorithms for efficient hospital operating theatre scheduling.
