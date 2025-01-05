//Link: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/

class Solution {
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {

        int[][] dist = new int[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dist[i][j] = Integer.MAX_VALUE;
            }
        }
        for(int[] edge : edges){
            int from = edge[0], to= edge[1], wt = edge[2];
            dist[from][to]= wt;
            dist[to][from] = wt;
        }

        for(int i=0; i<n ; i++) dist[i][i]=0;

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dist[i][k] == Integer.MAX_VALUE || dist[k][j]  == Integer.MAX_VALUE)
                        continue;
                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int countCity = n, cityNo = -1;
        for(int city = 0; city < n; city++){
            int cnt =0;
            for(int adjCity =0; adjCity<n; adjCity++){
                if(dist[city][adjCity] <= distanceThreshold)
                    cnt++;
                
            }
                if(cnt <= countCity){
                    countCity = cnt;
                    cityNo = city;
                }
        }
            return cityNo;
        
    }    
}