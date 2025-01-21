
//Link: https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/
//TC: O(N*log(N))
//SC: O(1)

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        // Sort the input vectors
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int minHorBarsRemoved = 1, minVerBarsRemoved = 1;
        int count = 1;
        // Calculate the maximum horizontal gap
        for(int i=1; i < hBars.size(); i++){
            if(hBars[i] == hBars[i-1]+1)
                count++;
            else
                count = 1;            
            minHorBarsRemoved = max(minHorBarsRemoved, count);
        }
        // Calculate the maximum vertical gap
        count = 1;
        for(int i=1; i < vBars.size(); i++){
            if(vBars[i] == vBars[i-1]+1)
                count++;
            else
                count = 1;
            minVerBarsRemoved = max(minVerBarsRemoved, count);
        }
        // The side length of the largest square hole
        int side = min(minHorBarsRemoved + 1, minVerBarsRemoved + 1);
        return side*side;
    }
};