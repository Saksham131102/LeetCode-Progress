class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        k = min(k, n-1);
        unordered_map<int, int> mp;
        for(int i=0;i<=k;i++) {
            mp[nums[i]]++;
            if(mp[nums[i]] > 1)
                return true;
        }
        int left = 0, right = k + 1;
        while(right < n) {
            mp[nums[left]]--;
            left++;
            mp[nums[right]]++;
            if(mp[nums[right]] > 1)
                return true;
            right++;
        }
        return false;
    }
};