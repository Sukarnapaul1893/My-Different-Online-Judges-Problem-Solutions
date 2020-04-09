//Author : Sukarna Paul

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/detail/standard_policies.hpp>
#define pi acos(-1)
#define pb push_back
#define mp make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define PII pair<int,int>
template <class T> inline T bigmod(T p,T e,T M){ll ret = 1LL;for(; e > 0LL; e >>= 1LL){if(e & 1LL) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime}

using namespace std;
using namespace __gnu_pbds;

typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update>pref_trie;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;

const int N=505;
int INF=1e7;

vector<pair<int,int> > adj[N];     //node cost
int dis[N];
bool vis[N];

void clear()
{
    fill (adj, adj + N, vector<PII> ());
    fill (dis, dis + N, INF);
    fill (vis, vis + N, false);
}

void dijkstra (int s)
{
    dis[s]=0;
    priority_queue<PII, vector<PII>, greater<PII> > pq;
    pq.push(mp(0,s));

    while (!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first;
        //cout<<d<<" "<<u<<" "<<endl;
        pq.pop();

        if (vis[u])  continue;
        vis[u]=1;
        assert ( d == dis[u]);

        for (int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            int c = adj[u][i].second;
            int cur = max (dis[u], c);

            if (cur < dis[v])
                dis[v] = cur,
                pq.push(mp(cur, v));
        }
    }
}

int main(){
    //IOS
    //freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);

    for(int tt=0;tt<t;tt++){
        clear();
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<m;i++){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            adj[u].pb({v,w});
            adj[v].pb({u,w});
        }
        int src ;
        scanf("%d",&src);
        printf("Case %d:\n",tt+1);
        dijkstra(src);
        for(int i=0;i<n;i++){
            if(dis[i]==INF){
                printf("Impossible\n");
                continue;
            }
            printf("%d\n",dis[i]);


        }

    }



}
