#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  // 1. Direct addition
  // Time: O(1), Space: O(1)
  int add1(int num1, int num2) { return num1 + num2; }

  // 2. Using bitwise operators
  // Time: O(1), Space: O(1)
  int add2(int num1, int num2) {
    while (num2 != 0) {
      unsigned carry = (unsigned)(num1 & num2) << 1;
      num1 = num1 ^ num2;
      num2 = (int)carry;
    }
    return num1;
  }

  // 3. Using accumulate
  // Time: O(1), Space: O(1)
  int add3(int num1, int num2) {
    vector<int> nums = {num1, num2};
    return accumulate(nums.begin(), nums.end(), 0);
  }
};

int main() {
  Solution sol;
  cout << sol.add1(12, 5) << "\n";  // 17
  cout << sol.add2(7, 8) << "\n";   // 15
  cout << sol.add3(20, -3) << "\n"; // 17
  return 0;
}
