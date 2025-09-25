#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  // 1. String + reverse
  // Time: 0(d), Space: O(k)
  bool Solution1(int x) {
    if (x < 0)
      return false;
    string s = to_string(x);
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
  }

  // 2. String + two pointers
  // Time: 0(d), Space: O(1)
  bool Solution2(int x) {
    if (x < 0)
      return false;
    string s = to_string(x);
    int l = 0, r = s.size() - 1;
    while (l < r) {
      if (s[l] != s[r])
        return false;
      l++;
      r--;
    }
    return true;
  }

  // 3. Reverse whole integer
  // Time: 0(d), Space: O(1)
  bool Solution3(int x) {
    if (x < 0)
      return false;
    long long original = x;
    long long rev = 0;
    while (x > 0) {
      rev = rev * 10 + (x % 10);
      x /= 10;
    }
    return rev == original;
  }

  // 4. Reverse half integer (Optimal)
  // Time: 0(d), Space: O(1)
  bool Solution4(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0))
      return false;
    int rev = 0;
    while (x > rev) {
      rev = rev * 10 + (x % 10);
      x /= 10;
    }
    // For even length → rev == x
    // For odd length → rev/10 == x
    return (x == rev) || (x == rev / 10);
  }

  // 5. Compare first and last digits
  // Time: 0(d), Space: O(1)
  bool Solution5(int x) {
    if (x < 0)
      return false;
    int div = 1;
    while (x / div >= 10) {
      div *= 10;
    }
    while (x > 0) {
      int left = x / div;
      int right = x % 10;
      if (left != right)
        return false;
      // remove first and last digits
      x = (x % div) / 10;
      div /= 100;
    }
    return true;
  }
};

int main() {
  Solution sol;
  cout << boolalpha;
  cout << sol.Solution1(121) << "\n";   // true
  cout << sol.Solution2(-121) << "\n";  // false
  cout << sol.Solution3(10) << "\n";    // false
  cout << sol.Solution4(1221) << "\n";  // true
  cout << sol.Solution5(12321) << "\n"; // true
  return 0;
}
