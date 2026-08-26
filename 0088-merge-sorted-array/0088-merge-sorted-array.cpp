class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = 0, p2 = 0;
        vector<int> mergedArr;
        while(p1 < m && p2 < n) {
            if(nums1[p1] <= nums2[p2])
                mergedArr.push_back(nums1[p1++]);
            else
                mergedArr.push_back(nums2[p2++]);
        }
        while(p1 < m)
            mergedArr.push_back(nums1[p1++]);
        while(p2 < n)
            mergedArr.push_back(nums2[p2++]);
        for(int i=0;i<(m+n);i++)
            nums1[i] = mergedArr[i];
    }
};