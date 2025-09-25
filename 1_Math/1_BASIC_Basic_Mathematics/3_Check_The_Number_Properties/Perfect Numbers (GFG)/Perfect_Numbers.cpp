#include <cmath>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
  // 1. Brute Force: check all divisors
  // Time: O(n), Space: O(1)
  bool isPerfectBruteForce(int n) {
    if (n <= 1)
      return false;
    int sum = 0;
    for (int i = 1; i < n; i++) {
      if (n % i == 0)
        sum += i;
    }
    return sum == n;
  }

  // 2. Optimized Divisor Sum (check up to sqrt(n))
  // Time: O(sqrt(n)), Space: O(1)
  bool isPerfectOptimized(int n) {
    if (n <= 1)
      return false;
    int sum = 1;
    int sqrtN = static_cast<int>(sqrt(n));
    for (int i = 2; i <= sqrtN; i++) {
      if (n % i == 0) {
        sum += i;
        int div = n / i;
        if (div != i)
          sum += div;
      }
    }
    return sum == n;
  }

  // 3. Precomputed known perfect numbers (for n <= 10^9)
  // Time: O(1), Space: O(1)
  bool isPerfectPrecomputed(int n) {
    static const unordered_set<int> perfectNumbers = {6, 28, 496, 8128,
                                                      33550336};
    return perfectNumbers.find(n) != perfectNumbers.end();
  }

  // 4. Using Euclid-Euler formula (Mersenne primes)
  // Time: O(1), Space: O(1)
  bool isPerfectEuclidEuler(int n) {
    // Known p values that give perfect numbers <= 10^9
    int perfectNumbers[] = {6, 28, 496, 8128, 33550336};
    for (int p : perfectNumbers) {
      if (n == p)
        return true;
    }
    return false;
  }
};

int main() {
  Solution sol;
  int nums[] = {6, 10, 28, 496, 8128, 33550336, 12};

  for (int n : nums) {
    cout << "Number: " << n << "\n";
    cout << "BruteForce: " << sol.isPerfectBruteForce(n) << "\n";
    cout << "Optimized: " << sol.isPerfectOptimized(n) << "\n";
    cout << "Precomputed: " << sol.isPerfectPrecomputed(n) << "\n";
    cout << "EuclidEuler: " << sol.isPerfectEuclidEuler(n) << "\n";
    cout << "-------------------------\n";
  }

  return 0;
}
