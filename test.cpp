#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

/* 
 This is hackerrank exercise: Bit Array 
 https://www.hackerrank.com/challenges/bitset-1/problem?isFullScreen=false
*/

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  uint32_t N, S, P, Q;
  const uint32_t mod = 1u << 31;
  uint32_t count = 0;

  cin >> N >> S >> P >> Q;

  uint32_t a = S;

  vector<uint64_t> flag(ceil((mod + 63) / 64), 0);

  for (size_t i = 0; i < N; ++i) {
    uint32_t idx = a >> 6;
    uint32_t offset = a & 63;
    if (!(flag[idx] & (1ULL << offset))) {
      count++;
      flag[idx] |= (1ULL << offset);
    } else {
      break;
    }
    a = (1ULL * P * a + Q) & (mod - 1);
  }
  cout << count << endl;
  return 0;
}
