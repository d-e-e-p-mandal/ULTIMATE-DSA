// Move constructor is faster than copy constructor (for vector, string, pair with heavy objects).
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

    // v1 : Original Vector
    vector<string> v1 = {"Hello", "World", "C++"};

    cout << "Initial v1:\n";
    for (auto &s : v1) cout << s << " ";
    cout << "\n\n";


    // v2 : Copy Constructor
    vector<string> v2(v1);
    // Deep copy of all elements
    // Each string is copied
    // Time Complexity: O(n)
    // Extra Space Complexity: O(n)

    cout << "After Copy Constructor (v2 from v1):\n";
    for (auto &s : v2) cout << s << " ";
    cout << "\nv1 still unchanged:\n";
    for (auto &s : v1) cout << s << " ";
    cout << "\n\n";


    // Modify v1 to prove v2 is independent
    v1[0] = "Hi";

    cout << "After modifying v1[0] = \"Hi\":\n";
    cout << "v1: ";
    for (auto &s : v1) cout << s << " ";
    cout << "\nv2 (NOT affected): ";
    for (auto &s : v2) cout << s << " ";
    cout << "\n\n";


    // v3 : Move Constructor
    vector<string> v3(move(v1));
    // Internal pointer, size, capacity transferred
    // No element copying
    // Time Complexity: O(1)
    // Extra Space Complexity: O(1)

    cout << "After Move Constructor (v3 from v1):\n";
    cout << "v3: ";
    for (auto &s : v3) cout << s << " ";
    cout << "\nv1 size after move: " << v1.size() << "\n\n";


    // v4 : Move Assignment
    vector<string> v4;
    v4 = move(v2);
    // Move assignment operator
    // Transfers ownership from v2 to v4
    // Time Complexity: O(1)
    // Extra Space Complexity: O(1)

    cout << "After Move Assignment (v4 = move(v2)):\n";
    cout << "v4: ";
    for (auto &s : v4) cout << s << " ";
    cout << "\nv2 size after move: " << v2.size() << "\n\n";

    return 0;
}

/*
OVERALL COMPLEXITY ANALYSIS

Copy Constructor: Deep Copy
    Time  = O(n)
    Space = O(n)

Move Constructor: Shallow Copy
    Time  = O(1)
    Space = O(1)

Move Assignment: Shallow Copy
    Time  = O(1)
    Space = O(1)

*/