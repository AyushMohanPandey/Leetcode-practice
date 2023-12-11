class Solution {
public:
    void helper(int i, int sum, vector<int>& arr, int target, vector<vector<int>> &ans, vector<int> &ds)
    {
        //base condition
        if(sum == target){
            ans.push_back(ds);
            return;
        }
        //pick the element
        if(sum>target)
            return;
        if(i>=arr.size())
            return;
        //include current element    
        ds.push_back(arr[i]);
        sum += arr[i];
        helper(i,sum,arr,target,ans,ds);
        
        //remove current element from ds and sum for not include recursion
        ds.pop_back();
        sum -= arr[i];
        //do not incude current element
        helper(i+1,sum,arr,target,ans,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int sum=0;
        helper(0,sum,candidates,target,ans,ds);
        return ans;
    }
};