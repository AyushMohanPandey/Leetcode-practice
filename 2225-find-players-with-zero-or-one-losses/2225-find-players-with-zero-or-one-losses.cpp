class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> lose;
        for(auto x : matches ){
            lose[x[1]]++;
            lose[x[0]] = lose[x[0]];
        }
        vector<int> zero, ones;
        for (auto[k,l] : lose)
        {
            if (l == 0) zero.push_back(k);
            if (l == 1) ones.push_back(k);
        }
        
        return {zero,ones};
    }
};