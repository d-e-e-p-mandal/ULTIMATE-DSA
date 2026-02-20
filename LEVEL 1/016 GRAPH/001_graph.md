Think of a **Graph** as a social network. You have **people** (nodes) and **friendships** (edges) connecting them. Unlike a Tree, which has a strict "parent-child" hierarchy, a Graph is a "choose your own adventure" structure where anything can be connected to anything.

---

## 1. Key Terminology

To speak "Graph," you need these three terms:

* **Vertex (Node):** A data point (like a city or a person).
* **Edge:** The line connecting two vertices (like a road or a follow).
* **Weight:** A value assigned to an edge (like the distance between cities or the cost of a flight).

---

## 2. Common Graph Types

Graphs come in different "flavors" depending on how the edges behave:

* **Directed vs. Undirected:** * *Undirected:* A two-way street (Facebook friends).
* *Directed:* A one-way street (Twitter/Instagram followers).


* **Weighted vs. Unweighted:** * *Weighted:* The connection has a "cost" or "distance."
* *Unweighted:* All connections are equal.


* **Cyclic vs. Acyclic:**
* *Cyclic:* You can follow a path and end up back where you started.
* *Acyclic:* No loops possible (like a family tree).



---

## 3. How to Represent a Graph in Code

Computers don't "see" pictures, so we use two main math/data structures to store them:

| Method | Description | Best For... |
| --- | --- | --- |
| **Adjacency Matrix** | A 2D grid (table) of 0s and 1s. | Small graphs or checking if an edge exists quickly. |
| **Adjacency List** | An array of lists. Each node has a list of its neighbors. | Large, "sparse" graphs (most real-world data). |

---

## 4. How to Traverse (Search) a Graph

There are two "gold standard" ways to move through a graph:

### Breadth-First Search (BFS)

* **The Vibe:** Explore in "layers." Check all your immediate neighbors first, then their neighbors.
* **Tool:** Uses a **Queue** (FIFO).
* **Best for:** Finding the **shortest path** in an unweighted graph.

### Depth-First Search (DFS)

* **The Vibe:** Pick a path and go as deep as possible until you hit a dead end, then backtrack.
* **Tool:** Uses a **Stack** (or Recursion).
* **Best for:** Exploring every corner, solving puzzles (like mazes), or detecting cycles.

---

## 5. Real-World Uses

* **Google Maps:** Finding the shortest route (Dijkstra’s Algorithm).
* **Social Media:** "People you may know" suggestions.
* **Web Crawlers:** How Google finds new websites by following links.
* **Product Recommendations:** "Customers who bought this also bought..."

---



# Graph Theory Notes

## 1. Graph
```diff
A –– B
|   /|
|  / |
C –– D
```
A **graph** is a mathematical structure used to model pairwise relations between objects.  
It consists of:
- A set of **vertices (nodes)**.
- A set of **edges (connections)** that link pairs of vertices.

Formally, a graph `G` is defined as:  
**G = (V, E)**  
where:
- `V` = set of vertices (non-empty).
- `E` = set of edges.

---

## 2. Vertex (Node)
- A **vertex** is a fundamental unit of a graph, representing an object or entity.  
- Plural: **vertices**.  
- Example: In a social network graph, each person is a vertex.
- Vertices: `{A, B, C, D}`
---

## 3. Edge (Link)
- An **edge** is a connection between two vertices.  
- It represents the relationship or path between two vertices.  
- Example: In a road map, an edge represents a road connecting two cities.
- Edges: `{(A, B), (A, C), (B, C), (B, D), (C, D)}`
---

## 4. Adjacent Vertices
- Two vertices are **adjacent** if there is an edge connecting them.  
- Example: If edge `(A, B)` exists, then `A` and `B` are adjacent vertices.

---

## 5. Adjacent Edges
- Two edges are **adjacent** if they share a common vertex.  
- Example: If edges `(A, B)` and `(B, C)` exist, they are adjacent because both touch vertex `B`.

---

## 6. Directed Graph (Digraph)
- A **directed graph** is a graph where edges have a direction.  
- An edge from `A → B` means a one-way connection from `A` to `B`.  
- Order of vertices in an edge matters: `(A, B) ≠ (B, A)`.

---

## 7. Undirected Graph
- An **undirected graph** is a graph where edges have no direction.  
- An edge between `A` and `B` is the same as between `B` and `A`.  
- Order of vertices in an edge does not matter: `(A, B) = (B, A)`.

---

## 8. Self Loop
- A **self loop** is an edge that connects a vertex to itself.  
- Example: Edge `(A, A)`.

---

## 9. Multi Edges
- **Multi edges** (or parallel edges) are two or more edges connecting the same pair of vertices.  
- Example: Two different roads (edges) connecting the same cities (vertices).

---

## 10. Pseudograph
- A **pseudograph** is a graph that allows:
  - **Self loops**
  - **Multiple edges** between the same vertices.  

---

## 11. Multigraph
- A **multigraph** is a graph that allows **multiple edges** between the same pair of vertices.  
- **Self loops may or may not be allowed** depending on definition.

---

## 12. Simple Graph
- A **simple graph** is a graph that:
  - Does **not allow self loops**.
  - Does **not allow multiple edges**.
- Only one edge can exist between two distinct vertices.

---



# Degree of a Graph

## 1. Degree of a Vertex
The **degree** of a vertex is the number of edges incident (connected) to that vertex.

