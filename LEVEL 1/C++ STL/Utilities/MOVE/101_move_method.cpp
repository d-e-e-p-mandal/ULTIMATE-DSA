// Move constructor is faster than copy constructor (for vector, string, pair with heavy objects).
#include <iostream>
#include <utility>
#include <string>
using namespace std;

int main() {

    // p1 : Original Pair
    pair<string, string> p1 = {"Hello", "World"};

    cout << "Initial p1:\n";
    cout << "p1: " << p1.first << " " << p1.second << "\n\n";


    // p2 : Copy Constructor
    pair<string, string> p2(p1);
    // Deep copy happens
    // New memory allocated for both strings
    // Time Complexity: O(n)
    // Extra Space Complexity: O(n)

    cout << "After Copy Constructor (p2 from p1):\n";
    cout << "p2: " << p2.first << " " << p2.second << "\n";
    cout << "p1 still unchanged: " << p1.first << " " << p1.second << "\n\n";


    // Modify p1 to prove p2 is independent
    p1.first = "Hi";

    cout << "After modifying p1.first = \"Hi\":\n";
    cout << "p1: " << p1.first << " " << p1.second << "\n";
    cout << "p2 (NOT affected): " << p2.first << " " << p2.second << "\n\n";


    // p3 : Move Constructor

    pair<string, string> p3(move(p1));
    // Move constructor called
    // Internal string buffers transferred
    // No deep copy
    // Time Complexity: O(1)
    // Extra Space Complexity: O(1)

    cout << "After Move Constructor (p3 from p1):\n";
    cout << "p3: " << p3.first << " " << p3.second << "\n";
    cout << "p1 after move: (changed)"
         << "\"" << p1.first << "\" "
         << "\"" << p1.second << "\"\n\n";


    // p4 : Move Assignment

    pair<string, string> p4;
    p4 = move(p2);
    // Move assignment operator called
    // Transfers ownership from p2 to p4
    // Time Complexity: O(1)
    // Extra Space Complexity: O(1)

    cout << "After Move Assignment (p4 = move(p2)):\n";
    cout << "p4: " << p4.first << " " << p4.second << "\n";
    cout << "p2 after move: (changed)"
         << "\"" << p2.first << "\" "
         << "\"" << p2.second << "\"\n\n";

    return 0;
}

/*
OVERALL COMPLEXITY ANALYSIS

Let n = length of original strings.

Copy Constructor  →  O(n) time, O(n) extra space
Move Constructor  →  O(1) time, O(1) extra space
Move Assignment   →  O(1) time, O(1) extra space

Key Concept:
Copy duplicates memory.
Move transfers ownership (pointer swap).
*/