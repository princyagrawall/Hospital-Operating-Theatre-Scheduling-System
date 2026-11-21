# Algorithm Comparison: Greedy vs Backtracking

## 1. Introduction

The Hospital Operating Theatre Scheduling System uses Greedy and Backtracking approaches to allocate surgeries to operating theatres while avoiding overlapping time slots.

## 2. Greedy Approach – Interval Partitioning

- Sorts surgeries by their starting time.
- Assigns each surgery to an available theatre.
- Opens a new theatre when no existing theatre is free.
- Provides an efficient allocation for the interval partitioning problem.

**Time Complexity:** O(n²) in the current implementation because of sorting and theatre searching.

**Space Complexity:** O(k), where k is the number of theatres used.

## 3. Backtracking Approach

- Tries assigning a surgery to an available theatre.
- Checks whether the assignment creates a time conflict.
- If an assignment fails, it reverses the choice and tries another theatre.
- Finds a feasible allocation if one exists within the available choices.

**Worst-case Time Complexity:** O(kⁿ), where n is the number of surgeries and k is the number of theatres.

**Space Complexity:** O(n + k), including recursion and assignment storage.

## 4. Comparison

| Feature | Greedy | Backtracking |
|---|---|---|
| Technique | Greedy method | Recursive search |
| Decision | Makes a local choice | Explores alternatives |
| Speed | Generally faster | Can be slower |
| Memory | Lower | Higher |
| Main advantage | Efficient allocation | Can find a feasible allocation when choices require reconsideration |

## 5. Conclusion

Greedy Interval Partitioning is suitable for efficient theatre allocation when surgeries are treated as time intervals. Backtracking explores alternative theatre assignments and can be useful when additional constraints make allocation more complicated. Both approaches demonstrate important Design and Analysis of Algorithms techniques.