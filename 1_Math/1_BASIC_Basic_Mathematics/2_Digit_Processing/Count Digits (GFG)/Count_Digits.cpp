#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  // 1. Using string conversion
  // Time: O(log n), Space: O(log n) (string creation)
  int Solution1(int n) { return to_string(n).length(); }

  // 2. Iterative division by 10
  // Time: O(log n), Space: O(1)
  int Solution2(int n) {
    int count = 0;
    while (n > 0) {
      n /= 10;
      count++;
    }
    return count;
  }

  // 3. Using logarithm
  // Time: O(1), Space: O(1)
  int Solution3(int n) { return (int)log10(n) + 1; }

  // 4. Recursive division
  // Time: O(log n), Space: O(log n) (stack)
  int Solution4(int n) {
    if (n < 10)
      return 1;
    return 1 + Solution4(n / 10);
  }

  // 5. Functional / STL style
  // Time: O(log n), Space: O(log n) (vector)
  int Solution5(int n) {
    vector<int> digits;
    while (n > 0) {
      digits.push_back(n % 10);
      n /= 10;
    }
    return digits.size();
  }
};

int main() {
  Solution sol;
  int n = 456;

  cout << "String: " << sol.Solution1(n) << "\n";
  cout << "Iterative: " << sol.Solution2(n) << "\n";
  cout << "Logarithm: " << sol.Solution3(n) << "\n";
  cout << "Recursive: " << sol.Solution4(n) << "\n";
  cout << "Functional: " << sol.Solution5(n) << "\n";

  return 0;
}
