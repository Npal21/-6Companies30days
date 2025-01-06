
//Link: https://leetcode.com/problems/shopping-offers/description/

//TC: O(N^k.M) where N=max value in needs, k= size of needs, M = no. of special offers
//SC: O(N^k)

class Solution {
public:
    map<vector<int>, int> mp;

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        // Check if the result for the current `needs` is already computed
        if (mp.count(needs) != 0) {
            return mp[needs];
        }
        
        // Calculate the cost without any offers
        int ans = 0;
        for (int i = 0; i < needs.size(); i++) {
            ans += (needs[i] * price[i]);
        }

        // Try applying each special offer
        for (int i = 0; i < special.size(); i++) {
            bool isValidOffer = true;

            // Check if the current special offer is valid
            for (int j = 0; j < needs.size(); j++) {
                if (needs[j] < special[i][j]) {
                    isValidOffer = false;
                    break;
                }
            }

            // If the offer is valid, apply it
            if (isValidOffer) {
                for (int j = 0; j < needs.size(); j++) {
                    needs[j] -= special[i][j];
                }

                // Recurse with the updated needs
                int ans2 = special[i].back() + shoppingOffers(price, special, needs);
                ans = min(ans, ans2);

                // Backtrack to restore the original needs
                for (int j = 0; j < needs.size(); j++) {
                    needs[j] += special[i][j];
                }
            }
        }

        // Memoize and return the result
        return mp[needs] = ans;
    }
};
