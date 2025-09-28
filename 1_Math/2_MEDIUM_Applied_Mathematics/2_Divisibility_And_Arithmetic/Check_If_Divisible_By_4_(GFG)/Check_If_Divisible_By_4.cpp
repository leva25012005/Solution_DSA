#include <cmath> // log, fmod, pow
#include <iostream>
#include <numeric> // accumulate
#include <vector>  // vector

using namespace std;

class Solution {
public:
  // 1. Repeated Multiplication
  // Time: O(log_y), Space: O(1)
  bool isPower1(int x, int y) {
    if (x == 1)
      return (y == 1);
    long long val = 1;
    while (val < y) {
      val *= x;
      if (val == y)
        return true;
    }
    return false;
  }

  // 2. Repeated Division
  // Time: O(log_y), Space: O(1)
  bool isPower2(int x, int y) {
    if (x == 1)
      return (y == 1);
    while (y % x == 0) {
      y /= x;
    }
    return (y == 1);
  }

  // 3. Logarithm Method
  // Time: O(1), Space: O(1)
  bool isPower3(int x, int y) {
    if (x == 1)
      return (y == 1);
    double expVal = log(y) / log(x);
    return fabs(expVal - round(expVal)) < 1e-9;
  }

  // 4. Recursive Method
  // Time: O(log_y), Space: O(log_y) (stack)
  bool isPower4(int x, int y) {
    if (y == 1)
      return true;
    if (y < x || y % x != 0)
      return false;
    return isPower4(x, y / x);
  }

  // 5. Prime Factorization Approach
  // Time: O(sqrt(y)), Space: O(1)
  bool isPower5(int x, int y) {
    if (x == 1)
      return (y == 1);

    // Factorize y
    int num = y;
    for (int i = 2; i * i <= num; i++) {
      while (y % i == 0) {
        if (x % i != 0)
          return false;
        y /= i;
      }
    }
    if (y > 1 && x % y != 0)
      return false;
    return true;
  }

  // 6. Binary Exponentiation Search
  // Time: O(log_y), Space: O(1)
  bool isPower6(int x, int y) {
    if (x == 1)
      return (y == 1);
    long long val = 1;
    while (val < y) {
      val *= x;
      if (val == y)
        return true;
    }
    return false;
  }
};

int main() {
  Solution sol;
  int x = 2, y = 8;
  cout << boolalpha;
  cout << sol.isPower1(x, y) << "\n"; // true
  cout << sol.isPower2(x, y) << "\n"; // true
  cout << sol.isPower3(x, y) << "\n"; // true
  cout << sol.isPower4(x, y) << "\n"; // true
  cout << sol.isPower5(x, y) << "\n"; // true
  cout << sol.isPower6(x, y) << "\n"; // true
  return 0;
}
