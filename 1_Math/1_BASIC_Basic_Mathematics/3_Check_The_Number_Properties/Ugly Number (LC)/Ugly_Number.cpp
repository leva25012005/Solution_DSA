#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  // 1. Iterative Division
  // Time: O(log n), Space: O(1)
  bool Solution1(int n) {
    if (n <= 0)
      return false;
    while (n % 2 == 0)
      n /= 2;
    while (n % 3 == 0)
      n /= 3;
    while (n % 5 == 0)
      n /= 5;
    return n == 1;
  }

  // 2. Recursive Division
  // Time: O(log n), Space: O(log n)  (stack depth)
  bool Solution2(int n) {
    if (n <= 0)
      return false;
    if (n == 1)
      return true;
    if (n % 2 == 0)
      return Solution2(n / 2);
    if (n % 3 == 0)
      return Solution2(n / 3);
    if (n % 5 == 0)
      return Solution2(n / 5);
    return false;
  }

  // 3. Prime Factorization
  // Time: O(sqrt(n)), Space: O(1)
  bool Solution3(int n) {
    if (n <= 0)
      return false;
    for (int p = 2; p * p <= n; p++) {
      while (n % p == 0) {
        if (p != 2 && p != 3 && p != 5)
          return false;
        n /= p;
      }
    }
    return (n == 1 || n == 2 || n == 3 || n == 5);
  }

  // 4. Logarithm Check (not practical, demo only)
  // Time: O(log n), Space: O(1)
  bool Solution4(int n) {
    if (n <= 0)
      return false;
    // Remove factors of 2, 3, 5
    while (n % 2 == 0)
      n /= 2;
    while (n % 3 == 0)
      n /= 3;
    while (n % 5 == 0)
      n /= 5;
    return n == 1;
  }
};

int main() {
  Solution sol;
  cout << boolalpha;
  cout << sol.Solution1(6) << "\n";  // true
  cout << sol.Solution2(1) << "\n";  // true
  cout << sol.Solution3(14) << "\n"; // false
  cout << sol.Solution4(8) << "\n";  // true
  return 0;
}
