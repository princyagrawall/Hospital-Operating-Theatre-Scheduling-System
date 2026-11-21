
# Algorithm Comparison

## 1. Introduction

The Hospital Operating Theatre Scheduling System uses different algorithmic techniques to allocate surgeries to available operating theatres.

Each algorithm has a different approach, execution time, and level of solution exploration.

This document compares Greedy, Backtracking, and Branch and Bound scheduling techniques, along with the supporting sorting and searching algorithms.

---

## 2. Comparison of Scheduling Algorithms

| Parameter | Greedy | Backtracking | Branch and Bound |
|---|---|---|---|
| Approach | Makes the best local choice | Explores possible assignments | Explores solutions using bounds |
| Decision Making | Immediate | Recursive | Based on current score and upper bound |
| Execution Speed | Generally fast | Can be slow | Depends on pruning |
| Search Space | Limited | Large | Reduced using pruning |
| Optimality | Not always guaranteed | Finds a feasible solution if one exists, subject to its constraints and complete search | Finds the best solution if its bound and search are correct |
| Complexity | Usually lower | Exponential in worst case | Exponential in worst case |
| Implementation | Simple | More complex | More complex |

---

## 3. Greedy Algorithm

### Advantages

- Easy to understand and implement.
- Generally provides quick results.
- Requires less computational effort.
- Suitable for making immediate scheduling decisions.

### Disadvantages

- Makes decisions based on local information.
- May not produce the globally best schedule.
- Earlier decisions may affect later surgery assignments.

### Application in Project

Greedy scheduling prioritizes surgeries based on their priority and assigns them to suitable available theatres.

Interval Partitioning also uses a greedy approach to allocate non-overlapping surgery intervals.

---

## 4. Backtracking Algorithm

### Advantages

- Explores different possible assignments.
- Can find a feasible solution when one exists within the defined constraints.
- Can undo incorrect decisions.
- Useful for problems involving multiple constraints.

### Disadvantages

- Can require significant execution time.
- Searches many possible combinations.
- Performance decreases as the number of surgeries and theatres increases.

### Application in Project

Backtracking tries different theatre assignments recursively and reverses an assignment when it leads to an invalid solution.

---

## 5. Branch and Bound Algorithm

### Advantages

- Uses bounds to eliminate unpromising solutions.
- Can reduce unnecessary searching.
- Useful for optimization problems.
- Can identify a high-priority feasible allocation.

### Disadvantages

- More difficult to implement than Greedy.
- Requires a suitable bounding function.
- Worst-case execution time can still be exponential.
- Performance depends on how effectively branches are pruned.

### Application in Project

Branch and Bound explores different theatre assignments and uses an upper bound on the possible priority score to avoid exploring branches that cannot improve the current best solution.

---

## 6. Comparison of Supporting Algorithms

| Algorithm | Main Purpose | Time Complexity |
|---|---|---|
| Merge Sort | Sort surgery records | O(n log n) |
| Binary Search | Search a surgery by ID | O(log n) |

### Merge Sort

Merge Sort is useful for sorting records efficiently. It follows the Divide and Conquer technique and maintains O(n log n) time complexity.

### Binary Search

Binary Search is useful for quickly locating a surgery in a collection sorted by ID. It reduces the search space by half at each step.

---

## 7. Which Algorithm Is More Suitable?

Different algorithms are suitable for different scheduling situations.

### Greedy

Suitable when:
- Quick scheduling decisions are required.
- Surgery priority is important.
- The problem can be handled using local decisions.

### Backtracking

Suitable when:
- Multiple theatre assignments must be explored.
- Scheduling constraints are important.
- A feasible allocation is required.

### Branch and Bound

Suitable when:
- A high-priority allocation is desired.
- Several possible assignments exist.
- Unpromising solutions can be eliminated using bounds.

---

## 8. Overall Comparison

Greedy algorithms are generally faster and simpler, but they do not guarantee the best overall scheduling solution.

Backtracking explores possible assignments and can find a feasible solution, but it may require considerable computation.

Branch and Bound uses upper bounds to reduce the search space and is useful when the goal is to find a high-scoring allocation.

Merge Sort and Binary Search support efficient data processing.

No single algorithm is best for every scheduling situation. The appropriate technique depends on the number of surgeries, available theatres, and scheduling constraints.

---

## 9. Conclusion

The comparison demonstrates the importance of selecting suitable algorithms for different computational problems.

Greedy, Backtracking, and Branch and Bound provide different approaches to surgery scheduling, while Merge Sort and Binary Search support sorting and searching operations.

The project demonstrates how algorithmic techniques can be applied to improve the organization and allocation of hospital operating theatre resources.
