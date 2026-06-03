<!---LeetCode Topics Start-->
# LeetCode Topics
## Graphs
Type 1: Traversal Problems

Keywords:

Visit all
Reach
Explore
Connected
Component
Spread
Infection
Flood

Questions:

Number of islands
Flood fill
Rotten oranges
Connected components
Friend circles

Think:

👉 "Can I start somewhere and keep visiting neighbors?"

Use:

DFS
BFS

Type 3: Reachability Problems

Keywords:

Can reach?
Possible?
Exists a path?
Connected?

Examples:

Path exists
Valid path
Can escape maze

Think:

👉 "Need YES/NO"

Use:

DFS
BFS
Type 4: Connected Components

Keywords:

Number of groups
Number of clusters
Provinces
Communities

Examples:

Number of Provinces
Friend circles
Connected network

Think:

👉 "How many independent graphs exist?"

Use:

DFS
BFS
DSU

Type 10: Grid Problems

Keywords:

Matrix
Land water
Maze
Cell movement

Examples:

Number of Islands
Rotten Oranges
Surrounded Regions

Think:

👉 Every cell = node

Edge:

Up
Down
Left
Right

Use:

BFS
DFS
Type 11: Multi-Source BFS

Keywords:

Spread
Infection
Fire
Nearest source

Examples:

Rotten Oranges
Walls and Gates
01 Matrix

Think:

👉 Start BFS from many nodes simultaneously

Use:

Multi-source BFS

#

Type 2: Shortest Path Problems

Keywords:

Minimum distance
Fewest moves
Fastest route
Cheapest path
Smallest cost

Examples:

Network Delay Time
Maze shortest path
Flight routes
Road map

Think:

👉 "Need minimum cost from A to B"

Use:

BFS (unweighted)
Dijkstra
Bellman-Ford
Floyd Warshall

Type 5: Cycle Detection

Keywords:

Circular dependency
Loop
Deadlock
Infinite path

Examples:

Detect cycle in graph
Course Schedule

Think:

👉 "Can we come back to a node?"

Use:

Undirected
DFS
BFS
DSU
Directed
DFS recursion stack
Kahn's Algorithm
Type 6: Topological Ordering

Keywords:

Dependency
Before after
Ordering
Schedule

Examples:

Course Schedule II
Build System
Task Scheduling

Think:

👉 "A must happen before B"

Use:

Topological Sort
Kahn's Algorithm
Type 7: Minimum Spanning Tree

Keywords:

Connect all nodes
Minimum cost
Build network
Lay cables

Examples:

Connecting cities
Network design

Think:

👉 "Connect everyone cheaply"

Use:

Kruskal
Prim
Type 8: Union-Find / DSU Problems

Keywords:

Merge groups
Dynamic connectivity
Components changing

Examples:

Number of islands II
Redundant Connection
Accounts Merge

Think:

👉 "Groups keep joining"

Use:

DSU
Type 9: Bipartite Graph Problems

Keywords:

Two groups
Divide into teams
No enemies together

Examples:

Possible Bipartition
Graph Coloring

Think:

👉 "Can graph be colored using 2 colors?"

Use:

BFS Coloring
DFS Coloring
Type 12: Weighted Graph

Keywords:

Cost
Time
Distance
Fuel
Price

Example:

A → B costs 5

Think:

👉 Edges have weights

Use:

Dijkstra
Bellman Ford
Floyd Warshall
Type 13: DAG DP

Keywords:

Longest path
Count paths
Ways to reach

Examples:

Paths in DAG
Course schedule variations

Think:

👉 DP on topological order

Use:

Topological Sort + DP
Type 14: State Graph Problems

Most interview candidates miss this.

Keywords:

Minimum operations
Transform
Convert
Change state

Examples:

Word Ladder
Open Lock
Genetic Mutation

Think:

Node = State

Edge = Valid operation

Use:

BFS
Type 15: Graph + Bitmask

Keywords:

Visit all nodes
TSP
Hamiltonian

Examples:

Shortest Path Visiting All Nodes
Travelling Salesman

Think:

State:

(node, visited_mask)

Use:

BFS + Bitmask
DP + Bitmask
Type 16: Strongly Connected Components

Keywords:

Mutual reachability
Groups where everyone can reach everyone

Examples:

SCC problems
Condensation graph

Use:

Kosaraju
Tarjan
Type 17: Bridges & Articulation Points

Keywords:

Critical connection
Critical router
Single point of failure

Examples:

Critical Connections in Network

Use:

Tarjan Algorithm
Type 18: Maximum Flow

Keywords:

Maximum transfer
Capacity
Pipeline
Traffic

Examples:

Network Flow
Bipartite Matching

Use:

Ford Fulkerson
Edmonds Karp
Dinic
Type 19: Graph Coloring

Keywords:

Assign colors
Assign frequencies
Conflict constraints

Examples:

M Coloring Problem

Use:

Backtracking
Bipartite Coloring
Type 20: Euler Path / Circuit

Keywords:

Use every edge exactly once

Examples:

Reconstruct Itinerary
Postman Route

Use:

Hierholzer Algorithm
Fast Interview Recognition Rules
If you see:
"minimum moves"

→ BFS

"minimum cost"

→ Dijkstra

"dependency"

→ Topological Sort

"groups"

→ DSU / Connected Components

"spread"

→ Multi-source BFS

"grid"

→ BFS / DFS

"critical connection"

→ Bridges

"visit all"

→ Bitmask Graph

"can divide into 2 groups"

→ Bipartite

"connect all with minimum cost"

→ MST

Ultimate Decision Tree
Problem

├── Grid?
│      ├─ Count regions → DFS/BFS
│      ├─ Shortest path → BFS
│      └─ Weighted → Dijkstra
│
├── Dependency?
│      └─ Topological Sort
│
├── Shortest path?
│      ├─ Unweighted → BFS
│      ├─ Positive weights → Dijkstra
│      └─ Negative weights → Bellman Ford
│
├── Components?
│      ├─ Static → DFS/BFS
│      └─ Dynamic → DSU
│
├── Cycles?
│      ├─ Undirected → DFS/DSU
│      └─ Directed → DFS/Kahn
│
├── Connect all cheaply?
│      └─ MST
│
├── Visit all nodes?
│      └─ Bitmask DP
│
└── Critical nodes/edges?
       └─ Tarjan
