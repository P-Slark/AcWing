//三层循环dp
#include<bits/stdc++.h>
using namespace std;
#define MAX 1005
int v[MAX];
int w[MAX];

int main(){
    int N,V;
    cin>>N>>V;
    for(int i = 1;i <= N;i++)
        cin>>v[i]>>w[i];//体积 价值
    vector<vector<int>> dp(N+1,vector<int>(V+1,0));
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<V+1;j++){
            for(int k = 0;k*v[i]<=j;k++){
                dp[i][j] = max(dp[i][j],dp[i-1][j-k*v[i]]+k*w[i]);
            }
        }
    }
    cout<<dp[N][V]<<endl;
}

//两层循环二维dp
#include<bits/stdc++.h>
using namespace std;
#define MAX 1005
int v[MAX];
int w[MAX];

int main(){
    int N,V;
    cin>>N>>V;
    for(int i = 1;i <= N;i++)
        cin>>v[i]>>w[i];//体积 价值
    vector<vector<int>> dp(N+1,vector<int>(V+1,0));
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<V+1;j++){
            dp[i][j] = dp[i-1][j];
            if(j>=v[i])
                dp[i][j] = max(dp[i][j],dp[i][j-v[i]]+w[i]);    //这和0-1背包很相似但是
        }
    }
    cout<<dp[N][V]<<endl;
}

//一维dp
//物理意义就是，每次外层循环表示当前放第i个物体
#include<bits/stdc++.h>
using namespace std;
#define MAX 1005
int v[MAX];
int w[MAX];

int main(){
    int N,V;
    cin>>N>>V;
    for(int i = 1;i <= N;i++)
        cin>>v[i]>>w[i];//体积 价值
    vector<int> dp(V+1,0);
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<V+1;j++){
            if(j>=v[i])
                dp[j] = max(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    cout<<dp[V]<<endl;
}

