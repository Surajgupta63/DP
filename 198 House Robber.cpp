// BruteForce-- TLE ---
class Solution {
public:
    int solve(int i, vector<int>& nums){
        if(i >= nums.size()) return 0;

        int pick    = nums[i] + solve(i+2, nums);
        int notPick = solve(i+1, nums);

        return max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        return solve(0, nums);
    }
};

// Approach--1 DP+Memoization
class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int> &dp){
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int pick    = nums[i] + solve(i+2, nums, dp);
        int notPick = solve(i+1, nums, dp);

        return dp[i] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return solve(0, nums, dp);
    }
};
