
//Link: https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/
//TC: O(2*n) = O(n)
//SC: O(n)

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long result = 0;
        long long currWindowSum = 0;
        unordered_set<int> st;
        int i=0, j=0;

        while(j < nums.size()){
            
            //Check if num[j] is already present in current window nums[i....j]
            while(st.count(nums[j])){
                currWindowSum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            currWindowSum += nums[j];
            st.insert(nums[j]);

            if(j-i+1 == k){
                result = max(result, currWindowSum);

                currWindowSum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            j++;
        }
        return result;
    }
};