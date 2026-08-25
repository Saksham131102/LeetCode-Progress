class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = INT_MIN;
        int candidate2 = INT_MIN;
        int count1 = 0;
        int count2 = 0;
        int n = nums.size();

        for(const int &num : nums) {
            if(count1 == 0 && num != candidate2) {
                candidate1 = num;
                count1 = 1;
            }
            else if(count2 == 0 && num != candidate1) {
                candidate2 = num;
                count2 = 1;
            }
            else if(num == candidate1) {
                count1++;
            }
            else if(num == candidate2) {
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;

        for(const int &num : nums) {
            if(num == candidate1)
                count1++;
            if(num == candidate2)
                count2++;
        }

        vector<int> ans;
        if(count1 > n/3)
            ans.push_back(candidate1);
        if(count2 > n/3)
            ans.push_back(candidate2);
        return ans;
    }
};