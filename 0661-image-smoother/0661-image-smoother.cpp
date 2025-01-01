class Solution {
public:

    vector<vector<int>> directions{
        {-1,-1}, {-1,0}, {-1, 1},
        {0,-1}, {0,0}, {0,1},
        {1,-1}, {1,0}, {1,1}
    };
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int r = img.size();
        int c = img[0].size();

        vector<int> temp(c);
        int prevCorner = 0;

        for(int i=0; i< r; i++){
            for(int j=0; j< c; j++){
                int sum=0;
                int count =0;

                //Bottom neighbours
                if(i+1 < r){
                    if(j-1 >= 0){
                        sum += img[i+1][j-1];
                        count++;
                    }
                    sum += img[i+1][j];
                    count++;
                    if(j+1 < c){
                        sum += img[i+1][j+1];
                        count++;
                    }
                }
                //Neighbour towards right
                if(j+1 < c){
                    sum += img[i][j+1];
                    count++;
                }
                //Current cell
                sum += img[i][j];
                count++;
                //Neighbour towards left
                if(j-1 >= 0){
                    sum += temp[j-1];
                    count++;
                }
                //Top neighbours
                if(i-1 >= 0){
                    //Top-left neighbour
                    if(j-1 >= 0){
                        sum += prevCorner;
                        count++;
                    }
                    //Top-center neighbour
                    sum += temp[j];
                    count++;
                    //Top-right neighbour
                    if(j+1 < c){
                        sum += temp[j+1];
                        count++;
                    }
                }
                if(i-1 >= 0){
                    prevCorner = temp[j];
                }                
                temp[j] = img[i][j];
                img[i][j] = sum/count;                
            }
    }
        return img;
    }
};