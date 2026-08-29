class Solution {
public:
    vector<int> parent;
    vector<int> size;
    int findUParent(int i) {
        if(parent[i] == i)
            return i;
        return parent[i] = findUParent(parent[i]);
    }
    void unionBySize(int i, int j) {
        int ulp_i = findUParent(i);
        int ulp_j = findUParent(j);

        if(ulp_i == ulp_j)
            return;
        
        if(size[ulp_i] > size[ulp_j]) {
            parent[ulp_j] = ulp_i;
            size[ulp_i] += size[ulp_j];
        }
        else {
            parent[ulp_i] = ulp_j;
            size[ulp_j] += size[ulp_i];
        }
    }
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        size.resize(n, 1);
        parent.resize(n);

        for(int i=0;i<n;i++)
            parent[i] = i;
        
        vector<pair<int, int>> temp;

        for(int i=0;i<n;i++) {
            temp.push_back({nums[i], i});
        }

        sort(temp.begin(), temp.end());

        for(int i=0;i<n-1;i++) {
            int x = temp[i].first;
            int x_i = temp[i].second;
            int y = temp[i+1].first;
            int y_i = temp[i+1].second;
            if(y - x <= limit) {
                unionBySize(x_i, y_i);
            }
        }

        unordered_map<int, vector<pair<int, int>>> mp;

        for(int i=0;i<n;i++) {
            int ulp = parent[i];
            mp[ulp].push_back({nums[i], i});
        }

        vector<int> ans = nums;

        for(auto it : mp) {
            vector<pair<int, int>> temp = it.second;

            vector<int> a, b;
            for(int i=0;i<temp.size();i++) {
                a.push_back(temp[i].first);
                b.push_back(temp[i].second);
            }

            sort(a.begin(), a.end());
            sort(b.begin(), b.end());

            for(int i=0;i<a.size();i++) {
                ans[b[i]] = a[i];
            }
        }

        return ans;
    }
};