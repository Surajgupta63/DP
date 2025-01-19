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
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];

        int pick    = nums[i] + solve(i-2, nums, dp);
        int notPick = solve(i-1, nums, dp);

        return dp[i] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return solve(nums.size()-1, nums, dp);
    }
};

// Approach--2 DP+Tabulation
class Solution {
public:
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0];

        vector<int> dp(nums.size()+1, 0);

        dp[0] = 0;
        dp[1] = nums[0];

        for(int i=2; i<=n; i++){
            int pick    = nums[i-1] + dp[i-2];
            int notPick = dp[i-1];
            dp[i] = max(pick, notPick);
        }
        
        return dp[n];


    }
};
