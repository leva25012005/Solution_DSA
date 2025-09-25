#include <iostream>
#include <numeric>
#include <string>

using namespace std;

class Solution {
public:
  // 1. Modulo & Division (iterative)
  int Solution1(int n) {
    int sum = 0;
    while (n > 0) {
      sum += n % 10;
      n /= 10;
    }
    return sum;
  }
  // Time: O(log10(n)), Space: O(1)

  // 2. Convert to string & iterate
  int Solution2(int n) {
    string s = to_string(n);
    int sum = 0;
    for (char c : s)
      sum += c - '0';
    return sum;
  }
  // Time: O(log10(n)), Space: O(log10(n))

  // 3. Recursion
  int Solution3(int n) {
    if (n == 0)
      return 0;
    return n % 10 + Solution3(n / 10);
  }
  // Time: O(log10(n)), Space: O(log10(n)) due to recursion stack

  // 4. Functional / accumulate
  int Solution4(int n) {
    string s = to_string(n);
    return accumulate(s.begin(), s.end(), 0,
                      [](int acc, char c) { return acc + (c - '0'); });
  }
  // Time: O(log10(n)), Space: O(log10(n)) for string

  // 5. Mathematical formula (digital root, special case)
  int Solution5(int n) {
    if (n == 0)
      return 0;
    return 1 + (n - 1) % 9; // Digital root
  }
  // Time: O(1), Space: O(1)
};

int main() {
  Solution sol;
  int n1 = 687, n2 = 12;

  cout << "\nFor n = 687\n";
  cout << "Iterative: " << sol.Solution1(n1) << "\n";  // 21
  cout << "String: " << sol.Solution2(n1) << "\n";     // 21
  cout << "Recursion: " << sol.Solution3(n1) << "\n";  // 21
  cout << "Functional: " << sol.Solution4(n1) << "\n"; // 21
  cout << "Formula (Digital Root): " << sol.Solution5(n1)
       << "\n"; // 3 (digital root)

  cout << "\nFor n = 12\n";
  cout << "Iterative: " << sol.Solution1(n2) << "\n";              // 3
  cout << "String: " << sol.Solution2(n2) << "\n";                 // 3
  cout << "Recursion: " << sol.Solution3(n2) << "\n";              // 3
  cout << "Functional: " << sol.Solution4(n2) << "\n";             // 3
  cout << "Formula (Digital Root): " << sol.Solution5(n2) << "\n"; // 3

  return 0;
}
