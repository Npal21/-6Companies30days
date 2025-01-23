
//Link: https://leetcode.com/problems/combination-sum-iii/
//TC: O(9! / (9 - k)!)
//SC: O(9! / (k!(9 - k)!) + k)

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;

        function<void(int, int)> dfs = [&](int start, int sum){
            if(sum == 0 && temp.size() == k){
                ans.emplace_back(temp);
                return;
            }
            if(start > 9 || start > sum || temp.size() >= k)
                return;
            
            temp.emplace_back(start);
            dfs(start+1, sum-start);

            temp.pop_back();
            dfs(start+1, sum);
        };

        dfs(1, n);
        return ans;
    }
};