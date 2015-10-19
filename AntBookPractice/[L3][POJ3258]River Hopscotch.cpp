#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll Rock[50005];
bool solve(const ll& N,const ll& M,ll x)
{
    ll cnt = M;
    ll pre = Rock[0];
    for(int i=1;i<=N+1;i++){
        if(Rock[i]-pre < x){
            cnt--;
            continue;
        }
        pre = Rock[i];
    }
    return cnt >= 0 ;
}

int main()
{   
    // freopen("in","r",stdin);
    ll L,N,M;
    while(~scanf("%lld%lld%lld",&L,&N,&M)){
        Rock[0]=0;
        for(int i=1;i<=N;i++)
            scanf("%lld",&Rock[i]);
        Rock[N+1] = L;
        ll lb=-1,ub=L+1,mid;
        sort(Rock,Rock+N+2);
        while(ub-lb>1){
            mid = (ub+lb)/2;
            if(solve(N,M,mid))
                lb = mid;
            else
                ub = mid;
        }
        printf("%lld\n",lb);
    }
    return 0;
}