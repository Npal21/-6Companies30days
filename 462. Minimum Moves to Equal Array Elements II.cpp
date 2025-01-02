
//Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/

import java.util.Arrays;
//Step1: Sort
//Step2: Find median
//Step3: Calculate the sum of distances from all numbers to the median
class Solution {
    public int minMoves2(int[] nums) {  
        Arrays.sort(nums);
        int median = nums[nums.length >> 1]; // nums[nums.length/2]
        int movesCount = 0;
        for(int element : nums){
            movesCount += Math.abs(element-median);
        }

        return movesCount;
    }
}