
//Link: https://leetcode.com/problems/longest-mountain-in-array/description/

class Solution {
public:
    int longestMountain(vector<int>& arr) {
       int res = 0;
       int n = arr.size();
       for(int i=1; i<n; i++){
            int count = 1;
            bool flag = false;
            //Increasing sequence
            int j = i;
            while(j < n && arr[j] > arr[j-1]){
                j++;
                count++;
            }

            //Decreasing subsequence
            while(i!=j && j<n && arr[j] < arr[j-1]){
                j++;
                count++;
                flag = true;
            }
            if(i!=j && flag && count > 2){
                res = max(res,count);
                j--;
            }
            i = j;
       }
       return res;
        
    }
};