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

// Approach--1 using DP
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

