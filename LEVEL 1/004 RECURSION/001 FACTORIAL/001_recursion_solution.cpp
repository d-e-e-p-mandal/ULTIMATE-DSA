#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int static factorial(int n) {
        if(n == 0 || n == 1) return 1;
        return n * factorial(n-1);
    }
};

int main() {
    Solution sol;
    int n;
    cin >>n;
    cout<<Solution ::factorial(n)<<endl;

    return 0;
}