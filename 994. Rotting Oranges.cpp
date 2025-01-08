
//Link: https://leetcode.com/problems/rotting-oranges/
//TC: O(n * m)
//SC: O(n)

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>, int>> q;
        int row = grid.size();
        int col = grid[0].size();

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                }
            }
        }

        int time=0;       
        //BFS traversal
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t= q.front().second;
            time = max(time, t);
            q.pop();

            for(int i=-1; i<=1; i++){
                int nrow = r + i;
                if(nrow >= 0 && nrow < row && grid[nrow][c]==1){
                    grid[nrow][c] = 2;
                    q.push({{nrow,c},t+1});
                }
            }
            for(int i=-1; i<=1; i++){
                int ncol = c + i;
                if(ncol >= 0 && ncol < col && grid[r][ncol]==1){
                    grid[r][ncol] = 2;
                    q.push({{r,ncol},t+1});
                }
            }

        }
            for(int i=0; i<row; i++){
                for(int j=0; j<col; j++){
                    if(grid[i][j] == 1)
                        return -1;
                }
            }
        
        return time;
    }
};