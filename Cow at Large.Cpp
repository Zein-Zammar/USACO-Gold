//http://www.usaco.org/index.php?page=viewproblem2&cpid=790
//USACO 2018 January Contest, Gold
#include <bits/stdc++.h>
#define endl '\n'
#define m1(a) memset(a,-1, sizeof a)
#define pb push_back
#define int ll
#define FOR(i,a, b) for (int i=a; i<=(b); i++)

using namespace std;
typedef long long ll;
typedef vector<int> vi;

void setIO(string s) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!s.empty()){
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

vi g[100005];
int n,k,ans,cost[100005],cost2[100005];
bool vis[100005];

queue<int>q;

void bfs(bool farmer){

    while (!q.empty()){
    
        int src = q.front();
        q.pop();
        for (auto it : g[src]){
        
            if (!farmer){
                if (cost[it] == -1){
                    cost[it]=cost[src]+1;
                    q.push(it);
                }
            }
            
            else{
                if (cost2[it]==-1){
                    cost2[it]=cost2[src]+1;
                    q.push(it);
                }
            }
            
        }  
    }
}

int32_t main(){

    setIO("atlarge");

    cin >> n >>k;
    FOR(i,2,n){
        int x, y;
        cin >>x >>y;
        g[x].pb(y);
        g[y].pb(x);
    }

    m1(cost); m1(cost2);
    q.push(k);
    cost[k] = 0;
    bfs(0);

    FOR(i,1,n){
        if (g[i].size() == 1){
            q.push(i), cost2[i]=0;
        }
    }
    bfs(1);

    q.push(k);
    vis[k] = 1;
    while (!q.empty()){
    
        int src = q.front();
        q.pop();
        
        for (auto it : g[src]){
        
            if (cost[it] >= cost2[it]){
                ans++;
                continue;
            }
            
            else if (!vis[it])
                q.push(it), vis[it] = 1;
                
        }

    }
    
    cout << ans;
}
