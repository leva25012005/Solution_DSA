#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  // 1. Using string conversion
  int countDigitsString(int n) { return to_string(n).length(); }
  // Time: O(log n), Space: O(log n) (string creation)

  // 2. Iterative division by 10
  int countDigitsIterative(int n) {
    int count = 0;
    while (n > 0) {
      n /= 10;
      count++;
    }
    return count;
  }
  // Time: O(log n), Space: O(1)

  // 3. Using logarithm
  int countDigitsLog(int n) { return (int)log10(n) + 1; }
  // Time: O(1), Space: O(1)

  // 5. Recursive division
  int countDigitsRecursive(int n) {
    if (n < 10)
      return 1;
    return 1 + countDigitsRecursive(n / 10);
  }
  // Time: O(log n), Space: O(log n) (stack)

  // 6. Functional / STL style
  int countDigitsFunctional(int n) {
    vector<int> digits;
    while (n > 0) {
      digits.push_back(n % 10);
      n /= 10;
    }
    return digits.size();
  }
  // Time: O(log n), Space: O(log n) (vector)
};

int main() {
  Solution sol;
  int n = 456;

  cout << "String: " << sol.countDigitsString(n) << "\n";
  cout << "Iterative: " << sol.countDigitsIterative(n) << "\n";
  cout << "Logarithm: " << sol.countDigitsLog(n) << "\n";
  cout << "Recursive: " << sol.countDigitsRecursive(n) << "\n";
  cout << "Functional: " << sol.countDigitsFunctional(n) << "\n";

  return 0;
}
