class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        int count =0;
        for(int i=0;i<nums.size();i++)
            {
                mp[nums[i]]++;
            }
        for(auto i: mp)
        {
            if(i.second == 1)
                return -1;
            count += i.second/3;
            if(i.second % 3)count++;
        }     
        return count;
    }
};