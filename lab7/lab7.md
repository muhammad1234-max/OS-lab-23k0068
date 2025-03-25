**Operating Systems Lab (CL 2006) - Lab 7 Solutions**

**Task 1: First-Come, First-Served (FCFS) Scheduling**

| Process | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time |
|---------|-------------|------------|-----------------|----------------|-------------|
| P1      | 0           | 6          | 6               | 6              | 0           |
| P2      | 2           | 8          | 14              | 12             | 4           |
| P3      | 4           | 7          | 21              | 17             | 10          |
| P4      | 6           | 3          | 24              | 18             | 15          |

**Average Waiting Time (AWT) = (0 + 4 + 10 + 15) / 4 = 7.25 ms**
**Average Turnaround Time (ATAT) = (6 + 12 + 17 + 18) / 4 = 13.25 ms**

---

**Task 2: Shortest Job First (SJF) – Non-Preemptive**

| Process | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time |
|---------|-------------|------------|-----------------|----------------|-------------|
| P1      | 1           | 5          | 6               | 5              | 0           |
| P2      | 3           | 2          | 8               | 5              | 3           |
| P4      | 6           | 4          | 12              | 6              | 2           |
| P3      | 5           | 9          | 21              | 16             | 7           |

**AWT = (0 + 3 + 7 + 2) / 4 = 3 ms**
**ATAT = (5 + 5 + 16 + 6) / 4 = 8 ms**

---

**Task 3: Shortest Remaining Time First (SRTF) – Preemptive SJF**

**Gantt Chart:**
P1 (0-1), P2 (1-5), P3 (5-12), P4 (12-14), P1 (14-18)

| Process | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time |
|---------|-------------|------------|-----------------|----------------|-------------|
| P1      | 0           | 9          | 18              | 18             | 9           |
| P2      | 1           | 4          | 5               | 4              | 0           |
| P3      | 2           | 7          | 12              | 10             | 3           |
| P4      | 3           | 2          | 14              | 11             | 9           |

**AWT = (9 + 0 + 3 + 9) / 4 = 5.25 ms**
**ATAT = (18 + 4 + 10 + 11) / 4 = 10.75 ms**

---

**Task 4: Round Robin (RR) Scheduling – Time Quantum = 3ms**

Gantt Chart: P1 (0-3), P2 (3-6), P3 (6-9), P4 (9-12), P1 (12-15), P2 (15-18), P3 (18-21), P1 (21-22), P3 (22-23)

**AWT = 6.75 ms, ATAT = 14.75 ms**

---

**Task 5: Round Robin (RR) Scheduling – Time Quantum = 2ms**

Gantt Chart: P1 (0-2), P2 (2-4), P3 (4-6), P4 (6-8), P1 (8-10), P2 (10-12), P3 (12-14), P1 (14-16), P3 (16-18), P1 (18-20)

**AWT = 7.5 ms, ATAT = 16 ms**

---

**Task 6: Priority Scheduling (Non-Preemptive)**

| Process | Arrival Time | Burst Time | Priority | Completion Time | Turnaround Time | Waiting Time |
|---------|-------------|------------|----------|-----------------|----------------|-------------|
| P2      | 1           | 4          | 1        | 5               | 4              | 0           |
| P3      | 2           | 6          | 2        | 11              | 9              | 3           |
| P1      | 0           | 7          | 3        | 18              | 18             | 11          |
| P4      | 3           | 5          | 4        | 23              | 20             | 15          |

**AWT = 7.25 ms, ATAT = 12.75 ms**

---

**Task 7: Priority Scheduling (Preemptive)**

Gantt Chart: P1 (0-1), P2 (1-4), P1 (4-6), P3 (6-7), P1 (7-8), P3 (8-9), P1 (9-10), P3 (10-11), P1 (11-12)

**AWT = 5.25 ms, ATAT = 10.75 ms**

