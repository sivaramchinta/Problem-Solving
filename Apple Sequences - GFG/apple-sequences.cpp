//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string arr){
        // code her
        int i=0,j=0,res=0;
        while(j<n){
            if(arr[j]=='O' and m>0){
                m--;
            }
            else{
                if(arr[j]=='O'){
                    while(arr[i]!='O'){
                        i++;
                    }
                    i++;
                }
            }
            res=max(res,j-i+1);
            j++;
        }
        return res;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends