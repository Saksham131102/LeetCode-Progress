class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-2;i++) {
            if(i > 0 && nums[i-1] == nums[i])
                continue;
            int idx = i;
            int target = -nums[idx];
            int left = idx+1;
            int right = n-1;
            while(left < right) {
                if(nums[left] + nums[right] == target) {
                    ans.push_back({nums[idx], nums[left], nums[right]});
                    while(left+1 < right && nums[left] == nums[left + 1])
                        left++;
                    while(left < right - 1 && nums[right - 1] == nums[right])
                        right--;
                    left++;
                    right--;
                }
                else if(nums[left] + nums[right] < target)
                    left++;
                else if(nums[left] + nums[right] > target)
                    right--;
            }
        }
        return ans;
    }
};