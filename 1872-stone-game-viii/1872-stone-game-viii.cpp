class Solution {
private:
    int solve(int idx, int n, vector<int> &P, vector<int> &DP) {
        // base case
        if(idx == n-1)
            return P[n-1];
        // recursive relation
        if(DP[idx] != -1)
            return DP[idx];
        // 2 choices
        // not pick
        int notPick = 0 + solve(idx+1, n, P, DP);
        // pick
        int pick = P[idx] - solve(idx+1, n, P, DP);
        return DP[idx] = max(notPick, pick);
    }
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefixSum;
        int sum = 0;
        for(int i=0;i<n;i++) {
            sum += stones[i];
            prefixSum.push_back(sum);
        }

        vector<int> dp(n, 0);
        dp[n-1] = prefixSum[n-1];
        for(int i=n-2;i>=1;i--) {
            int notPick = 0 + dp[i+1];
            int pick = prefixSum[i] - dp[i+1];
            dp[i] = max(notPick, pick);
        }
        // return solve(1, n, prefixSum, dp);
        return dp[1];
    }
};