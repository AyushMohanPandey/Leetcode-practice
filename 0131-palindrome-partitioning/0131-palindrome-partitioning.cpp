class Solution {
public:
    bool isPal(string s,int start,int end)
    {
        while(start<=end)
        {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
    void helper(vector<vector<string>> &ans, vector<string> &ds, string s, int index)
    {
        if(index == s.size())
        {
            ans.push_back(ds);
            return;
        }
        for(int i=index;i<s.size();i++)
        {
            if(isPal(s, index, i))
            {
                ds.push_back(s.substr(index,i-index+1));
                helper(ans, ds, s, i+1);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        helper(ans, ds, s, 0);
        return ans;
    }
};