class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        bitset<101> mask;
        for(auto &num : nums) {
            mask.set(num);
        }
        int m = k;
        while(m <= 100 && mask.test(m)) {
            m = m + k;
        }
        return m;
    }
};