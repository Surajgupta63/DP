// ---BruteForce-TLE----
class Solution {
public:
    int solve(int n){
        if(n==0) return 1;
        if(n < 0) return 0;

        return (solve(n-1) + solve(n-2));
    }
    int climbStairs(int n) {
        return solve(n);
    }
};

// Approach--1 using DP + Memoization
class Solution {
public:
    int solve(int n, vector<int> &dp){
        if(n==0) return 1;
        if(n < 0) return 0;

        if(dp[n] != -1) return dp[n];

        return dp[n] = solve(n-1, dp) + solve(n-2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);

        return solve(n, dp);
    }
};

// Approach--2 using DP + Tabulation
class Solution {
public:

    int climbStairs(int n) {
        
        if(n < 3) return n;

        vector<int> dp(n+1, 0);

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for(int i=3; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};

// Approach--3 Space Optimaztion

class Solution {
public:

    int climbStairs(int n) {
        
        if(n < 3) return n;

        int a = 1;
        int b = 2;
        for(int i=3; i<=n; i++){
            int c = a + b;
            a = b;
            b = c;
        }

        return b;
    }
};

