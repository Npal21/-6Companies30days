
//GfG Link: https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1
//Leetcode: https://leetcode.com/problems/sliding-window-maximum/

//TC: (Using Deque) Every element is added(pushed) and popped only once,So it is O(n) time complexity.

class Solution {
  public:
    // Monotonic decreasing problem
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {        
        int n = arr.size();        
        if(n==0)
            return {};
        deque<int> deq;
        vector<int> result;
        
        for(int i=0; i<n; i++){
            //Step 1: Making space for arr[i]
            while(!deq.empty() && deq.front() <= i-k){
                deq.pop_front();
            }
            //Step 2: Pop all elements smaller than nums[i]
            while(!deq.empty() && arr[i] > arr[deq.back()]){
                deq.pop_back();
            }
            //Step 3: Push i in deque
            deq.push_back(i);
            //Step 4: if i>= k-1, then deq.front() is our answer for this window
            if(i >= k-1){
                result.push_back(arr[deq.front()]);
            }
        }
        return result;
    }
};