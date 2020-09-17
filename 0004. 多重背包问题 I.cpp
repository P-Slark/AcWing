//
#include<bits/stdc++.h>
using namespace std;
int v[105];
int w[105];
int s[105];
int dp[105][105];

int main(){
    int n,V;
    cin>>n>>V;
    for(int i = 1;i<=n;i++){
        cin>>v[i]>>w[i]>>s[i];
    }
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<=V;j++){
            for(int k = 0;k<=s[i];k++){
                if(j>=k*v[i])
                    dp[i][j] = max(dp[i][j],dp[i-1][j-k*v[i]]+k*w[i]);
            }
        }
    }
    cout<<dp[n][V];
    return 0;
}

//
#include<bits/stdc++.h>
using namespace std;
int dp[105];

int main(){
    int n,V;
    cin>>n>>V;
    for(int i = 1;i<=n;i++){
        int v,w,s;
        cin>>v>>w>>s;
        for(int j = V;j>=v;j--){
            for(int k = 0;k<=s&&k*v<=j;k++){
                dp[j] = max(dp[j],dp[j-k*v]+k*w);
            }
        }
    }
    cout<<dp[V];
    return 0;
}
