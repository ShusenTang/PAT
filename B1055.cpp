#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 10005

using namespace std;
struct person{
    char name[10];
    int h;
}p[MAXN];

bool cmp(person a, person b){
    if(a.h != b.h) return a.h > b.h;
    else return strcmp(a.name,b.name) < 0;
}

int ans[MAXN];
void print(int low,int m){
    int cnt = 0;
    int mid = m / 2;
    ans[mid--] = cnt++;
    while(mid >= 0){
       ans[mid--] = cnt;
       cnt += 2;
    }
    mid = m / 2  + 1;
    cnt = 2;
    while(mid < m){
        ans[mid++] = cnt;
        cnt += 2;
    }

    for(int i = 0; i < m; i++){
        printf("%s",p[ans[i]+low].name);
        if(i == m-1) printf("\n");
        else printf(" ");
    }
}
int main(){
    //freopen("input.txt","r",stdin);

    int n,k;

    scanf("%d %d",&n,&k);
    for(int i = 0; i < n; i++){
        scanf("%s %d",p[i].name,&p[i].h);
    }
    sort(p,p+n,cmp);

    int low,m;
    low = 0;
    for(int i = 0; i < k; i++){
        if(i==0) m = n/k + n%k;
        else  m = n/k;
        print(low,m);
        low += m;
    }

    return 0;
}
