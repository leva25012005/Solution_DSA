#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  // 1. Using modulo operator
  // Time: O(d), Space: O(1)   where d = number of digits (~2 for x <= 100)
  int isHarshad1(int x) {
    int sum = 0, temp = x;
    while (temp > 0) {
      sum += temp % 10;
      temp /= 10;
    }
    return (x % sum == 0) ? sum : -1;
  }

  // 2. Using string conversion
  // Time: O(d), Space: O(d)
  int isHarshad2(int x) {
    string s = to_string(x);
    int sum = 0;
    for (char c : s)
      sum += (c - '0');
    return (x % sum == 0) ? sum : -1;
  }

  // 3. Using math (pow and division)
  // Time: O(d), Space: O(1)
  int isHarshad3(int x) {
    int digits = (int)log10(x) + 1;
    int sum = 0;
    for (int i = 0; i < digits; i++) {
      int d = (x / (int)pow(10, i)) % 10;
      sum += d;
    }
    return (x % sum == 0) ? sum : -1;
  }

  // 4. Using recursion
  // Time: O(d), Space: O(d) (stack space)
  int digitSumRec(int n) {
    if (n == 0)
      return 0;
    return (n % 10) + digitSumRec(n / 10);
  }
  int isHarshad4(int x) {
    int sum = digitSumRec(x);
    return (x % sum == 0) ? sum : -1;
  }

  // 5. Using STL accumulate on string
  // Time: O(d), Space: O(d)
  int isHarshad5(int x) {
    string s = to_string(x);
    int sum = accumulate(s.begin(), s.end(), 0,
                         [](int acc, char c) { return acc + (c - '0'); });
    return (x % sum == 0) ? sum : -1;
  }
};

int main() {
  Solution sol;
  cout << sol.isHarshad1(18) << "\n"; // 9
  cout << sol.isHarshad2(23) << "\n"; // -1
  cout << sol.isHarshad3(12) << "\n"; // 3
  cout << sol.isHarshad4(21) << "\n"; // 3
  cout << sol.isHarshad5(20) << "\n"; // 2
  return 0;
}
