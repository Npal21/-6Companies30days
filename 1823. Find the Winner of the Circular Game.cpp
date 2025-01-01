
//Link: https://leetcode.com/problems/find-the-winner-of-the-circular-game/

class Solution {
public:

    int findWinnerIndex(int n, int k){
         if(n == 1)
            return 0;

        int index = findWinnerIndex(n-1, k);
        index = (index + k) % n;

        return index;   
        
    }

    int findTheWinner(int n, int k) {
        
        int result_index = findWinnerIndex(n,k);
        return result_index + 1;            
    }

    
};