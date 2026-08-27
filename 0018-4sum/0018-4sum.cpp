class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int a=0;a<n-3;a++) {
            if(a>0 && nums[a-1] == nums[a])
                continue;
            for(int b=a+1;b<n-2;b++) {
                if(b>a+1 && nums[b-1] == nums[b])
                    continue;
                long long newTarget = target - 1LL*nums[a] - 1LL*nums[b];
                int c = b+1;
                int d = n-1;
                while(c < d) {
                    if(nums[c] == newTarget - 1LL*nums[d]) {
                        ans.push_back({nums[a], nums[b], nums[c], nums[d]});
                        while(c+1<d && nums[c] == nums[c+1])
                            c++;
                        while(c<d-1 && nums[d-1] == nums[d])
                            d--;
                        c++;
                        d--;
                    }
                    else if(nums[c] > newTarget - 1LL*nums[d])
                        d--;
                    else if(nums[c] < newTarget - 1LL*nums[d])
                        c++;
                }
            }
        }
        return ans;
    }
};