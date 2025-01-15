
//Link: https://leetcode.com/problems/high-access-employees/

class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<int>> mp;
        for (auto& e : access_times) {
            auto name = e[0];
            auto s = e[1];
            int time = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(2, 2));
            mp[name].emplace_back(time);
        }
        vector<string> ans;
        for (auto& [name, timeStamp] : mp) {
            sort(timeStamp.begin(), timeStamp.end());
            for (int i = 2; i < timeStamp.size(); ++i) {
                if (timeStamp[i] - timeStamp[i - 2] < 60) {
                    ans.emplace_back(name);
                    break;
                }
            }
        }
        return ans;
    }
};