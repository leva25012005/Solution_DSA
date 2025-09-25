#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  // 1. Using string traversal
  // Time: O(d), Space: O(d)
  int Solution1(int num) {
    string s = to_string(num);
    int cnt = 0;
    for (char c : s) {
      int digit = c - '0';
      if (digit != 0 && num % digit == 0)
        cnt++;
    }
    return cnt;
  }

  // 2. Using math (mod/div)
  // Time: O(d), Space: O(1)
  int Solution2(int num) {
    int cnt = 0;
    int n = num;
    while (n > 0) {
      int digit = n % 10;
      if (digit != 0 && num % digit == 0)
        cnt++;
      n /= 10;
    }
    return cnt;
  }

  // 3. Using recursion
  // Time: O(d), Space: O(d)
  int helper(int num, int original) {
    if (num == 0)
      return 0;
    int digit = num % 10;
    int add = (digit != 0 && original % digit == 0) ? 1 : 0;
    return add + helper(num / 10, original);
  }
  int Solution3(int num) { return helper(num, num); }

  // 4. Using functional style (count_if)
  // Time: O(d), Space: O(d)
  int Solution4(int num) {
    string s = to_string(num);
    return count_if(s.begin(), s.end(), [&](char c) {
      int digit = c - '0';
      return digit != 0 && num % digit == 0;
    });
  }
};

int main() {
  Solution sol;
  cout << sol.Solution1(1248) << "\n"; // 4
  cout << sol.Solution2(121) << "\n";  // 2
  cout << sol.Solution3(7) << "\n";    // 1
  cout << sol.Solution4(123456789) << "\n";
  return 0;
}
