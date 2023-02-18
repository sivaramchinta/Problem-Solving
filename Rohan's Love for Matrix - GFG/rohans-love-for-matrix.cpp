//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    int firstElement(int n) 
    {
        // code here
        if(n<=2) return 1;
        int a=0;
        int b=1;
        int c=0;
        n--;
        while(n){
            c=(a+b)%1000000007;
            a=b;
            b=c;
            n--;
            
        }
        return c%1000000007;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n;
        cin >> n ;
        Solution ob;
        cout<<ob.firstElement(n)<<endl;
    }
    return 0;
}

// } Driver Code Ends