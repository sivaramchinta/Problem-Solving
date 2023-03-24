//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string s) {
        // code here
        int i=0,j=s.size()-1;
        vector<int>arr(26,0);
        int c=0,f=1;
        for(char ch:s) arr[ch-'a']++;
        string first="",last="";
        while(i<=j){
            char ch;
            if(f) ch=s[i++];
            else ch=s[j--];
            if(arr[ch-'a']>1){
                arr[ch-'a']--;
                c++;
                if(f==0) f=1;
                else f=0;
            }
            else{
                if(f) first+=ch;
                else last=ch+last;
            }
        }
        string res=first+last;
        if(c%2==1) reverse(res.begin(),res.end());
        return res;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends