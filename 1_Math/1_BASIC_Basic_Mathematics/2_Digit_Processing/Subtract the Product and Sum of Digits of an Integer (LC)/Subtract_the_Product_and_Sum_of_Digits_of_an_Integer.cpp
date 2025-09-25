#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution {
private:
  // Helper for recursion to calculate product - sum
  pair<int, int> helper(int n) {
    if (n == 0)
      return {1, 0}; // product=1, sum=0
    auto prev = helper(n / 10);
    int product = prev.first * (n % 10);
    int sum = prev.second + (n % 10);
    return {product, sum};
  }

public:
  // 1. Iterative (using division and modulo)
  // Time: O(d), Space: O(1)
  int Solution1(int n) {
    int sum = 0, product = 1;
    while (n > 0) {
      int digit = n % 10;
      sum += digit;
      product *= digit;
      n /= 10;
    }
    return product - sum;
  }

  // 2. String conversion
  // Time: O(d), Space: O(d) for string
  int Solution2(int n) {
    string s = to_string(n);
    int sum = 0, product = 1;
    for (char c : s) {
      int digit = c - '0';
      sum += digit;
      product *= digit;
    }
    return product - sum;
  }

  // 3. Recursive approach
  // Time: O(d), Space: O(d) (recursion stack)
  int Solution3(int n) {
    if (n == 0)
      return 0; // base case
    int lastDigit = n % 10;
    int prev = Solution3(n / 10);
    // tricky: need to accumulate sum/product separately
    // easiest: helper function
    return helper(n).first - helper(n).second;
  }

  int Solution3Full(int n) {
    pair<int, int> res = helper(n);
    return res.first - res.second;
  }

  // 4. Functional / STL approach
  // Time: O(d), Space: O(d)
  int Solution4(int n) {
    string s = to_string(n);
    vector<int> digits;
    for (char c : s)
      digits.push_back(c - '0');
    int sum = accumulate(digits.begin(), digits.end(), 0);
    int product =
        accumulate(digits.begin(), digits.end(), 1, multiplies<int>());
    return product - sum;
  }
};

int main() {
  Solution sol;
  int n1 = 234, n2 = 4421;

  cout << sol.Solution1(n1) << "\n";     // 15
  cout << sol.Solution2(n1) << "\n";     // 15
  cout << sol.Solution3Full(n1) << "\n"; // 15
  cout << sol.Solution4(n1) << "\n";     // 15

  cout << sol.Solution1(n2) << "\n";     // 21
  cout << sol.Solution2(n2) << "\n";     // 21
  cout << sol.Solution3Full(n2) << "\n"; // 21
  cout << sol.Solution4(n2) << "\n";

  return 0;
}