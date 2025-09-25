#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  // 1. Iterative Division
  // Time: O(log n), Space: O(1)
  bool isUglyIterative(int n) {
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
  bool isUglyRecursive(int n) {
    if (n <= 0)
      return false;
    if (n == 1)
      return true;
    if (n % 2 == 0)
      return isUglyRecursive(n / 2);
    if (n % 3 == 0)
      return isUglyRecursive(n / 3);
    if (n % 5 == 0)
      return isUglyRecursive(n / 5);
    return false;
  }

  // 3. Prime Factorization
  // Time: O(sqrt(n)), Space: O(1)
  bool isUglyFactorization(int n) {
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
  bool isUglyLogarithm(int n) {
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
  cout << sol.isUglyIterative(6) << "\n";      // true
  cout << sol.isUglyRecursive(1) << "\n";      // true
  cout << sol.isUglyFactorization(14) << "\n"; // false
  cout << sol.isUglyLogarithm(8) << "\n";      // true
  return 0;
}
