#include <iostream>
#include <utility>
using namespace std;

class Solution {
public:
  // 1. Addition - Subtraction
  // Time : O(1), Space : O(1)
  pair<int, int> Solution1(int a, int b) {
    a = a + b;
    b = a - b;
    a = a - b;
    return {a, b};
  }

  // 2. Subtraction - Addition
  // Time : O(1), Space : O(1)
  pair<int, int> Solution2(int a, int b) {
    a = a - b;
    b = a + b;
    a = b - a;
    return {a, b};
  }

  // 3. Multiplication - Division
  // Time : O(1), Space : O(1)
  pair<int, int> Solution3(int a, int b) {
    a = a * b;
    b = a / b;
    a = a / b;
    return {a, b};
  }

  // 4. XOR swap
  // Time : O(1), Space : O(1)
  pair<int, int> Solution4(int a, int b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    return {a, b};
  }

  // 5. Tuple-like (using tie & make_tuple)
  // Time : O(1), Space : O(1)
  pair<int, int> Solution5(int a, int b) {
    tie(a, b) = make_tuple(b, a);
    return {a, b};
  }

  // 6. Using std::swap
  // Time : O(1)m, Space : O(1)
  pair<int, int> Solution6(int a, int b) {
    swap(a, b);
    return {a, b};
  }
};

int main() {
  Solution sol;

  int a = 13, b = 9;

  cout << "Initial Variables: " << a << ' ' << b << endl;
  cout << "After swapping:\n";
  auto p1 = sol.Solution1(a, b);
  cout << "Addition-Subtraction: " << p1.first << " " << p1.second << endl;

  auto p2 = sol.Solution2(a, b);
  cout << "Subtraction-Addition: " << p2.first << " " << p2.second << endl;

  auto p3 = sol.Solution3(a, b);
  cout << "Multiplication-Division: " << p3.first << " " << p3.second << endl;

  auto p4 = sol.Solution4(a, b);
  cout << "XOR: " << p4.first << " " << p4.second << endl;

  auto p5 = sol.Solution5(a, b);
  cout << "Tuple-like: " << p5.first << " " << p5.second << endl;

  auto p6 = sol.Solution6(a, b);
  cout << "std::swap: " << p6.first << " " << p6.second << endl;

  return 0;
}
