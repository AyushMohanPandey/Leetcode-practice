class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
    constexpr int kMod = 1'000'000'007;
    const int n = arr.size();
    long ans = 0;
    // prevMin[i] := index k s.t. arr[k] is the previous minimum in arr[:i]
    vector<int> prevMin(n, -1);
    // nextMin[i] := index k s.t. arr[k] is the next minimum in arr[i + 1:]
    vector<int> nextMin(n, n);
    stack<int> stack;

    for (int i = 0; i < n; ++i) {
      while (!stack.empty() && arr[stack.top()] > arr[i]) {
        const int index = stack.top();
        stack.pop();
        nextMin[index] = i;
      }
      if (!stack.empty())
        prevMin[i] = stack.top();
      stack.push(i);
    }

    for (int i = 0; i < n; ++i) {
      ans += static_cast<long>(arr[i]) * (i - prevMin[i]) * (nextMin[i] - i);
      ans %= kMod;
    }

    return ans;
  }
    // void helper(vector<vector<int>> &ans, vector<int> &ds, vector<int> &arr, int i)
    // {
    //     if(i >= arr.size())
    //     {
    //         ans.push_back(ds);
    //         return;
    //     }
    //     ds.push_back(arr[i]);
    //     helper(ans, ds, arr, i+1);
    //     ds.pop_back();
    //     helper(ans, ds, arr, i+1);
    //     return;
    // }
    // int sumSubarrayMins(vector<int>& arr) {
    //     vector<vector<int>> ans;
    //     vector<int> ds;
    //     helper(ans, ds , arr, 0);
    //     sort(ans.begin(),ans.end());
    //     int sum = 0;
    //     for(int i=1;i<ans.size();i++)
    //     {
    //         sort(ans[i].begin(),ans[i].end());
    //         sum += ans[i][0];
    //     }
    //     return sum;
    // }
};