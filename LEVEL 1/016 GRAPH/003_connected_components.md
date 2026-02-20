A **Connected Component** is a subset of a graph where all nodes are "reachable" from one another. Think of it as an isolated "island" of nodes within a larger network.

---

### 1️⃣ Undirected Graphs

In an undirected graph, a connected component is a maximal subgraph where there is a path between **any** two vertices.

* **Property:** If you start at any node in a component, you can reach every other node in that same component.
* **Isolation:** There are no edges connecting a node in one component to a node in another.

---

### 2️⃣ Directed Graphs

Since direction matters, we categorize components into two types:

* **Strongly Connected Component (SCC):** A subgraph where every vertex is reachable from every other vertex **following the directed edges**. (If you can go , there must be a way back ).
* **Weakly Connected Component:** A subgraph that becomes connected only if you **ignore the directions** of the arrows and treat them as simple lines.

---

### 3️⃣ Key Technical Facts

* **Counting Components:** To find the number of connected components, we use **DFS** or **BFS**. Every time we start a traversal on an "unvisited" node, it represents the discovery of a new component.
* **Disjoint Set Union (DSU):** This is the most efficient data structure for merging and counting components in dynamic graphs.
* **Time Complexity:** Finding all components takes  using DFS/BFS.

---

### 4️⃣ Interview Context (The "Number of Islands" Problem)

In interviews, this concept is often disguised. For example:

> *"Given a 2D grid of 1s (land) and 0s (water), count the number of islands."*

Each island is simply a **connected component** of the graph where the "1s" are the nodes.

