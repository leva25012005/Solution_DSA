#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
  // 1. Brute force (check divisors for each number)
  // Time: O(n * sqrt(n)), Space: O(1)
  long long countDivisorsBrute(long long n) {
    long long cnt = 0;
    for (long long i = 1; i <= n; i++) {
      int divisors = 0;
      for (long long j = 1; j * j <= i; j++) {
        if (i % j == 0) {
          divisors++;
          if (j != i / j)
            divisors++;
        }
      }
      if (divisors == 3)
        cnt++;
    }
    return cnt;
  }

  // 2. Check sqrt for each number
  // Time: O(sqrt(n) * sqrt(sqrt(n))), Space: O(1)
  bool isPrime(long long x) {
    if (x < 2)
      return false;
    for (long long i = 2; i * i <= x; i++) {
      if (x % i == 0)
        return false;
    }
    return true;
  }
  long long countDivisorsSqrt(long long n) {
    long long cnt = 0;
    for (long long i = 2; i * i <= n; i++) {
      if (isPrime(i))
        cnt++;
    }
    return cnt;
  }

  // 3. Sieve + binary search
  // Time: O(1e6 log log 1e6 + log 1e6), Space: O(1e6)
  vector<int> sievePrimes(int limit) {
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= limit; i++) {
      if (isPrime[i]) {
        for (int j = i * i; j <= limit; j += i) {
          isPrime[j] = false;
        }
      }
    }
    vector<int> primes;
    for (int i = 2; i <= limit; i++) {
      if (isPrime[i])
        primes.push_back(i);
    }
    return primes;
  }

  long long countDivisorsSieveBS(long long n) {
    static vector<int> primes = sievePrimes(1000000);
    long long root = sqrtl(n);
    return upper_bound(primes.begin(), primes.end(), (int)root) -
           primes.begin();
  }

  // 4. Sieve + prefix sum
  // Time: O(1e6 log log 1e6 + 1), Space: O(1e6)
  long long countDivisorsSievePrefix(long long n) {
    static vector<int> prefix;
    if (prefix.empty()) {
      int limit = 1000000;
      vector<bool> isPrime(limit + 1, true);
      isPrime[0] = isPrime[1] = false;
      for (int i = 2; i * i <= limit; i++) {
        if (isPrime[i]) {
          for (int j = i * i; j <= limit; j += i) {
            isPrime[j] = false;
          }
        }
      }
      prefix.resize(limit + 1, 0);
      for (int i = 1; i <= limit; i++) {
        prefix[i] = prefix[i - 1] + (isPrime[i] ? 1 : 0);
      }
    }
    long long root = sqrtl(n);
    return prefix[(int)root];
  }
};

int main() {
  Solution sol;
  long long n1 = 6, n2 = 10;

  cout << "Brute force (n=6): " << sol.countDivisorsBrute(n1) << "\n";
  cout << "Sqrt check (n=6): " << sol.countDivisorsSqrt(n1) << "\n";
  cout << "Sieve+BS (n=6): " << sol.countDivisorsSieveBS(n1) << "\n";
  cout << "Sieve+Prefix (n=6): " << sol.countDivisorsSievePrefix(n1) << "\n\n";

  cout << "Brute force (n=10): " << sol.countDivisorsBrute(n2) << "\n";
  cout << "Sqrt check (n=10): " << sol.countDivisorsSqrt(n2) << "\n";
  cout << "Sieve+BS (n=10): " << sol.countDivisorsSieveBS(n2) << "\n";
  cout << "Sieve+Prefix (n=10): " << sol.countDivisorsSievePrefix(n2) << "\n";

  return 0;
}
