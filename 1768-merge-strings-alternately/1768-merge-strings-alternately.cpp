class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        int p1 = 0, p2 = 0;
        string ans = "";
        while(p1 < n1 && p2 < n2) {
            ans.push_back(word1[p1++]);
            ans.push_back(word2[p2++]);
        }
        while(p1 < n1)
            ans.push_back(word1[p1++]);
        while(p2 < n2)
            ans.push_back(word2[p2++]);
        return ans;
    }
};