#include <cmath>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
  // 1. Brute force approach
  // Time: O(n), Space: O(1)
  bool Solution1(int num) {
    if (num <= 1)
      return false;
    int sum = 0;
    for (int i = 1; i < num; i++) {
      if (num % i == 0)
        sum += i;
    }
    return sum == num;
  }

  // 2. Optimized divisor check (sqrt approach)
  // Time: O(sqrt(n)), Space: O(1)
  bool Solution2(int num) {
    if (num <= 1)
      return false;
    int sum = 1;
    int root = (int)sqrt(num);
    for (int i = 2; i <= root; i++) {
      if (num % i == 0) {
        sum += i;
        if (i != num / i)
          sum += num / i;
      }
    }
    return sum == num;
  }

  // 3. Euclid–Euler theorem approach
  // Time: O(1), Space: O(1)
  bool Solution3(int num) {
    if (num <= 1)
      return false;
    // Known perfect numbers from Euclid–Euler theorem within 1e8
    int perfectNums[] = {6, 28, 496, 8128, 33550336};
    for (int n : perfectNums) {
      if (n == num)
        return true;
    }
    return false;
  }

  // 4. Precomputed Set
  // Time: O(1), Space: O(1)
  bool Solution4(int num) {
    static unordered_set<int> perfectNums = {6, 28, 496, 8128, 33550336};
    return perfectNums.find(num) != perfectNums.end();
  }
};

int main() {
  Solution sol;
  cout << boolalpha;
  cout << sol.Solution1(28) << "\n";   // true
  cout << sol.Solution2(28) << "\n";   // true
  cout << sol.Solution3(8128) << "\n"; // true
  cout << sol.Solution4(7) << "\n";    // false
  return 0;
}
