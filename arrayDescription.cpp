#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pyes cout << "YES" << "\n";
#define pno cout << "NO" << "\n";
#define br cout << "\n";
 
int mod =  1e9 + 7;
 
int recursion(int i, int n, vector<int> &arr, int last, int m, vector<vector<int>> &dp){
    if(i == n){
        return 1;
    }
    if(dp[i][last] != -1){
        return dp[i][last];
    }
    int ans = 0;
    if(arr[i] == 0){
        for(int j = 1; j <= m; j++){
            if(i == 0 || abs(last - j) <= 1){
                ans = (ans + recursion(i+1, n, arr, j, m, dp)) % mod;
            }
        }
    }else{
        if(i != 0 && abs(last - arr[i]) > 1){
            return 0;
        }else{
            ans = (ans + recursion(i+1, n, arr, arr[i], m, dp)) % mod;
        }
    }
    return dp[i][last] = ans;
}
 
void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for(auto &v : arr){
        cin >> v;
    }
    vector<vector<int>> dp(n+2, vector<int>(m+2, 0));
    for(int i = 1; i <= m; i++){
        dp[n][i] = 1;
    }
    for(int i = n-1; i > 0; i--){
        for(int j = 1; j <= m; j++){
            if(arr[i] == 0){
                dp[i][j] = ((dp[i+1][j+1] + dp[i+1][j]) % mod + dp[i+1][j-1]) % mod;
            }else{
                if(abs(arr[i] - j) <= 1){
                    dp[i][j] = dp[i+1][arr[i]];
                }
            }
        }
    }
    int ans = 0;
    if(arr[0] == 0){
        for(int i = 1; i <= m; i++){
            ans = (ans + dp[1][i]) % mod;
        }
    }else{
        ans = dp[1][arr[0]];
    }
    cout << ans << endl;
}
 
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    //code here
 
    solve();
 
    //end
 
    return 0;
 
}
