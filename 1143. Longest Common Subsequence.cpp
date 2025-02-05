// Approach-1 Using Recursion + Memoization
// T.C : O(M*N)
// S.C : O(M*N)
class Solution {
public:
    int dp[1001][1001];

    int solve(string text1, string text2, int i, int j){
        if(i >= text1.length() || j >= text2.length()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(text1[i] == text2[j]){
            return dp[i][j] = 1 + solve(text1, text2, i+1, j+1);
        }
        
        return dp[i][j] = max(solve(text1, text2, i+1, j), solve(text1, text2, i, j+1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        return solve(text1, text2, 0, 0);
    }
}; 

// Approach-2 Using Tabualtion
// T.C : O(M*N)
// S.C : O(M*N)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1));

        for(int row=0; row<m; row++){
            dp[row][0] = 0;
        }
        for(int col=0; col<n; col++){
            dp[0][col] = 0;
        }

        for(int row=1; row<=m; row++){
            for(int col=1; col<=n; col++){
                if(text1[row-1] == text2[col-1]){
                    dp[row][col] = 1 + dp[row-1][col-1];
                }else{
                    dp[row][col] = max(dp[row-1][col], dp[row][col-1]);
                }
            }
        }
        return dp[m][n];
    }
};


// Printing Longest Common Subsequence
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1));

        for(int row=0; row<=m; row++){
            dp[row][0] = 0;
        }
        for(int col=0; col<=n; col++){
            dp[0][col] = 0;
        }

        for(int row=1; row<=m; row++){
            for(int col=1; col<=n; col++){
                if(text1[row-1] == text2[col-1]){
                    dp[row][col] = 1 + dp[row-1][col-1];
                }else{
                    dp[row][col] = max(dp[row-1][col], dp[row][col-1]);
                }
            }
        }

        // printing longest common subsequence
        string lcs = "";
        int i = m, j = n;

        while(i > 0 && j > 0){
            if(text1[i-1] == text2[j-1]){
                lcs += text1[i-1];
                i--; j--;
            }else{
                if(dp[i-1][j] > dp[i][j-1]){
                    i--;
                }else{
                    j--;
                }
            }
        }

        reverse(begin(lcs), end(lcs));
        cout<<lcs;

        return dp[m][n];
    }
};
