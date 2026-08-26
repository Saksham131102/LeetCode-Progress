class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(char ch : s) {
            if(('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || ('0' <= ch && ch <= '9'))
                str.push_back(ch);
        }
        for(char &ch : str)
            ch = tolower(ch);
        int n = str.size();
        int l = 0, r = n - 1;
        while(l < r) {
            if(str[l] != str[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};