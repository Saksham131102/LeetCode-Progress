class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unsigned __int128 mask = 0;
        for(auto &num : nums) {
            mask = mask | ((unsigned __int128)1 << num);
        }

        int m = k;
        while(m <= 100 && ((mask >> m) & (unsigned __int128)1)) {
            m = m + k;
        }
        return m;
    }
};