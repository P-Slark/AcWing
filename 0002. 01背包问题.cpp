//二维
#include<bits/stdc++.h>
using namespace std;
#define MAX 1005
int v[MAX];
int w[MAX];
int main(){
    int N,V;
    cin>>N>>V;
    for(int i = 1;i <= N;i++)
        cin>>w[i]>>v[i];
    vector<vector<int>> dp(N+1,vector<int>(V+1,0));
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<V+1;j++){
            if(j<w[i])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j-w[i]]+v[i],dp[i-1][j]);
        }
    }
    cout<<dp[N][V]<<endl;
    return 0;
}

//一维
#include<bits/stdc++.h>
using namespace std;
#define MAX 1005
int v[MAX];
int w[MAX];
int main(){
    int N,V;
    cin>>N>>V;
    for(int i = 1;i <= N;i++)
        cin>>w[i]>>v[i];
    vector<int> dp(V+1,0);
    for(int i = 1;i<N+1;i++){
        for(int j = V;j>=1;j--){
            if(j>=w[i])
                dp[j] = max(dp[j-w[i]]+v[i],dp[j]);
        }
    }
    cout<<dp[V]<<endl;
    return 0;
}
