
//Link: https://leetcode.com/problems/random-flip-matrix/

class Solution {
public:
    Solution(int n_rows, int n_cols) 
        : rows(n_rows), cols(n_cols), total(n_rows * n_cols) {}
    
    vector<int> flip() {
        if (used.size() == total)
            return {};
        int index = rand() % total;
        while (used.contains(index))
            index = ++index % total;
        used.insert(index);
        return {index / cols, index % cols};
    }
    
    void reset() {
        used = {};
    }

    private:
        unordered_set<int> used;
        int rows;
        int cols;
        int total;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */