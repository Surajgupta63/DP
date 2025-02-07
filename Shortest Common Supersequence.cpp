// Recursion + Memoization
// T.C : O(M*N)
// S.C : O(M*N)
class Solution {
  public:
    int dp[501][501];
    int solve(string& s1, string &s2, int m, int n){
        
        if(m == 0 || n == 0){
            return m+n;
        }
        
        if(dp[m][n] != -1) return dp[m][n];
        
        if(s1[m-1] == s2[n-1]){
            return dp[m][n] = 1 + solve(s1, s2, m-1, n-1);
        }
        
        return dp[m][n] = 1 + min(solve(s1, s2, m-1, n), solve(s1, s2, m, n-1));
    }
    int shortestCommonSupersequence(string &s1, string &s2) {
        memset(dp, -1, sizeof(dp));
        return solve(s1, s2, s1.length(), s2.length());
    }
};
