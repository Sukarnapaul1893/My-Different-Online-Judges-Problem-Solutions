//Author : Sukarna Paul

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/detail/standard_policies.hpp>
#define pi acos(-1)
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define MAX 300005
#define INF 0x3f3f3f3f
template <class T> inline T bigmod(T p,T e,T M){ll ret = 1LL;for(; e > 0LL; e >>= 1LL){if(e & 1LL) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime}

using namespace std;
using namespace __gnu_pbds;

typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update>pref_trie;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;


vector <long long> prime;
bitset <10000010> bs;

void sieve (ll n){
	bs.set ();
    //prime.pb(2);
	for (ll i = 2; i <= n; i++){
		if (bs[i])prime.pb(i);

		for (int j = 0; j<prime.size() && i*prime[j]<=n; j++){
		    bs[i*prime[j]] = 0;
		    if(i%prime[j]==0)break;
		}
	}
}

int main(){
    //IOS
    //freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    sieve(10000004);
    for(int tt=0;tt<t;tt++){
        long long n;
        cin>>n;
        long long ans = 1LL;

        for(int i=0;prime[i]*prime[i]<=n && i<prime.size();i++){
            ll cnt=0;
            while(n%prime[i]==0){
                cnt++;
                n/=prime[i];
            }

            ans= ans*(2LL*cnt+1LL);
        }
        if(n>1LL)ans = ans*3LL;
        cout<<"Case "<<tt+1<<": "<<(ans+1LL)/2LL<<"\n";
    }
}
