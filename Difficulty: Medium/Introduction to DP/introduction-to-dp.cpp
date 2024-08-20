//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int m = 1e9+7;
    long long int td(long long int n, vector <long long int> &dp)
    {
        if(n<=1) return n;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = td(n-1,dp) % m + td(n-2,dp) % m;
    }
    long long int topDown(int n) {
        long long s = n;
        vector<long long int> dp(n+1,-1);
        return td(s,dp) % m;
    }
    long long int bottomUp(int n) {
        if(n<=1) return n;
        long long int k = n;
        vector<long long int> dp(n+1,-1);
        long long int prev2 = 0;
        long long int prev = 1;
        for(long long int i=2;i<=k;i++)
        {
            dp[i] = (prev + prev2) % m;
            prev2 = prev % m;
            prev = dp[i] % m;
        }
        return dp[k] % m;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends