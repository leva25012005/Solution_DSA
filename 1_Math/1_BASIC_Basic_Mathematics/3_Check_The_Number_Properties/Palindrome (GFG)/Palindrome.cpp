#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  // 1. String conversion + reverse
  bool isPalindrome1(int n) {
    string s = to_string(n);
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
  }

  // 2. String + two pointers
  bool isPalindrome2(int n) {
    string s = to_string(n);
    int l = 0, r = s.size() - 1;
    while (l < r) {
      if (s[l] != s[r])
        return false;
      l++;
      r--;
    }
    return true;
  }

  // 3. Reverse whole number (math)
  bool isPalindrome3(int n) {
    int original = n, rev = 0;
    while (n > 0) {
      int digit = n % 10;
      rev = rev * 10 + digit;
      n /= 10;
    }
    return rev == original;
  }

  // 4. Reverse half number (optimized math)
  bool isPalindrome4(int n) {
    if (n < 0 || (n % 10 == 0 && n != 0))
      return false;
    int revHalf = 0;
    while (n > revHalf) {
      revHalf = revHalf * 10 + n % 10;
      n /= 10;
    }
    // For odd length: revHalf/10
    return (n == revHalf || n == revHalf / 10);
  }

  // 5. Recursion with string
  bool checkRec(string &s, int l, int r) {
    if (l >= r)
      return true;
    if (s[l] != s[r])
      return false;
    return checkRec(s, l + 1, r - 1);
  }
  bool isPalindrome5(int n) {
    string s = to_string(n);
    return checkRec(s, 0, s.size() - 1);
  }

  // 6. Digit array + two-pointer
  bool isPalindrome6(int n) {
    vector<int> digits;
    while (n > 0) {
      digits.push_back(n % 10);
      n /= 10;
    }
    int l = 0, r = digits.size() - 1;
    while (l < r) {
      if (digits[l] != digits[r])
        return false;
      l++;
      r--;
    }
    return true;
  }
};

int main() {
  Solution sol;
  cout << boolalpha;
  cout << sol.isPalindrome1(1221) << "\n"; // true
  cout << sol.isPalindrome2(123) << "\n";  // false
  cout << sol.isPalindrome3(555) << "\n";  // true
  cout << sol.isPalindrome4(10) << "\n";   // false
  cout << sol.isPalindrome5(1001) << "\n"; // true
  cout << sol.isPalindrome6(1331) << "\n"; // true
  return 0;
}
