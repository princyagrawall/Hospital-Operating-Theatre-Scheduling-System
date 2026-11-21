
# Test Cases

## 1. Introduction

Software testing is performed to verify that the Hospital Operating Theatre Scheduling System works correctly under different conditions.

The purpose of testing is to identify errors, validate scheduling operations, and ensure that the implemented algorithms produce valid results.

This document describes the test cases used to evaluate the system.

---

## 2. Functional Test Cases

| Test ID | Test Scenario | Expected Result |
|---|---|---|
| TC01 | Add a valid surgery | Surgery should be added successfully |
| TC02 | Add a valid surgeon | Surgeon should be added successfully |
| TC03 | Add a valid operating theatre | Theatre should be added successfully |
| TC04 | Add valid equipment | Equipment should be added successfully |
| TC05 | Display surgery records | All stored surgeries should be displayed |
| TC06 | Display surgeon records | All stored surgeons should be displayed |
| TC07 | Display theatre records | All stored theatres should be displayed |
| TC08 | Display equipment records | All stored equipment should be displayed |
| TC09 | Enter invalid surgery details | Validation error should be displayed |
| TC10 | Generate surgery schedule | Scheduling algorithm should execute |
| TC11 | Calculate theatre utilization | Utilization should be displayed |
| TC12 | Exit application | Application should terminate |

---

## 3. Scheduling Algorithm Test Cases

| Test ID | Test Scenario | Expected Result |
|---|---|---|
| TC13 | Schedule surgeries with different priorities | Higher-priority surgeries should be considered first |
| TC14 | Schedule non-overlapping surgeries | Surgeries should be allocated without unnecessary conflicts |
| TC15 | Schedule overlapping surgeries | Overlapping surgeries should not use the same theatre |
| TC16 | Theatre has insufficient capacity | Surgery should not be assigned to that theatre |
| TC17 | No theatre is available | Surgery should remain unscheduled |
| TC18 | Multiple theatres are available | Suitable theatres should be considered |
| TC19 | Backtracking with a feasible allocation | A valid allocation should be found |
| TC20 | Backtracking with no feasible allocation | Algorithm should report that allocation is not possible |
| TC21 | Branch and Bound with multiple possible allocations | A high-priority feasible allocation should be selected |

---

## 4. Sorting and Searching Test Cases

| Test ID | Test Scenario | Expected Result |
|---|---|---|
| TC22 | Sort surgery records using Merge Sort | Records should be sorted correctly |
| TC23 | Search for an existing surgery ID | Correct surgery should be found |
| TC24 | Search for a non-existing surgery ID | Surgery not found message should appear |
| TC25 | Search in a sorted collection | Binary Search should return the correct position |

---

## 5. Edge Case Testing

| Test ID | Test Scenario | Expected Result |
|---|---|---|
| TC26 | Empty surgery list | No scheduling should occur |
| TC27 | Empty theatre list | No surgery should be allocated |
| TC28 | Only one surgery is available | Surgery should be considered for allocation |
| TC29 | Only one theatre is available | Allocation should respect theatre availability |
| TC30 | Two surgeries have the same start time | Scheduling conflicts should be checked |
| TC31 | Surgery duration is zero or negative | Invalid duration should be rejected |
| TC32 | Maximum number of surgeries is reached | Additional surgery should not be added |

---

## 6. Test Result Record

The following table can be updated after executing the test cases.

| Test Category | Total Test Cases | Passed | Failed |
|---|---:|---:|---:|
| Functional Testing | 12 | Pending | Pending |
| Scheduling Testing | 9 | Pending | Pending |
| Sorting and Searching | 4 | Pending | Pending |
| Edge Case Testing | 7 | Pending | Pending |

**Note:** Update the test results after actually executing the corresponding tests.

---

## 7. Conclusion

Testing helps verify the correctness and reliability of the Hospital Operating Theatre Scheduling System.

Functional testing checks the main application features, scheduling tests evaluate the implemented algorithms, and edge case testing checks the system under unusual conditions.

The test cases help identify errors and ensure that the application behaves as expected for different hospital scheduling situations.
