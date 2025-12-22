class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();
        int n = strs[0].size();

        vector<int> dp(n, 1); // each column alone

        for (int j = 0; j < n; j++) {
            for (int i = 0; i < j; i++) {
                bool ok = true;
                for (int k = 0; k < m; k++) {
                    if (strs[k][i] > strs[k][j]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }

        int maxKeep = 0;
        for (int x : dp) maxKeep = max(maxKeep, x);

        return n - maxKeep;
    }
};
