//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string s, string t) {
        // code here
        int n=s.size(),m=t.size();
        int i=0,j=0,f=1;
        string sum="";
        while(i<n and j<m){
            if(isalpha(t[j])){
                if(s[i]!=t[j]){
                    return 0;
                }
                else{
                    //cout<<s[i]<<" ";
                    i++;
                }
                sum="";
            }
            else{
                if(isdigit(t[j+1])){
                    sum+=t[j];
                }
                else{
                sum+=t[j];
                i+=stoi(sum);
                //cout<<sum<<" ";
                if(i==n-1 and j==m-1) return 1;
                if(i>n) return 0; 
                }
            }
            j++;
        }
        return 1;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends