#include <iostream>
using namespace std;

class Solution {
public:
  // 1. Using modulo operator
  // Time: O(1), Space: O(1)
  bool Solution1(int n) { return (n % 2 == 0); }

  // 2. Using bitwise AND
  // Time: O(1), Space: O(1)
  bool Solution2(int n) { return ((n & 1) == 0); }

  // 3. Using math library fmod
  // Time: O(1), Space: O(1)
  bool Solution3(int n) { return (fmod(n, 2) == 0); }
};

int main() {
  Solution sol;
  cout << boolalpha;
  cout << sol.Solution1(15) << "\n";  // false
  cout << sol.Solution2(44) << "\n";  // true
  cout << sol.Solution3(101) << "\n"; // false
  return 0;
}
