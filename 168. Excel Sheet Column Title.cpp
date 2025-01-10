
//Link: https://leetcode.com/problems/excel-sheet-column-title/
//T.C : O(log(columnNo))

class Solution {
public:
    string convertToTitle(int columnNo) {
        string result;

        while(columnNo > 0){
            columnNo--;
            int remainder = columnNo % 26;
            char ch = remainder + 'A';
            result.push_back(ch);
            columnNo /= 26;
        }

        reverse(begin(result), end(result));
        return result;
        
    }
};