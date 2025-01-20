// Approach--1 Recursion + Memoization
class Solution {
public:
    long long dp[100001][2];

    long long solve(int i, bool sign, vector<int>& nums){
        if(i >= nums.size()) return 0;

        if(dp[i][sign] != -1) return dp[i][sign];

        long long notPick  = solve(i+1, sign, nums);

        long long val = (sign == false) ? -nums[i] : nums[i];

        long long pick = val + solve(i+1, !sign, nums);
        
        return dp[i][sign] = max(pick, notPick);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, true, nums);
    }
};

// Approach--2 Tabualtion
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<long long>> dp(n+1, vector<long long>(2, 0));

        for(int i=1; i<=n; i++){
            dp[i][0] = max(dp[i-1][1] - nums[i-1], dp[i-1][0]);
            dp[i][1] = max(dp[i-1][0] + nums[i-1], dp[i-1][1]);
        }

        return max(dp[n][0], dp[n][1]);
    }
};
