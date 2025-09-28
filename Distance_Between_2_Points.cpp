#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  // 1. Using sqrt + ceil
  // Time: O(1), Space: O(1)
  int distance1(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    return (int)ceil(sqrt(dx * dx + dy * dy));
  }

  // 2. Using hypot + ceil
  // Time: O(1), Space: O(1)
  int distance2(int x1, int y1, int x2, int y2) {
    return (int)ceil(hypot(x2 - x1, y2 - y1));
  }

  // 3. Using pow + sqrt + ceil
  // Time: O(1), Space: O(1)
  int distance3(int x1, int y1, int x2, int y2) {
    return (int)ceil(sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
  }

  // 4. Using long double for higher precision
  // Time: O(1), Space: O(1)
  int distance4(int x1, int y1, int x2, int y2) {
    long double dx = (long double)x2 - x1;
    long double dy = (long double)y2 - y1;
    return (int)ceil(sqrt(dx * dx + dy * dy));
  }
};

int main() {
  Solution sol;
  cout << sol.distance1(0, 0, 2, -2) << "\n";      // 3
  cout << sol.distance2(-20, 23, -15, 68) << "\n"; // 45
  cout << sol.distance3(1, 2, 4, 6) << "\n";       // 5
  cout << sol.distance4(-3, -4, 0, 0) << "\n";     // 5
  return 0;
}
