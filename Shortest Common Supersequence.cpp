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

// Tabulation
// T.C : O(M*N)
// S.C : O(M*N)
class Solution {
  public:
    int shortestCommonSupersequence(string &s1, string &s2) {
        int m = s1.length();
        int n = s2.length();
        
        int dp[m+1][n+1];
        
        for(int i=0; i<=m; i++){
            for(int j=0; j<=n; j++){
                if(i==0 || j==0){
                    dp[i][j] = i+j;
                }
                else if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[m][n];
    }
};

// Using Tabulation Of LCS(Longest Increasing Subsequence)
// T.C : O(M*N)
// S.C : O(M*N)
class Solution {
  public:
    int shortestCommonSupersequence(string &s1, string &s2) {
        int m = s1.length();
        int n = s2.length();
        
        int dp[m+1][n+1];
        
        for(int i=0; i<=m; i++){
            for(int j=0; j<=n; j++){
                if(i==0 || j==0){
                    dp[i][j] = 0;
                }
                else if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        int lcs = dp[m][n];
        
        int rem_char_s1 = m - lcs;
        int rem_char_s2 = n - lcs;
        
        return lcs + rem_char_s1 + rem_char_s2;
    }
};
