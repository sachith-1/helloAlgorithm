#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	    ull dp[n];
	    // here dp[i] stores the number of ugly numbers till i+1th number.
	    // these are the subproblems.
	    
	    dp[0]=1;
	    // dp[0] is the number of ugly numbers till N=1.
	    // dp[n-1] is the number of ugly numbers till N.
	    
	    ull p2=0, p3=0, p5=0;
	    // p2, p3, p5 tracks the factors count for 2,3,5
	    // intially for N=1, 1 has no factors in 2/3/5. so all 3 are initially 0.
	    // ugly number is the one which has all factors as 2/3/5 only.

		// p2, p3, p5 tracks the factors count for 2,3,5 i.e if a number has only '2' factor  
		//then p2 count increases and if a number has '2' & '3' as  factor  then p2 and p3 count increases.
	    
	    for(int i=1;i<n;i++)
	    {
	        dp[i] = min({dp[p2]*2, dp[p3]*3, dp[p5]*5});
	        
	        // if n==2
	        // dp[0] = 1
	        // dp[1] = min(dp[0]*2, dp[0]*3, dp[0]*5) = 2
	        // dp[2] = min(dp[1]*2, dp[0]*3, dp[0]*5) = 4
	        
	        if(dp[i]==dp[p2]*2) p2++;
	        // if the current number has a multiple 2 then p2 increases as p2 keeps track of count of 2s (in factors of number i+1).
	        
	        if(dp[i]==dp[p3]*3) p3++;
	        // if the current number has a multiple 3 then p3 increases as p3 keeps track of count of 3s (in factors of number i+1).
	        
	        if(dp[i]==dp[p5]*5) p5++;
	        // if the current number has a multiple 5 then p5 increases as p5 keeps track of count of 5s (in factors of number i+1).
	    }
	    
	    return dp[n-1]; // return the #ugly numbers of n.
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends