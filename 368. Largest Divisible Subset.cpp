// Approach-1 Using Recursion (TLE)
// T.C : O(2^N)
// S.C : O(2N)
class Solution {
public:
    void solve(vector<int>& nums, int i, int prev, vector<int> &temp, vector<int> &result){
        if(i >= nums.size()){
            if(temp.size() > result.size()){
                result = temp;
            }
            return;
        }

        if(prev == -1 || nums[i] % prev == 0){
            temp.push_back(nums[i]);
            solve(nums, i+1, nums[i], temp, result);
            temp.pop_back();
        }

        solve(nums, i+1, prev, temp, result);
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> result;
        vector<int> temp;

        solve(nums, 0, -1, temp, result);

        return result;
    }
};
