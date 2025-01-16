
//Link:
//TC: O(m*n)
//SC: O(m*n)

class Solution {
    public int findLength(int[] nums1, int[] nums2) {
        int[][] dp = new int[nums1.length + 1][nums2.length + 1];
        int maxLen = 0;
        //Make a memoization matrix

        for(int i=1; i <= nums1.length; i++){
            for(int j=1; j <= nums2.length; j++){
                //If both numbers are same, then add 1 to the top-left corner value
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    maxLen = Math.max(dp[i][j], maxLen);
                }
            }
        }
        return maxLen;        
    }
}