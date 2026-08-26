class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int l = 0, r = n - 1;
        while(l < r) {
            s[l] = s[l] ^ s[r];
            s[r] = s[l] ^ s[r];
            s[l] = s[l] ^ s[r];
            l++;
            r--;
        }
    }
};