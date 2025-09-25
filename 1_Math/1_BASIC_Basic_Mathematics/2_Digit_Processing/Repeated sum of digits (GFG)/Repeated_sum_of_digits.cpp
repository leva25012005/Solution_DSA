#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  // 1. Recursive approach
  // Time: O(log n), Space: O(log n)
  int Solution1(int n) {
    if (n < 10)
      return n;
    int sum = 0;
    while (n > 0) {
      sum += n % 10;
      n /= 10;
    }
    return Solution1(sum);
  }

  // 2. Iterative approach
  // Time: O(log n), Space: O(1)
  int Solution2(int n) {
    while (n >= 10) {
      int sum = 0;
      while (n > 0) {
        sum += n % 10;
        n /= 10;
      }
      n = sum;
    }
    return n;
  }

  // 3. Mathematical formula (digital root)
  // Time: O(1), Space: O(1)
  int Solution3(int n) {
    if (n == 0)
      return 0;
    return 1 + (n - 1) % 9;
  }

  // 4. String-based approach
  // Time: O(log n), Space: O(log n)
  int Solution4(int n) {
    while (n >= 10) {
      string s = to_string(n);
      int sum = 0;
      for (char c : s)
        sum += c - '0';
      n = sum;
    }
    return n;
  }
};

int main() {
  Solution sol;
  cout << sol.Solution1(1234) << "\n"; // 1
  cout << sol.Solution2(9999) << "\n"; // 9
  cout << sol.Solution3(1234) << "\n"; // 1
  cout << sol.Solution4(9999) << "\n"; // 9
  return 0;
}
