
//Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
//TC: O(N*2*K)
//SC: O(K)

class Solution {
public:
    int f(int ind, int buy, int cap, vector<int> &prices, int n, 
        vector<vector<vector<int>>> &dp){
            if(ind == n || cap == 0) return 0;
            if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
            if(buy == 1){
                return dp[ind][buy][cap] = 
                    max(-prices[ind] + f(ind + 1, 0, cap, prices, n, dp),
                    0 + f(ind + 1, 1, cap, prices, n, dp));
            }
            return dp[ind][buy][cap] = 
                    max(prices[ind] + f(ind + 1, 1, cap - 1, prices, n, dp),
                    0 + f(ind + 1, 0, cap, prices, n, dp));
        }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> after(2, vector<int> (k+1, 0));
        vector<vector<int>> cur(2, vector<int> (k+1, 0));

        for(int index= n-1; index >= 0 ; index--){
            for(int buy = 0; buy <= 1 ; buy++){
                for(int cap = 1; cap <= k; cap++){
                    if (buy == 1){
                        cur[buy][cap] = max(-prices[index] + after[0][cap],
                         0 + after[1][cap]);
                    }
                    else{
                        cur[buy][cap] = max(prices[index] + after[1][cap-1],
                         0 + after[0][cap]);
                    }
                }
            }
            after = cur;
        }
        return after[1][k];
        
    }
};