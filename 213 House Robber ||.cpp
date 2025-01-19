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


// Approach--1 DP+Tabualtion
class Solution {
public:

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==1) return nums[0];

        int dp[101];

        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        dp[1] = nums[0];

        for(int i=2; i<=n-1; i++){
            int pick = nums[i-1] + dp[i-2];
            int notPick = dp[i-1];
            dp[i] = max(pick, notPick); 
        }

        int firstPart = dp[n-1];
   
        memset(dp, -1, sizeof(dp));
        dp[1] = 0;
        dp[2] = nums[1];

        for(int i=3; i<=n; i++){
            int pick = nums[i-1] + dp[i-2];
            int notPick = dp[i-1];
            dp[i] = max(pick, notPick); 
        }

        int secondPart = dp[n];

        return max(firstPart, secondPart);
    }
};
