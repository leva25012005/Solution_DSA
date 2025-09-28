#include <algorithm>
#include <iostream>

using namespace std;

struct Point {
  int x, y;
};

class Solution {
public:
  // Method 1: Non-overlap conditions check
  // Time: O(1), Space: O(1)
  bool isOverlap1(Point L1, Point R1, Point L2, Point R2) {
    // One rectangle is to the left of the other
    if (R1.x < L2.x || R2.x < L1.x)
      return false;
    // One rectangle is above the other
    if (R1.y > L2.y || R2.y > L1.y)
      return false;
    return true;
  }

  // Method 2: Interval overlap check
  // Time: O(1), Space: O(1)
  bool isOverlap2(Point L1, Point R1, Point L2, Point R2) {
    bool overlapX = max(L1.x, L2.x) <= min(R1.x, R2.x);
    bool overlapY = max(R1.y, R2.y) <= min(L1.y, L2.y);
    return overlapX && overlapY;
  }

  // Method 3: Intersection area check
  // Time: O(1), Space: O(1)
  bool isOverlap3(Point L1, Point R1, Point L2, Point R2) {
    int width = min(R1.x, R2.x) - max(L1.x, L2.x);
    int height = min(L1.y, L2.y) - max(R1.y, R2.y);
    return (width >= 0 && height >= 0);
  }

  // Method 4: Separating Axis Theorem (simplified)
  // Time: O(1), Space: O(1)
  bool isOverlap4(Point L1, Point R1, Point L2, Point R2) {
    bool separateX = (R1.x < L2.x || R2.x < L1.x);
    bool separateY = (R1.y > L2.y || R2.y > L1.y);
    return !(separateX || separateY);
  }
};

int main() {
  Solution sol;
  Point L1 = {0, 10}, R1 = {10, 0};
  Point L2 = {5, 5}, R2 = {15, 0};

  cout << sol.isOverlap1(L1, R1, L2, R2) << endl; // 1
  cout << sol.isOverlap2(L1, R1, L2, R2) << endl; // 1
  cout << sol.isOverlap3(L1, R1, L2, R2) << endl; // 1
  cout << sol.isOverlap4(L1, R1, L2, R2) << endl; // 1

  return 0;
}
