class Solution {
public:
    bool makeEqual(vector<string>& words) {
        string s;
        unordered_map<char,int> mp;
        for(int i=0;i<words.size();i++)
        {
            s = words[i];
            for(int j=0;j<s.size();j++)
            {
                mp[s[j]]++;
            }
        }
        int n = words.size();
        for (auto a : mp) {
            if (a.second % n != 0) {
                return false;
            }
        }
        return true;
    }
};