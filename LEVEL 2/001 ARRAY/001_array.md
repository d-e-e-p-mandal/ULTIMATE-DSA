# Arrays in C, C++, and Java

## 1. What is an Array?
An **array** is a collection of elements of the same type stored in **contiguous memory locations**.  
- Each element is accessed using an **index** (starting from `0`).  
- Arrays allow **random access** to elements.  
- Supported in **C, C++, and Java** as one-dimensional, multi-dimensional, or dynamic arrays.

---

## 2. Initial Values of Arrays

### C/C++
- **Local arrays (inside a function):**
  - Not automatically initialized.
  - Contain **garbage values**.
  - Example:
    ```cpp
    void func() {
        int arr[5];   // uninitialized → garbage values
    }
    ```

- **Global or static arrays:**
  - Automatically initialized to `0` (for numeric types).
  - Example:
    ```cpp
    int arr[5];   // all values = 0
    ```

---

### Java
- Arrays are always **heap objects**.
- Default initialization:
  - `int[] arr = new int[5];` → all values = `0`
  - `boolean[] arr = new boolean[5];` → all values = `false`
  - `String[] arr = new String[5];` → all values = `null`

---

## 3. Maximum Size of Arrays

### C/C++
- **Local arrays (stack memory):**
  - Limited by **stack size** (usually **1 MB to 8 MB** depending on OS/compiler).
  - Example:  
    - `int arr[1000000];//1e6`

- **Global/static arrays (data segment):**
  - Much larger, limited by **system RAM and compiler settings**.
  - Can be **hundreds of MBs or more**.
  - Example:  
    -`int arr[10000000];//1e7`   

---
### Why global array has a larger size than the local array?

When an array is declared locally, then it always initializes in the stack memory, and generally, stack memory has a size limit of around 8 MB. This size can vary according to different computer architecture.
When an array is declared globally then it stores in the data segment, and the data segment has no size limit. Hence, when the array is declared of big size (i.e., more than 107) then the stack memory gets full and leads into the stack overflow error, and therefore, a segmentation fault error is encountered. Therefore, for declaring the array of larger size, it is good practice to declare it globally.

### Java
- Arrays are always stored on the **heap**.
- Maximum size depends on **available heap memory** and **JVM limits**:
  - Theoretical max length: `Integer.MAX_VALUE` (≈ 2,147,483,647 elements).
  - In practice, limited by **heap space** (few GBs).
  - Example:
    ```java
    int[] arr = new int[100000000]//Integer.MAX_VALUE// Integer.MAX_VALUE - 2(macos);   // works if JVM has enough memory
    ```

---

## 4. Summary Table

| Language        | Array Location      | Default Initialization | Max Size (Typical)       |
|-----------------|--------------------|-------------------------|---------------------------|
| **C/C++ (local)**   | Stack              | Garbage values          | ~1–8 MB (stack size)      |
| **C/C++ (global)**  | Data segment       | Zero-initialized        | Hundreds of MBs or more   |
| **Java**            | Heap               | Zero/false/null         | Up to `Integer.MAX_VALUE`, limited by heap |

---