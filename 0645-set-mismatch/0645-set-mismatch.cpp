class Solution {
public:
    vector<int> findErrorNums(vector<int> &nums){
        int n = nums.size();
        vector<int> count(n+1,0);
        vector<int> ans;
        for (auto i: nums){
            count[i]++;
            if (count[i] > 1)
                ans.push_back(i);
        }
        for(int i=1; i<count.size()+1; i++)
        {
            if( count[i] == 0)
            {
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
    // vector<int> findErrorNums(vector<int>& nums) {
    //     vector<int> ans;
    //     sort(nums.begin(),nums.end());
    //     for(int i=0; i<nums.size(); i++)
    //     {
    //         if(nums[i] == nums[i+1])
    //         {
    //             ans.push_back(nums[i]);
    //             if(nums[i+1] == nums.size())
    //             {
    //                 ans.push_back(nums[i]-1);
    //             }
    //             else
    //             {
    //                 ans.push_back(nums[i]+1);
    //             }
    //             break;
    //         }
    //     }
    //     return ans;
    // }
};