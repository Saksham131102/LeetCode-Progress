class Solution {
private:
    string getMaxString(vector<int> &freq) {
        string res;
        for(int i=25;i>=0;i--)
            res.append(freq[i], i+'a');
        return res;
    }

    string getMinString(vector<int> &freq) {
        string res;
        for(int i=0;i<26;i++)
            res.append(freq[i], i+'a');
        return res;
    }

    bool canFormGreater(vector<int> &freq, string &target, int start) {
        string maxStr = getMaxString(freq);
        string suffix = target.substr(start);
        return maxStr > suffix;
    }
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26, 0);
        for(char ch : s)
            freq[ch - 'a']++;
        string ans = "";
        int n = target.size();
        for(int i=0;i<n;i++) {
            int targetChar = target[i] - 'a';

            if(freq[targetChar] > 0) {
                freq[targetChar]--;

                if(canFormGreater(freq, target, i+1)) {
                    ans.push_back(target[i]);
                    continue;
                }

                freq[targetChar]++;
            }

            for(int j=targetChar+1;j<26;j++) {
                if(freq[j] > 0) {
                    freq[j]--;
                    ans.push_back(j+'a');
                    ans += getMinString(freq);
                    return ans;
                }
            }

            return "";
        }

        return "";
    }
};