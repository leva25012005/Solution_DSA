#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  // 1. Formula method
  // Time: O(1), Space: O(1)
  long long sumOfSquaresFormula(int n) {
    return 1LL * n * (n + 1) * (2 * n + 1) / 6;
  }

  // 2. Iterative method
  // Time: O(n), Space: O(1)
  long long sumOfSquaresLoop(int n) {
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
      sum += 1LL * i * i;
    }
    return sum;
  }

  // 3. Recursive method
  // Time: O(n), Space: O(n) - stack)
  long long sumOfSquaresRec(int n) {
    if (n == 0)
      return 0;
    return 1LL * n * n + sumOfSquaresRec(n - 1);
  }

  // 4. Functional (accumulate) method
  // Time: O(n), Space: O(n)
  long long sumOfSquaresFunctional(int n) {
    vector<int> nums(n);
    iota(nums.begin(), nums.end(), 1); // Fill nums with 1..n
    return accumulate(nums.begin(), nums.end(), 0LL,
                      [](long long acc, int x) { return acc + 1LL * x * x; });
  }
};

int main() {
  Solution sol;
  int n = 3;

  cout << "Formula: " << sol.sumOfSquaresFormula(n) << "\n";
  cout << "Loop: " << sol.sumOfSquaresLoop(n) << "\n";
  cout << "Recursion: " << sol.sumOfSquaresRec(n) << "\n";
  cout << "Functional: " << sol.sumOfSquaresFunctional(n) << "\n";

  return 0;
}
