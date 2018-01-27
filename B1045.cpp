#include<cstdio>
#include<algorithm>
#define MAXN 100005
using namespace std;

struct number{
    int n,left_max,right_min;
}num[MAXN];

bool cmp(number a, number b){
    return a.n < b.n;
}


int main() {
    int n,L_max,R_min;
    L_max = 0;
    R_min = 1000000001;
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);

    for(int i = 0; i < n; i++){
        scanf("%d",&num[i].n);
        num[i].left_max = L_max;
        if(num[i].n > L_max) L_max = num[i].n;
    }

    int cnt = 0;
    for(int i = n - 1; i >= 0; i--){
        num[i].right_min = R_min;
        if(num[i].n < R_min) R_min = num[i].n;
        if(num[i].n > num[i].left_max && num[i].n < num[i].right_min) cnt++;
    }
    printf("%d\n",cnt);
    sort(num,num+n,cmp);
    for(int i = 0; i < n; i++){
        if(num[i].n > num[i].left_max && num[i].n < num[i].right_min){
            cnt--;
            if(cnt == 0) printf("%d",num[i].n);
            else printf("%d ",num[i].n);
        }

    }
    printf("\n");
    return 0;
}
