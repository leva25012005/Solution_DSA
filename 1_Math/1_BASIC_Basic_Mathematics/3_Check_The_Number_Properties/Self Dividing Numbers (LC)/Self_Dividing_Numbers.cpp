#include <algorithm> // for all_of
#include <iostream>
#include <numeric> // for accumulate
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  // 1. String conversion method
  // Time: O(d) per number, Space: O(d) (d = số chữ số)
  vector<int> Solution1(int left, int right) {
    vector<int> ans;
    for (int n = left; n <= right; n++) {
      string s = to_string(n);
      bool ok = true;
      for (char c : s) {
        int d = c - '0';
        if (d == 0 || n % d != 0) {
          ok = false;
          break;
        }
      }
      if (ok)
        ans.push_back(n);
    }
    return ans;
  }

  // 2. Math digit extraction method
  // Time: O(d) per number, Space: O(1)
  vector<int> Solution2(int left, int right) {
    vector<int> ans;
    for (int n = left; n <= right; n++) {
      int x = n;
      bool ok = true;
      while (x > 0) {
        int d = x % 10;
        if (d == 0 || n % d != 0) {
          ok = false;
          break;
        }
        x /= 10;
      }
      if (ok)
        ans.push_back(n);
    }
    return ans;
  }

  // 3. Helper function + loop (standard)
  // Time: O(d) per number, Space: O(1)
  bool isSelfDividing(int n) {
    int x = n;
    while (x > 0) {
      int d = x % 10;
      if (d == 0 || n % d != 0)
        return false;
      x /= 10;
    }
    return true;
  }
  vector<int> Solution3(int left, int right) {
    vector<int> ans;
    for (int n = left; n <= right; n++) {
      if (isSelfDividing(n))
        ans.push_back(n);
    }
    return ans;
  }

  // 4. Recursive digit checking
  // Time: O(d) per number, Space: O(d) (stack recursion)
  bool checkRecursive(int n, int original) {
    if (n == 0)
      return true;
    int d = n % 10;
    if (d == 0 || original % d != 0)
      return false;
    return checkRecursive(n / 10, original);
  }
  vector<int> Solution4(int left, int right) {
    vector<int> ans;
    for (int n = left; n <= right; n++) {
      if (checkRecursive(n, n))
        ans.push_back(n);
    }
    return ans;
  }

  // 5. Functional style with STL all_of
  // Time: O(d) per number, Space: O(d)
  vector<int> Solution5(int left, int right) {
    vector<int> ans;
    for (int n = left; n <= right; n++) {
      string s = to_string(n);
      bool ok = all_of(s.begin(), s.end(), [&](char c) {
        int d = c - '0';
        return (d != 0 && n % d == 0);
      });
      if (ok)
        ans.push_back(n);
    }
    return ans;
  }
};

// Example usage
int main() {
  Solution sol;
  int left = 1, right = 22;

  vector<int> res = sol.Solution2(left, right);
  for (int x : res)
    cout << x << " ";
  cout << endl;

  return 0;
}
