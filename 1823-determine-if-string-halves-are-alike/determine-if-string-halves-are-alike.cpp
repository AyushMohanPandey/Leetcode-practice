class Solution {
public:
    bool halvesAreAlike(string s) {
        //string a,b;
        int l = s.length();
        int c=0,d=0;
        /*for(int i=0;i<l;i++)
        {
            if(i > l/2)
                b=s[i];
            else
                a=s[i];
        }*/
        string a = s.substr(0, l/2);
        string b = s.substr(l/2);
        for(int i=0;i<a.length();i++)
        {
            if(a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u' || a[i]=='A' || a[i]=='E' || a[i]=='I' || a[i]=='O' || a[i]=='U' )
                c++;
            if(b[i]=='a' || b[i]=='e' || b[i]=='i' || b[i]=='o' || b[i]=='u' || b[i]=='A' || b[i]=='E' || b[i]=='I' || b[i]=='O' || b[i]=='U' )
                d++;
        }
        if(c==d)
            return true;
        else
            return false;
    }
};