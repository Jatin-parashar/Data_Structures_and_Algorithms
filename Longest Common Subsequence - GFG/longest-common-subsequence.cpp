// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings
    
    int l(int x,int y,string s1,string s2,int i,int j, vector<vector<int>> &dp){
        if(i==x or j==y){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=1+l(x,y,s1,s2,i+1,j+1,dp);
        return dp[i][j]=max(l(x,y,s1,s2,i+1,j,dp),l(x,y,s1,s2,i,j+1,dp));
    }
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        vector<vector<int>> dp(x,vector<int>(y,-1));
        
        return l(x,y,s1,s2,0,0,dp);
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends