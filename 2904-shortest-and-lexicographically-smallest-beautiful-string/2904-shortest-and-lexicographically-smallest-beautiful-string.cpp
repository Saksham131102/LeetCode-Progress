class Solution {
public:
    string shortestBeautifulSubstring(string s, int K) {
        int n = s.size();
        int l = 0, r = 0;
        int minLen = 102;
        int k = K;
        while(r < n) {
            if(s[r] == '1')
                k--;
            while(k == 0) {
                minLen = min(minLen, r - l + 1);
                if(s[l] == '1')
                    k++;
                l++;
            }
            r++;
        }
        if(minLen == 102)
            return "";
        set<string> st;
        k = K;
        for(int i=0;i<minLen;i++) {
            if(s[i] == '1')
                k--;
        }
        l = 0;
        r = minLen;
        while(r <= n) {
            if(k == 0)
                st.insert(s.substr(l, minLen));
            if(r == n)
                break;
            if(s[r] == '1')
                k--;
            if(s[l] == '1')
                k++;
            l++;
            r++;
        }
        if(st.empty())
            return "";
        auto it = st.begin();
        return *(it);
    }
};