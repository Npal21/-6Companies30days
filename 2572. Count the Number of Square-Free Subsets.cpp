
//Link: https://leetcode.com/problems/count-the-number-of-square-free-subsets/description/
//TC: O(1)
//SC: O(1)

class Solution {
public:
    int squareFreeSubsets(vector<int>& nums) {
        // Array of the first 10 prime numbers
        int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        // Counter for occurrences of numbers (1 to 30)
        int count[31]{};
        // Populate the count array based on input nums
        for (int& x : nums) {
            ++count[x];
        }
        // Number of prime numbers we're considering
        const int numOfPrimes = 10;
        // Modulo constant for large numbers
        const int mod = 1e9 + 7;

        // f[i] will store the number of subsets ending with a subset of the prime state i
        vector<long long> subsetsState(1 << numOfPrimes);
        subsetsState[0] = 1;
        // Handle the special case for the number 1
        for (int i = 0; i < count[1]; ++i) {
            subsetsState[0] = subsetsState[0] * 2 % mod;
        }

        // Iterate over all numbers from 2 to 30 to construct the subsetsState
        for (int x = 2; x < 31; ++x) {
            // Skip numbers that are squares or not present in the input array
            if (count[x] == 0 || x % 4 == 0 || x % 9 == 0 || x % 25 == 0) {
                continue;
            }

            // Determine the prime factors mask for the current number
            int mask = 0;
            for (int i = 0; i < numOfPrimes; ++i) {
                if (x % primes[i] == 0) {
                    mask |= 1 << i;
                }
            }

            // Update the subsetsState based on the current number's prime factors
            for (int state = (1 << numOfPrimes) - 1; state; --state) {
                if ((state & mask) == mask) {
                    subsetsState[state] = (subsetsState[state] + 1LL * count[x] * subsetsState[state ^ mask]) % mod;
                }
            }
        }

        // Calculate the final answer excluding the empty set
        long long ans = -1;
        for (auto state : subsetsState) {
            ans = (ans + state) % mod;
        }
      
        // Return the total count of square-free subsets
        return ans;
    }
};
