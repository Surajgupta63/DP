// Using Recursion + Memoization
// T.C : O(N^2)
// S.C : O(N^2)
class Solution {
public:
    int n;
    int dp[1001][1001];
    int solve(int i, int p, vector<vector<int>>& pairs){
        if(i >= n) return 0;
        if(p != -1 && dp[i][p] != -1) return dp[i][p];

        int take = 0;
        if(p == -1 || pairs[p][1] < pairs[i][0]){
            take = 1 + solve(i+1, i, pairs);
        }

        int skip = solve(i+1, p, pairs);

        if(p != -1)
            dp[i][p] = max(take, skip);

        return max(take, skip);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        n = pairs.size();
        memset(dp, -1, sizeof(dp));

        sort(pairs.begin(), pairs.end());

        return solve(0, -1, pairs);
    }
};
