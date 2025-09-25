#include <algorithm>
#include <cmath>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  // 1. Iterative (mod + div)
  // Time: O(log10|x|), Space: O(1)
  int Solution1(int x) {
    int rev = 0;
    while (x != 0) {
      int digit = x % 10;
      // check overflow
      if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7))
        return 0;
      if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8))
        return 0;
      rev = rev * 10 + digit;
      x /= 10;
    }
    return rev;
  }

  // 2. String conversion
  // Time: O(log10|x|), Space: O(log10|x|)
  int Solution2(int x) {
    bool neg = x < 0;
    string s = to_string(abs(x));
    reverse(s.begin(), s.end());
    long long rev = stoll(s);
    if (neg)
      rev = -rev;
    if (rev > INT_MAX || rev < INT_MIN)
      return 0;
    return (int)rev;
  }

  // 3. Recursive digit extraction
  // Space: O(log10|x|), Time: O(log10|x|)
  int Solution3Helper(int x, int rev = 0) {
    if (x == 0)
      return rev;
    int digit = x % 10;
    if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7))
      return 0;
    if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8))
      return 0;
    return Solution3Helper(x / 10, rev * 10 + digit);
  }
  int Solution3(int x) { return Solution3Helper(x, 0); }

  // 4. Using stack, O(log10|x|) time, O(log10|x|) space
  int Solution4(int x) {
    stack<int> st;
    int temp = abs(x);
    while (temp != 0) {
      st.push(temp % 10);
      temp /= 10;
    }
    long long rev = 0;
    while (!st.empty()) {
      rev = rev * 10 + st.top();
      if (rev > INT_MAX)
        return 0;
      st.pop();
    }
    return x < 0 ? -rev : rev;
  }

  // 5. Using digit vector/array, O(log10|x|) time, O(log10|x|) space
  int Solution5(int x) {
    vector<int> digits;
    int temp = abs(x);
    while (temp != 0) {
      digits.push_back(temp % 10);
      temp /= 10;
    }
    long long rev = 0;
    for (int d : digits) {
      rev = rev * 10 + d;
      if (rev > INT_MAX)
        return 0;
    }
    return x < 0 ? -rev : rev;
  }
};

int main() {
  Solution sol;
  int nums[] = {123, -123, 120, 1534236469};

  for (int x : nums) {
    cout << "Input: " << x << "\n";
    cout << "Iterative: " << sol.Solution1(x) << "\n";
    cout << "String: " << sol.Solution2(x) << "\n";
    cout << "Recursive: " << sol.Solution3(x) << "\n";
    cout << "Stack: " << sol.Solution4(x) << "\n";
    cout << "Vector: " << sol.Solution5(x) << "\n";
    cout << "---------------------\n";
  }

  return 0;
}
