
//Link: https://leetcode.com/problems/first-unique-character-in-a-string/

class Solution {
    public int firstUniqChar(String s) {

        int[] freq = new int[26];
        for(int i=0; i<26; i++)
            freq[i] = 0;

        int n = s.length();
        for(int i=0; i<n; i++){
            char ch = s.charAt(i);
            freq[ch - 'a']++;          
        }
        for(int i=0; i<n; i++){
            char ch = s.charAt(i);
            if(freq[ch - 'a'] == 1){
                return i;
            }
        }
        return -1;
    }
}