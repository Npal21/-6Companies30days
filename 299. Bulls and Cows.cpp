
//Link: https://leetcode.com/problems/bulls-and-cows/

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;

        vector<int> countSecret(10,0);
        vector<int> countGuess(10,0);

        for(int i=0; i<secret.length(); i++){
            int secretDigit = secret[i] - '0';
            int guessDigit = guess[i] - '0';

            if(secretDigit == guessDigit){
                bulls++;
            }
            else{
                countSecret[secretDigit]++;
                countGuess[guessDigit]++;
            }
        }

        for(int i=0; i<10 ; i++){
            cows += min(countSecret[i], countGuess[i]);

        }

        return to_string(bulls)+"A"+to_string(cows)+"B";
        
    }
};