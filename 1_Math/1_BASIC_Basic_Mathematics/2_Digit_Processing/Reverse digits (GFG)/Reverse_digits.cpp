#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  // 1. String reverse
  // Time: O(log n), Space: O(log n) for string
  int Solution1(int n) {
    string s = to_string(n);
    reverse(s.begin(), s.end());
    return stoi(s);
  }

  // 2. Iterative digit extraction
  // Time: O(log n), Space: O(1)
  int Solution2(int n) {
    int rev = 0;
    while (n > 0) {
      rev = rev * 10 + n % 10;
      n /= 10;
    }
    return rev;
  }

  // 3. Recursive digit extraction
  // Time: O(log n), Space: O(log n) for recursion stack
  int reverseRecursiveHelper(int n, int rev) {
    if (n == 0)
      return rev;
    return reverseRecursiveHelper(n / 10, rev * 10 + n % 10);
  }
  int reverseRecursive(int n) { return reverseRecursiveHelper(n, 0); }

  // 4. STL/library (C++ style)
  // Time: O(log n), Space: O(log n)
  int Solution3(int n) {
    string s = to_string(n);
    reverse(begin(s), end(s));
    return stoi(s);
  }

  // 6. Pure mathematical
  // Time: O(log n), Space: O(1)
  int Solution4(int n) {
    int digits = floor(log10(n)) + 1;
    int rev = 0;
    for (int i = 0; i < digits; ++i) {
      int d = n % 10;
      rev += d * pow(10, digits - i - 1);
      n /= 10;
    }
    return rev;
  }
};

int main() {
  Solution sol;
  int n = 133456;

  cout << "n = " << n << endl;
  cout << "String reverse: " << sol.Solution1(n) << "\n";
  cout << "Iterative: " << sol.Solution2(n) << "\n";
  cout << "Recursive: " << sol.reverseRecursive(n) << "\n";
  cout << "STL: " << sol.Solution3(n) << "\n";
  cout << "Math: " << sol.Solution4(n) << "\n";

  n = 200;
  cout << "n = " << n << endl;
  cout << "String reverse: " << sol.Solution1(n) << "\n";
  cout << "Iterative: " << sol.Solution2(n) << "\n";
  cout << "Recursive: " << sol.reverseRecursive(n) << "\n";
  cout << "STL: " << sol.Solution3(n) << "\n";
  cout << "Math: " << sol.Solution4(n) << "\n";
  return 0;
}
