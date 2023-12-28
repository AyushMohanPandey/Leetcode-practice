class Solution {
public:
    int calPoints(vector<string>& s) {
        stack<int> st;
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == "+")
            {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.push(num1);
                st.push(num1+num2);
            }
            else if(s[i] == "C")
            {
                st.pop();
            }
            else if(s[i] == "D")
            {
                st.push(st.top()*2);
            }
            else 
            {
                st.push(stoi(s[i]));
            }
        }
        while(st.size() != 0)
        {
            ans += st.top();
            st.pop();
        }
        return ans;

    }
};