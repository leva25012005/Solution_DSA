#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  // 1. Using modulo & division (explicit digits)
  // Time: O(1), Space: O(1)
  bool isArmstrong1(int n) {
    int d1 = n % 10;
    int d2 = (n / 10) % 10;
    int d3 = n / 100;
    return (d1 * d1 * d1 + d2 * d2 * d2 + d3 * d3 * d3) == n;
  }

  // 2. Convert number to string and iterate
  // Time: O(1), Space: O(1)  (string length fixed = 3)
  bool isArmstrong2(int n) {
    string s = to_string(n);
    int sum = 0;
    for (char c : s) {
      int d = c - '0';
      sum += d * d * d;
    }
    return sum == n;
  }

  // 3. Using loop with modulo (general method for any n digits)
  // Time: O(d), Space: O(1) where d = number of digits (here d = 3 => O(1))
  bool isArmstrong3(int n) {
    int temp = n, sum = 0;
    while (temp > 0) {
      int d = temp % 10;
      sum += d * d * d;
      temp /= 10;
    }
    return sum == n;
  }

  // 4. Using pow() from <cmath>
  // Time: O(1), Space: O(1)
  bool isArmstrong4(int n) {
    int d1 = n % 10;
    int d2 = (n / 10) % 10;
    int d3 = n / 100;
    return (pow(d1, 3) + pow(d2, 3) + pow(d3, 3)) == n;
  }

  // 5. Functional style with accumulate
  // Time: O(d), Space: O(d) where d = number of digits (here d = 3)
  bool isArmstrong5(int n) {
    string s = to_string(n);
    vector<int> digits;
    for (char c : s)
      digits.push_back(c - '0');
    int sum = accumulate(digits.begin(), digits.end(), 0,
                         [](int acc, int x) { return acc + x * x * x; });
    return sum == n;
  }
};

int main() {
  Solution sol;
  cout << boolalpha;
  cout << sol.isArmstrong1(153) << "\n"; // true
  cout << sol.isArmstrong2(371) << "\n"; // true
  cout << sol.isArmstrong3(372) << "\n"; // false
  cout << sol.isArmstrong4(407) << "\n"; // true
  cout << sol.isArmstrong5(100) << "\n"; // false
  return 0;
}
