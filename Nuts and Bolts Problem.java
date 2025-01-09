
//Link: https://www.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/1

class Solution {
    void matchPairs(int n, char nuts[], char bolts[]) {
        TreeSet<Character> set = new TreeSet<>();
        for(char c: nuts){
            set.add(c);
        }
        
        int id = 0;
        for(char c : set){
            nuts[id] = c;
            bolts[id] = c;
            id++;
        }
    }
}