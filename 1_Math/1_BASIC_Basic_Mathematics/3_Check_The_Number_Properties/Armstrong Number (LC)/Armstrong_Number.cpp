#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>


using namespace std;

class Solution {
public:
  // 1. Math approach with mod/div
  // Time: O(k), Space: O(1)
  bool isArmstrong1(int n) {
    int temp = n, k = 0;
    while (temp) {
      k++;
      temp /= 10;
    }

    int sum = 0, num = n;
    while (num) {
      int digit = num % 10;
      sum += pow(digit, k);
      num /= 10;
    }
    return sum == n;
  }

  // 2. String conversion
  // Time: O(k), Space: O(k)
  bool isArmstrong2(int n) {
    string s = to_string(n);
    int k = s.size();
    int sum = 0;
    for (char c : s) {
      int digit = c - '0';
      sum += pow(digit, k);
    }
    return sum == n;
  }

  // 3. Using log10 to get digits
  // Time: O(k), Space: O(1)
  bool isArmstrong3(int n) {
    if (n == 0)
      return true; // special case
    int k = (int)log10(n) + 1;
    int sum = 0, num = n;
    while (num) {
      int digit = num % 10;
      sum += pow(digit, k);
      num /= 10;
    }
    return sum == n;
  }

  // 4. Recursive solution
  // Time: O(k), Space: O(k) (recursion stack)
  int helperRec(int n, int k) {
    if (n == 0)
      return 0;
    int digit = n % 10;
    return pow(digit, k) + helperRec(n / 10, k);
  }
  bool isArmstrong4(int n) {
    int k = (int)to_string(n).size();
    return helperRec(n, k) == n;
  }

  // 5. Functional style with accumulate
  // Time: O(k), Space: O(k)
  bool isArmstrong5(int n) {
    string s = to_string(n);
    int k = s.size();
    vector<int> digits;
    for (char c : s)
      digits.push_back(c - '0');

    int sum = accumulate(digits.begin(), digits.end(), 0,
                         [k](int acc, int d) { return acc + (int)pow(d, k); });
    return sum == n;
  }
};

int main() {
  Solution sol;
  cout << boolalpha;
  cout << sol.isArmstrong1(153) << "\n";  // true
  cout << sol.isArmstrong2(123) << "\n";  // false
  cout << sol.isArmstrong3(9474) << "\n"; // true
  cout << sol.isArmstrong4(9475) << "\n"; // false
  cout << sol.isArmstrong5(370) << "\n";  // true
  return 0;
}
