#include <cmath> // for pow
#include <iostream>
#include <numeric> // for accumulate if needed
#include <string>


using namespace std;

class Solution {
public:
  // 1. Modulo by digit processing
  // Time: O(n), Space: O(1)
  bool isDivisible1(const string &s) {
    int mod = 0;
    for (char c : s) {
      int digit = c - '0';
      mod = (mod * 10 + digit) % 13;
    }
    return (mod == 0);
  }

  // 2. Rule-based divisibility test for 13 (using repeating coefficients)
  // Time: O(n), Space: O(1)
  bool isDivisible2(const string &s) {
    // Coefficients repeat with cycle [1, 10, 9, 12, 3, 4]
    int coeffs[] = {1, 10, 9, 12, 3, 4};
    int len = s.size();
    int sum = 0;
    int idx = 0;
    for (int i = len - 1; i >= 0; --i) {
      int digit = s[i] - '0';
      sum += digit * coeffs[idx];
      idx = (idx + 1) % 6;
    }
    return (sum % 13 == 0);
  }

  // 3. Simulated BigInteger using modulo (essentially same as method 1)
  // Time: O(n), Space: O(1)
  bool isDivisible3(const string &s) {
    long long mod = 0;
    for (char c : s) {
      int digit = c - '0';
      mod = (mod * 10 + digit) % 13;
    }
    return (mod == 0);
  }

  // 4. Chunk processing (divide into blocks, then modulo)
  // Time: O(n), Space: O(1)
  bool isDivisible4(const string &s) {
    int mod = 0;
    const int CHUNK_SIZE = 9; // safe for stoll
    for (size_t i = 0; i < s.size(); i += CHUNK_SIZE) {
      string part = s.substr(i, CHUNK_SIZE);
      long long val = stoll(part);
      // pow(10, part.size()) fits safely into long long for <= 9
      long long factor = 1;
      for (size_t j = 0; j < part.size(); j++)
        factor *= 10;
      mod = ((long long)mod * factor + val) % 13;
    }
    return (mod == 0);
  }
};

int main() {
  Solution sol;
  string s1 = "2911285";
  string s2 = "27";

  cout << boolalpha;
  cout << "Method 1: " << sol.isDivisible1(s1) << " " << sol.isDivisible1(s2)
       << "\n";
  cout << "Method 2: " << sol.isDivisible2(s1) << " " << sol.isDivisible2(s2)
       << "\n";
  cout << "Method 3: " << sol.isDivisible3(s1) << " " << sol.isDivisible3(s2)
       << "\n";
  cout << "Method 4: " << sol.isDivisible4(s1) << " " << sol.isDivisible4(s2)
       << "\n";

  return 0;
}
