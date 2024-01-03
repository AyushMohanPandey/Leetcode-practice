class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int res=0, prev=0;
        for(int i=0; i<bank.size(); i++)
        {
            int cur = count(begin(bank[i]), end(bank[i]), '1');
            if(cur!=0)
            {
                res += prev*cur;
                prev = cur;
            }
        }
        return res;
    }
};