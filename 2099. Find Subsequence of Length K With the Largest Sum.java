
//Link: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/
//TC: O(nlogk)
//SC: O(n)

class Solution {
    public int[] maxSubsequence(int[] nums, int k) {
        PriorityQueue<int[]> pq = new PriorityQueue<int[]> ((a,b)->(a[0]-b[0]));
        for(int i=0; i<nums.length; i++){
            pq.offer(new int[]{nums[i], i});
            if(pq.size() > k){
                pq.poll();
            }
        }
        Set<Integer> index = new HashSet<>();
        while(!pq.isEmpty()){
            int[] top = pq.poll();
            index.add(top[1]);
        }
        int[] ans = new int[k];
        int x = 0;
        for(int i=0; i<nums.length; i++){
            if(index.contains(i)){
                ans[x] = nums[i];
                x++;
            }
        }
        return ans;
    }
}