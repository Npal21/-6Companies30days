//Link: https://leetcode.com/problems/count-number-of-nice-subarrays/description/

class Solution {

public:
    int lessThanOrEqualToK(vector<int>& nums, int k){
        if(k<0) return 0;

        int l=0, r=0, sum=0, count = 0;
        while(r < nums.size()){
             if(nums[r]%2 != 0){
                sum++ ;
            }
            
            while(sum > k){
                if(nums[l]%2 != 0){
                    sum--;
                }
                l++;
            }
            count += (r-l+1);
            r++;

        }
        return count;

    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return lessThanOrEqualToK(nums, k) - lessThanOrEqualToK(nums, k-1);
    }
};