- **Undirected Graph:**
  - Degree of vertex `v` = Number of edges connected to `v`.
  - A **self loop** at a vertex contributes **2** to its degree (since it touches the vertex twice).
  - Notation: `deg(v)`.

- **Directed Graph:**
  - **In-degree (`deg⁻(v)`):** Number of edges coming **into** the vertex `v`.
  - **Out-degree (`deg⁺(v)`):** Number of edges going **out** from the vertex `v`.
  - Total degree of a vertex = `in-degree + out-degree`.

---

## 2. Handshaking Lemma
- In an **undirected graph**, the sum of the degrees of all vertices = **2 × number of edges**.
  - Formula:  
    \[
    \sum_{v \in V} deg(v) = 2|E|
    \]

- In a **directed graph**, the sum of in-degrees = sum of out-degrees = number of edges.  
  - Formula:  
    \[
    \sum_{v \in V} deg^-(v) = \sum_{v \in V} deg^+(v) = |E|
    \]

---

## 3. How to Calculate Degree

### Example 1: Undirected Graph
```diff
A –– B
|   /|
|  / |
C –– D
```

- deg(A) = 2  (edges: A–B, A–C)  
- deg(B) = 3  (edges: A–B, B–C, B–D)  
- deg(C) = 3  (edges: A–C, B–C, C–D)  
- deg(D) = 2  (edges: B–D, C–D)  

**Check with Handshaking Lemma:**  
Sum of degrees = 2 + 3 + 3 + 2 = 10 = 2 × 5 edges ✅

---

### Example 2: Directed Graph
```diff
A → B → C
↑       ↓
└───────D
```
- In-degree & Out-degree:  
  - A: in = 1 (D→A), out = 1 (A→B) → total = 2  
  - B: in = 1 (A→B), out = 1 (B→C) → total = 2  
  - C: in = 1 (B→C), out = 1 (C→D) → total = 2  
  - D: in = 1 (C→D), out = 1 (D→A) → total = 2  

**Check:**  
Sum of in-degrees = 4 = |E|  
Sum of out-degrees = 4 = |E| ✅

---
---



## 📘 DSA – Graph Chapter (Complete Guide for You 🚀)

Since you are strong in DSA and currently in MCA 3rd semester, let’s structure this chapter properly — interview + placement focused.

---

### 1️⃣ What is a Graph?

A Graph is a non-linear data structure consisting of:

* **Vertices** (Nodes)
* **Edges** (Connections)

It is written as:


Where:

*  = set of vertices
*  = set of edges

---

### 2️⃣ Types of Graphs

**🔹 1. Undirected Graph**

* Edges have no direction.
* If A is connected to B  B is also connected to A.

**Example:** `A — B`

**🔹 2. Directed Graph (Digraph)**

* Edges have direction.
* A  B does NOT mean B  A.

**🔹 3. Weighted Graph**

* Each edge has a weight (cost/distance).

**🔹 4. Cyclic vs Acyclic Graph**

* **Cyclic:** Contains at least one cycle.
* **Acyclic:** No cycles present.

**Special case:**

* **DAG** = Directed Acyclic Graph.

---

### 3️⃣ Graph Representation

Very important for coding 🔥

**🔸 1. Adjacency Matrix**

|  | 0 | 1 | 2 |
| --- | --- | --- | --- |
| **0** | 0 | 1 | 1 |
| **1** | 1 | 0 | 0 |
| **2** | 1 | 0 | 0 |

* **Space:** 
* **Good for:** Dense graphs.

**🔸 2. Adjacency List**

* 0  1  2
* 1  0
* 2  0
* **Space:** 
* **Good for:** Sparse graphs (standard for interview coding).

---

### 4️⃣ Graph Traversal Algorithms

---

**🔥 1. BFS (Breadth First Search)**

* Uses **Queue**.
* Level order traversal.
* **Used in:**
* Shortest path (unweighted graph).
* Cycle detection.
* Bipartite check.



**Time Complexity:** 

---

**🔥 2. DFS (Depth First Search)**

* Uses **Recursion / Stack**.
* Goes deep first.
* **Used in:**
* Cycle detection.
* Topological sort.
* Connected components.
* Bridges & Articulation points.



**Time Complexity:** 

---

### 5️⃣ Important Graph Algorithms (Interview Must)

---

**✅ 1. Cycle Detection**

* **Undirected:** DFS / BFS.
* **Directed:** DFS + Recursion stack.

**✅ 2. Topological Sort**

* Only for **DAG**.
* **Methods:**
* DFS.
* Kahn’s Algorithm (BFS).



**✅ 3. Shortest Path Algorithms**

| Algorithm | Works For | Time |
| --- | --- | --- |
| **BFS** | Unweighted graph |  |
| **Dijkstra** | Positive weights |  |
| **Bellman-Ford** | Negative weights allowed |  |
| **Floyd Warshall** | All pair shortest path |  |

**✅ 4. Minimum Spanning Tree (MST)**

* Prim’s Algorithm.
* Kruskal’s Algorithm.

**✅ 5. Disjoint Set (Union Find)**

* **Used in:** Cycle detection, Kruskal’s algorithm.

---

### 6️⃣ Very Important Interview Problems

You MUST master these:

1. Number of islands.
2. Detect cycle in graph.
3. Topological sort.
4. Shortest path.
5. Bipartite graph.
6. Clone graph.
7. Bridges and articulation point.

---

### 7️⃣ Complexity Summary

| Operation | Complexity |
| --- | --- |
| **BFS** |  |
| **DFS** |  |
| **Matrix Space** |  |
| **List Space** |  |

---