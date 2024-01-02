class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++)
        {
            vector<int> ds;
            for(int j=0;j<nums.size();j++)
            {
                if(find(ds.begin(),ds.end(),nums[j])!=ds.end() || nums[j]==-1)
                {
                    continue;
                }
                else
                {
                    ds.push_back(nums[j]);
                    nums[j]=-1;
                }
            }
            if(ds.empty())
                break;
            else
                ans.push_back(ds);
        }
        return ans;
    }
};