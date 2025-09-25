#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  // 1. Formula: n * (n + 1) / 2
  // Time: O(1), Space: O(1)
  int sumFormula(int n) { return n * (n + 1) / 2; }

  // 2. Iterative loop
  // Time: O(n), Space: O(1)
  int sumLoop(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++)
      sum += i;
    return sum;
  }

  // 3. Recursion
  // Time: O(n), Space: O(n) (due to recursion stack)
  int sumRecursion(int n) {
    if (n == 0)
      return 0;
    return n + sumRecursion(n - 1);
  }

  // 4. Functional programming (accumulate)
  // Time: O(n), Space: O(n)
  int sumFunctional(int n) {
    vector<int> nums(n);
    iota(nums.begin(), nums.end(), 1); // fill [1..n]
    return accumulate(nums.begin(), nums.end(), 0);
  }
};

int main() {
  Solution sol;
  int n = 5;

  cout << "Formula: " << sol.sumFormula(n) << endl;
  cout << "Loop: " << sol.sumLoop(n) << endl;
  cout << "Recursion: " << sol.sumRecursion(n) << endl;
  cout << "Functional: " << sol.sumFunctional(n) << endl;

  return 0;
}
