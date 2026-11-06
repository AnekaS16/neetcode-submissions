class Solution {
public:
    void solve(int index, int target, vector<int>& nums,
               vector<int>& ds, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        for (int i = index; i < nums.size(); i++) {

            // Pruning
            if (nums[i] > target)
                continue;

            // Pick
            ds.push_back(nums[i]);

            // Same index because reuse is allowed
            solve(i, target - nums[i], nums, ds, ans);

            // Backtrack
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        vector<vector<int>> ans;
        vector<int> ds;

        //sort(nums.begin(), nums.end());

        solve(0, target, nums, ds, ans);

        return ans;
    }
};