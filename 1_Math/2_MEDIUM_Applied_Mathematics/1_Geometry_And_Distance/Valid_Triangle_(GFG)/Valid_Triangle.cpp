#include <algorithm> // for sort, max
#include <cmath>     // for abs
#include <iostream>


using namespace std;

class Solution {
public:
  // Solution 1: Direct check with 3 conditions
  // Time: O(1), Space: O(1)
  bool isValidTriangle1(int a, int b, int c) {
    return (a + b > c && a + c > b && b + c > a);
  }

  // Solution 2: Sort sides, then check only one condition
  // Time: O(1), Space: O(1)
  bool isValidTriangle2(int a, int b, int c) {
    int sides[3] = {a, b, c};
    sort(sides, sides + 3);
    return (sides[0] + sides[1] > sides[2]);
  }

  // Solution 3: Use max side and compare with sum of other two
  // Time: O(1), Space: O(1)
  bool isValidTriangle3(int a, int b, int c) {
    int maxSide = max(a, max(b, c));
    int sumOthers = a + b + c - maxSide;
    return (sumOthers > maxSide);
  }

  // Solution 4: Use triangle inequality with absolute differences
  // Time: O(1), Space: O(1)
  bool isValidTriangle4(int a, int b, int c) {
    return (abs(a - b) < c && c < a + b) && (abs(a - c) < b && b < a + c) &&
           (abs(b - c) < a && a < b + c);
  }
};

int main() {
  Solution sol;

  cout << boolalpha;
  cout << sol.isValidTriangle1(8, 15, 17) << "\n"; // true
  cout << sol.isValidTriangle2(3, 6, 9) << "\n";   // false
  cout << sol.isValidTriangle3(7, 10, 12) << "\n"; // true
  cout << sol.isValidTriangle4(5, 1, 1) << "\n";   // false

  return 0;
}
