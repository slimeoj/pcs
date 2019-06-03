/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 05月 27日 星期一 08:17:58 CST
* problem: luogu-1966
*----------------*/
#include <bits/stdc++.h>
using namespace std;

#define maxn 100005
int n;
struct _p {
    int idx,val;
};

struct _px {
    int oidx,nidx,val;
};

bool cmp1(_p &a,_p &b){
    return a.val < b.val;
}

bool cmp2(_px &a,_px &b){
    return a.val< b.val;
}

bool cmp3(_px &a,_px &b){
    return a.oidx< b.oidx;
}


_p a[maxn];
_px b[maxn];
int c[maxn]; //对应的序列
int d[maxn];

void init(){
    scanf("%d",&n);
    int i;
    for (i=1;i<=n;i++){
        scanf("%d",&a[i].val);
        a[i].idx =i;
    }
    sort(a+1,a+n+1,cmp1);
    for (i=1;i<=n;i++){
        scanf("%d",&b[i].val);
        b[i].oidx = i;
    }
    sort(b+1,b+n+1,cmp2);
    for (i=1;i<=n;i++){
        b[i].nidx = i;
    }
    sort(b+1,b+n+1,cmp3);
    for (i=1;i<=n;i++){
        //printf("%d %d\n",b[i].val,b[i].nidx);
        d[i] = a[b[i].nidx].idx;
        //printf("%d\n",c[i]);
    }

}


int lowbit(int x){
    return x &-x;
}


void update(int pos,int val){
    while(pos <=n){
        c[pos] += val;
        pos += lowbit(pos);
    }
}

int query(int pos){
    int sum = 0;
    while( pos > 0){
        sum += c[pos];
        pos -= lowbit(pos);
    }
    return sum;
}


void deal(){
    int i;
    int ans = 0;
    for (i=1;i<=n;i++){
        update(d[i],1);
        ans = (ans + i-query(d[i])) % 99999997;
    }

    printf("%d\n",ans);
}
int main(){
    init();
    deal();
    return 0;
}
