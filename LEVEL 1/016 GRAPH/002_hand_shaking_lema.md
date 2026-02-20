# Handshaking Theorem in Graph Theory

## 1. Statement of the Theorem
The **Handshaking Theorem** states:

👉 In any **undirected graph**, the sum of the degrees of all vertices is **twice the number of edges**.

Mathematically:
\[
\sum_{v \in V} deg(v) = 2|E|
\]

---

## 2. Intuition (Why it is called Handshaking)
- Imagine people standing in a room, each handshake = one edge between two people.
- Every time a handshake occurs, **two people’s hand counts increase by 1**.
- Therefore, if you add up all the hand counts (degrees), it will always be **2 × number of handshakes (edges)**.

---

## 3. Proof of the Theorem
- Each edge in an **undirected graph** connects **two vertices**.
- When counting degrees:
  - Each edge contributes **1** to the degree of each endpoint.
  - So, each edge contributes **2** in total.
- Therefore:
  \[
  \sum_{v \in V} deg(v) = 2|E|
  \]

---

## 4. Corollaries (Consequences)
1. **Even Sum of Degrees**  
   Since the sum of all degrees = `2|E|` (an even number),  
   the sum of degrees of all vertices in an undirected graph is **always even**.

2. **Even Number of Odd Degree Vertices**  
   In any graph, the number of vertices with odd degree is **always even**.  
   - Reason: If total sum of degrees is even, then odd-degree vertices must occur in pairs.

---

## 5. Example

### Example Graph:

```diff
A –– B
|   / |
|  /  |
C –– D
```

- Degrees:  
  - deg(A) = 2  
  - deg(B) = 3  
  - deg(C) = 3  
  - deg(D) = 2  

- Sum of degrees = 2 + 3 + 3 + 2 = **10**  
- Number of edges = 5  

**Check:**  
\[
\sum deg(v) = 10 = 2 × 5 = 2|E|
\] ✅

---

## 6. Handshaking Theorem for Directed Graphs
- In a **directed graph**, each edge contributes:
  - **1 to in-degree** of a vertex  
  - **1 to out-degree** of another vertex  

Thus:
\[
\sum_{v \in V} deg^-(v) = \sum_{v \in V} deg^+(v) = |E|
\]

Meaning:
- Total in-degree = Total out-degree = Number of edges.

---

## 7. Real-Life Applications
- **Social networks:** Total number of friend connections counted by summing all users’ friends = 2 × number of friendships.  
- **Handshake problem:** If 10 people shake hands, each handshake counted twice → total degree = 20.  
- **Network analysis:** Used in traffic, communication, and flow problems.

---