//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> addOne(int arr[], int n) {
        // code here
        int carry=1;
        reverse(arr,arr+n);
        vector<int>v;
        for(int i=0;i<n;i++){
            if(arr[i]+carry>=10){
                v.push_back((arr[i]+carry)%10);
            }
            else{
                v.push_back(arr[i]+carry);
                carry=0;
            }
        }
        while(carry--){
            v.push_back(1);
        }
        reverse(v.begin(),v.end());
        return v;
       
    }
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.addOne(a, n);
        printAns(ans);
    }
    return 0;
}
// } Driver Code Ends