class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;
        for(const int &num : nums)
            st.insert(num);
        for(int i=1;;i++) {
            if(!st.count(k * i))
                return k * i;
        }
        return -1;
    }
};