
//Link: https://leetcode.com/problems/wiggle-sort-ii/

class Solution {
    public void wiggleSort(int[] nums) {
        //Step 1: Sort array
        Arrays.sort(nums);
        //Step 2: Make extra array and manage equality in it
        int n= nums.length;
        int[] res = new int[n];
        int i=1, j=n-1;
        while(i < n){
            res[i] = nums[j];
            i = i+2;
            j--;
        }
        i = 0;
        while(i < n){
            res[i] = nums[j];
            i = i+2; 
            j--;
        }
        //Step 3: Fill empty array from res[]
        for(i=0; i<n ; i++){
            nums[i] = res[i];
        }

        
        
    }
}