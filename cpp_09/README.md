# C++ Module 09: Advanced STL & Algorithmic Optimization

## 📌 Overview
This repository contains a series of high-performance C++98 applications focused on advanced data structures, algorithmic complexity, and rigorous input validation. Developed as part of the rigorous software engineering curriculum at 1337 (42 Network), these projects demonstrate a deep understanding of the C++ Standard Template Library (STL), memory safety, and defensive programming.

**Core Technologies:** C++98, STL (`std::map`, `std::vector`, `std::deque`, `std::stack`), Template Metaprogramming, RAII.

---

## 🛠 Projects & Engineering Case Studies

### 1. Bitcoin Exchange (`btc`)
A time-series data parser and financial evaluation tool. It loads a historical exchange rate database and evaluates user-provided portfolios against chronological data.

* **Data Structures Used:** `std::map` (implemented as a Red-Black Tree for $O(\log N)$ search operations).
* **Engineering Challenge:** Efficiently querying financial data when exact chronological matches do not exist (e.g., querying a weekend date when markets were closed).
* **The Solution:** Rather than relying on computationally heavy iterative searches or error-prone conditional logic, I utilized `std::upper_bound` combined with iterator decrementation. This guarantees retrieving the "closest lower date" in logarithmic time, ensuring high performance even with massive datasets.
* **Edge Cases Handled:** * Implemented split-level data sanitization: aggressive string formatting and space-stripping for user input (`input.txt`), contrasted with strict, zero-tolerance validation for the core database (`data.csv`) to prevent silent data corruption.
    * Handled lexicographical sorting traps by enforcing strict ISO 8601 (`YYYY-MM-DD`) zero-padding prior to tree insertion.

### 2. Reverse Polish Notation (`RPN`)
A mathematical expression evaluator utilizing postfix notation automata.

* **Data Structures Used:** `std::stack`.
* **Engineering Challenge:** Preventing silent arithmetic failures and memory state corruption during complex sequence evaluations.
* **The Solution:** Built a robust defensive architecture that validates bounds pre-emptively. Instead of executing an operation and checking the result (which can trigger undefined behavior), the algorithm checks `INT_MAX` and `INT_MIN` boundaries *against the current stack operands* before allowing the CPU to perform the addition, subtraction, or multiplication.
* **Edge Cases Handled:** Division by zero, strict lexical tokenization, and stack operand-to-operator ratio validation.

### 3. PmergeMe (Ford-Johnson Algorithm)
A microsecond-precision implementation of the Merge-Insertion Sort algorithm, designed to sort generic containers with the absolute mathematical minimum number of comparisons.

* **Data Structures Used:** `std::vector` and `std::deque` (for performance benchmarking across contiguous vs. node-based memory architectures).
* **Engineering Challenge:** Minimizing function call overhead during recursive binary insertions of millions of elements.
* **The Solution:** * Generated Jacobsthal numbers to determine the optimal insertion sequence, delaying binary search boundaries to drastically reduce comparison counts.
    * Designed custom **Functors** (Function Objects) rather than standard function pointers for the binary search comparators. By passing types rather than addresses, I enabled the compiler to perform aggressive **inlining (monomorphization)**, completely eliminating indirect call overhead during the heavy binary search phase.
* **Edge Cases Handled:** Odd-numbered dataset "stragglers" during recursive pairing, and strict `size_t` compliance to prevent `-Wsign-compare` vulnerabilities.

---

## 🧠 Key Takeaways & Competencies

* **Algorithmic Efficiency:** Transitioned from basic sorting methods to complex $O(N \log N)$ architectures utilizing binary search trees and mathematical sequencing (Jacobsthal).
* **Compiler Optimization:** Leveraged template metaprogramming and Functors to guide the compiler toward optimal machine-code generation (inlining).
* **System Robustness:** Adhered to strict RAII principles, ensuring that all file descriptors and memory allocations are safely scoped, preventing leaks even during catastrophic exception unwinding.
* **Legacy Compliance:** Engineered modern, highly efficient solutions while strictly adhering to the legacy C++98 standard, demonstrating adaptability and deep language comprehension.
