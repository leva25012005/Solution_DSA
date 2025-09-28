#include <cmath> // for log, fmod
#include <iostream>

using namespace std;

class Solution {
public:
  // 1. Division Loop
  // Time: O(log_y), Space: O(1)
  bool isPowerOfX_Division(int x, int y) {
    if (x == 1)
      return (y == 1);
    while (y % x == 0) {
      y /= x;
    }
    return (y == 1);
  }

  // 2. Logarithm Method
  // Time: O(1), Space: O(1)
  bool isPowerOfX_Log(int x, int y) {
    if (x == 1)
      return (y == 1);
    double val = log(y) / log(x);
    return fabs(val - round(val)) < 1e-9;
  }

  // 3. Recursive Method
  // Time: O(log_y), Space: O(log_y) (stack space)
  bool isPowerOfX_Recursion(int x, int y) {
    if (y == 1)
      return true;
    if (y % x != 0 || x == 1)
      return false;
    return isPowerOfX_Recursion(x, y / x);
  }
};

int main() {
  Solution sol;
  cout << boolalpha;

  // Test cases
  cout << sol.isPowerOfX_Division(2, 8) << "\n";  // true
  cout << sol.isPowerOfX_Log(2, 8) << "\n";       // true
  cout << sol.isPowerOfX_Recursion(2, 8) << "\n"; // true

  cout << sol.isPowerOfX_Division(1, 8) << "\n";  // false
  cout << sol.isPowerOfX_Log(1, 1) << "\n";       // true
  cout << sol.isPowerOfX_Recursion(3, 9) << "\n"; // true

  return 0;
}
