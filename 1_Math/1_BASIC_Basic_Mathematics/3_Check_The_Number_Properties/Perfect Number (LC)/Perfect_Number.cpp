#include <cmath>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
  // 1. Brute force approach
  // Time: O(n), Space: O(1)
  bool checkPerfectNumberBrute(int num) {
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
  bool checkPerfectNumberSqrt(int num) {
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
  bool checkPerfectNumberEuler(int num) {
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
  bool checkPerfectNumberPrecomputed(int num) {
    static unordered_set<int> perfectNums = {6, 28, 496, 8128, 33550336};
    return perfectNums.find(num) != perfectNums.end();
  }
};

int main() {
  Solution sol;
  cout << boolalpha;
  cout << sol.checkPerfectNumberBrute(28) << "\n";      // true
  cout << sol.checkPerfectNumberSqrt(28) << "\n";       // true
  cout << sol.checkPerfectNumberEuler(8128) << "\n";    // true
  cout << sol.checkPerfectNumberPrecomputed(7) << "\n"; // false
  return 0;
}
