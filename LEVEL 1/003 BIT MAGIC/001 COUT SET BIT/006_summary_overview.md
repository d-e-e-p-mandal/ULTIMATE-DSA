# Summary — Methods to Count Set Bits (1s) in an Integer

| **Method**         | **Logic**                        | **Time Complexity** | **Space Complexity** | **Best For**                    |
|--------------------|----------------------------------|---------------------|----------------------|----------------------------------|
| **Simple Loop**    | Shift & check each bit           | O(log n)            | O(1)                 | Learning basics                 |
| **Brian Kernighan**| Remove one `1`-bit each time     | O(k)                | O(1)                 | Faster counting                 |
| **Lookup Table**   | Precompute 8-bit results         | O(1) (after setup)  | O(256)               | Fast repeated calls             |
| **SWAR / Parallel**| Group & add bits via masks       | O(1)                | O(1)                 | Optimized, loop-free operations |
| **Built-in Popcount**| Hardware-level POPCNT support | O(1)                | O(1)                 | Best real-world performance     |

---

### 🧠 Overview

1. **Simple Loop** — Easiest to understand, iterates through every bit using shifting and masking.  
2. **Brian Kernighan’s Algorithm** — Efficient when the number has **few set bits**; removes one set bit per iteration.  
3. **Lookup Table Method** — Precomputes the bit count for all 8-bit numbers and adds results of each byte; extremely fast for **multiple queries**.  
4. **SWAR (Parallel Counting)** — Counts bits using **bitwise masks and additions**; no loops required; uses parallel computation within a register.  
5. **Built-in Function (`__builtin_popcount`)** — Leverages **CPU’s hardware POPCNT** instruction; fastest and simplest in real-world applications.

---

✅ **Key Takeaway:**  
All methods ultimately count the number of 1s in binary form, but their efficiency varies.  
For learning — start with the **Simple Loop**; for performance — use **Built-in Popcount**.