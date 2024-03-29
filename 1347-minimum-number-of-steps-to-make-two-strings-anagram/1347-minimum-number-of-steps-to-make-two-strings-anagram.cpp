class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>m;
        int sum=0;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
            m[t[i]]--;
        }
        for(auto i:m){
            if(i.second<0)
                sum += i.second;
        }
        return abs(sum);
    }
};