#include <algorithm> // for __gcd
#include <iostream>
#include <numeric> // for std::gcd

using namespace std;

class Solution {
public:
  // 1. Brute Force
  // Time: O(min(a, b)), Space: O(1)
  int gcdBruteForce(int a, int b) {
    int ans = 1;
    for (int i = min(a, b); i >= 1; i--) {
      if (a % i == 0 && b % i == 0) {
        ans = i;
        break;
      }
    }
    return ans;
  }

  // 2. Euclidean Algorithm (Modulo)
  // Time: O(log(min(a, b))), Space: O(1)
  int gcdEuclidean(int a, int b) {
    while (b != 0) {
      int temp = b;
      b = a % b;
      a = temp;
    }
    return a;
  }

  // 3. Subtraction-based Euclidean Algorithm
  // Time: O(max(a, b)), Space: O(1)
  int gcdSubtraction(int a, int b) {
    while (a != b) {
      if (a > b)
        a -= b;
      else
        b -= a;
    }
    return a;
  }

  // 4. Binary GCD (Stein’s Algorithm)
  // Time: O(log(max(a, b))), Space: O(1)
  int gcdBinary(int a, int b) {
    if (a == 0)
      return b;
    if (b == 0)
      return a;

    int k = 0;
    while (((a | b) & 1) == 0) {
      a >>= 1;
      b >>= 1;
      k++;
    }
    while ((a & 1) == 0)
      a >>= 1;

    while (b != 0) {
      while ((b & 1) == 0)
        b >>= 1;
      if (a > b)
        swap(a, b);
      b -= a;
    }
    return a << k;
  }

  // 5. Built-in Function (__gcd or std::gcd)
  // Time: O(log(min(a, b))), Space: O(1)
  int gcdBuiltin(int a, int b) {
    return std::gcd(a, b); // or use __gcd(a, b)
  }
};

int main() {
  Solution sol;
  int a = 60, b = 36;

  cout << "Brute Force: " << sol.gcdBruteForce(a, b) << "\n";
  cout << "Euclidean: " << sol.gcdEuclidean(a, b) << "\n";
  cout << "Subtraction: " << sol.gcdSubtraction(a, b) << "\n";
  cout << "Binary GCD: " << sol.gcdBinary(a, b) << "\n";
  cout << "Builtin: " << sol.gcdBuiltin(a, b) << "\n";

  return 0;
}
