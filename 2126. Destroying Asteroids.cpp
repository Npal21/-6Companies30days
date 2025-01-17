
//Link: https://leetcode.com/problems/destroying-asteroids/
//TC: O(nlogn)
//SC: O(1)

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long newMass = mass;
        for(int asteroid : asteroids){
            if(newMass < asteroid)
                return false;
            newMass += asteroid;
        }
        return true;
    }
};