// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        /*if(n==1)
        {
            if(isBadVersion(n))
            {
                return 1;
            }
        }
        */
        int start = 1;
        int end = n;
        //vector<int> ls;
        int min=0;
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            bool a = isBadVersion(mid);
            if(a == true)
            {
                //ls.push_back(mid);
                min = mid;
                end = mid-1;
            }
            else if(a == false)
            {
                start = mid+1;
            }
            else
                end = mid-1;
        }
        //int min = *min_element(ls.begin(), ls.end());
        return min;
    }
};