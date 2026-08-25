class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0;
        int ans = 0;
        mp[0] = 1;
        for(auto &num : nums) {
            sum += num;
            auto it = mp.find(sum - k);
            if(it != mp.end())
                ans += it->second;
            mp[sum]++;
        }
        return ans;
    }
};