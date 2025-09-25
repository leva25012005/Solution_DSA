#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>


using namespace std;

class Solution {
public:
  // 1. String conversion (scan MSB -> LSB)
  // Time: O(d), Space: O(d)
  int Solution1(int n) {
    string s = to_string(n);
    int sum = 0, sign = 1;
    for (char c : s) {
      int digit = c - '0';
      sum += sign * digit;
      sign = -sign;
    }
    return sum;
  }

  // 2. Math only (digit count first, then process LSB->MSB)
  // Time: O(d), Space: O(1)
  int Solution2(int n) {
    int temp = n, d = 0;
    while (temp > 0) {
      d++;
      temp /= 10;
    }
    int sum = 0;
    while (n > 0) {
      int digit = n % 10;
      if (d % 2 == 1)
        sum += digit;
      else
        sum -= digit;
      d--;
      n /= 10;
    }
    return sum;
  }

  // 3. Store digits in vector, then traverse backwards
  // Time: O(d), Space: O(d)
  int Solution3(int n) {
    vector<int> digits;
    while (n > 0) {
      digits.push_back(n % 10);
      n /= 10;
    }
    reverse(digits.begin(), digits.end());
    int sum = 0, sign = 1;
    for (int d : digits) {
      sum += sign * d;
      sign = -sign;
    }
    return sum;
  }

  // 4. Recursion (MSB -> LSB)
  // Time: O(d), Space: O(d) recursion stack
  int helper(string &s, int idx, int sign) {
    if (idx == (int)s.size())
      return 0;
    int digit = s[idx] - '0';
    return sign * digit + helper(s, idx + 1, -sign);
  }
  int Solution4(int n) {
    string s = to_string(n);
    return helper(s, 0, 1);
  }

  // 5. Single pass with sign flip (like #1 but highlight pattern)
  // Time: O(d), Space: O(d) due to string
  int Solution5(int n) {
    string s = to_string(n);
    int sum = 0, sign = 1;
    for (int i = 0; i < (int)s.size(); i++) {
      sum += sign * (s[i] - '0');
      sign = -sign; // flip each step
    }
    return sum;
  }

  // 6. Functional style using accumulate
  // Time: O(d), Space: O(d)
  int Solution6(int n) {
    string s = to_string(n);
    int sign = 1;
    return accumulate(s.begin(), s.end(), 0, [&](int acc, char c) {
      int digit = c - '0';
      int val = sign * digit;
      sign = -sign;
      return acc + val;
    });
  }

  // 7. Separate odd/even position sums
  // Time: O(d), Space: O(d) or O(1) depending impl
  int Solution7(int n) {
    string s = to_string(n);
    int sumOdd = 0, sumEven = 0;
    for (int i = 0; i < (int)s.size(); i++) {
      int digit = s[i] - '0';
      if (i % 2 == 0)
        sumOdd += digit; // odd position (0-based)
      else
        sumEven += digit;
    }
    return sumOdd - sumEven;
  }
};

int main() {
  Solution sol;
  cout << sol.Solution1(521) << "\n";    // 4
  cout << sol.Solution2(111) << "\n";    // 1
  cout << sol.Solution3(886996) << "\n"; // 0
  cout << sol.Solution4(521) << "\n";    // 4
  cout << sol.Solution5(111) << "\n";    // 1
  cout << sol.Solution6(886996) << "\n"; // 0
  cout << sol.Solution7(521) << "\n";    // 4
  return 0;
}
