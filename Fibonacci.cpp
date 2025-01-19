
// Approach --- 1
class Solution {
public:
    int solve(int n, vector<int> &dp){
        if(n == 1 || n == 0) return n;
        if(dp[n] != -1) return dp[n];

        return dp[n] = solve(n-1, dp) + solve(n-2, dp);
    }
    int fib(int n) {

        if(n < 1) return 0;
        vector<int> dp(n+1, 0);
        return solve(n, dp);

};


// Approach --- 2
class Solution {
public:
    int fib(int n) {
        if(n < 1) return 0;
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = 1;
      
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

// Approach --- 3
class Solution {
public:
    int fib(int n) {
        if(n < 1) return 0;
        int prev = 0;
        int curr = 1;
      
        for(int i=2; i<=n; i++){
            int temp = prev + curr;
            prev = curr;
            curr = temp;
        }
        return curr;
    }
};
