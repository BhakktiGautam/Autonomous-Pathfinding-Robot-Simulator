#  Autonomous Pathfinding Robot Simulator

##  Overview
This project is a grid-based pathfinding simulator implemented in C.  
It demonstrates how a robot finds the shortest path from a start point to a goal point while avoiding obstacles using different algorithms.

---

##  Features
- Create customizable 2D grid
- Add obstacles manually
- Visual representation of:
  - Start (S)
  - Goal (G)
  - Obstacles (X)
  - Path (*)
- Implemented Algorithms:
  - Breadth-First Search (BFS)
  - Dijkstra’s Algorithm
  - A* (A-Star) Algorithm
- Compare performance of all algorithms

---

##  Algorithms Used

### 🔹 BFS (Breadth-First Search)
- Works for unweighted grids
- Guarantees shortest path
- Explores all nodes level by level

### 🔹 Dijkstra’s Algorithm
- Works for weighted graphs
- Uses distance array
- Finds optimal shortest path

### 🔹 A* Algorithm
- Uses heuristic (Manhattan Distance)
- Faster than Dijkstra
- Explores fewer nodes

---

##  Heuristic Used (A*)
Manhattan Distance:


h(x, y) = |x - gx| + |y - gy|


---

##  How to Run

1. Compile the program:

gcc filename.c -o pathfinder


2. Run the executable:

./pathfinder


---

##  Menu Options

Create Grid
Display Grid
Run BFS
Run Dijkstra
Run A*
Compare Algorithms
Exit

---

##  Sample Test Case

**Input:**

Grid Size: 5x5
Start: (0,0)
Goal: (4,4)
Obstacles:
(1,1), (1,2), (2,2), (3,1)


**Output:**
- Path shown using `*`
- Distance calculated
- Steps compared

---

##  Comparison Output


BFS -> Distance: X | Steps: Y
Dijkstra -> Distance: X | Steps: Y
A* -> Distance: X | Steps: Y


---

##  Practical Learning
- Implemented pathfinding algorithms in C
- Learned queue operations and grid traversal
- Understood heuristic optimization
- Debugged infinite loops and edge cases
- Compared algorithm efficiency

---

##  Limitations
- Works only on small grids (max 50x50)
- No diagonal movement
