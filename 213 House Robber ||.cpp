// Approach--1 DP+Memoization
class Solution {
public:
    int dp[101];
    int solve(int i, int n, vector<int>& nums){
        if(i > n) return 0;
        if(dp[i] != -1) return dp[i];

        int pick    = nums[i] + solve(i+2, n, nums);
        int notPick = solve(i+1, n, nums);

        return dp[i] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==1) return nums[0];

        memset(dp, -1, sizeof(dp));
        int firstPart = solve(0, n-2, nums);
        
        memset(dp, -1, sizeof(dp));
        int secondPart = solve(1, n-1, nums);

        return max(firstPart, secondPart);
    }
};
