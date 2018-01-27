#include<cstdio>
#include<cstring>
#include<algorithm>
#include<math.h>
#define MAXN 10005
using namespace std;

int ans[MAXN][MAXN],num[MAXN];

void Find_m_n(int N, int &m, int &n){
    int sqr = (int)sqrt((double)N);
    //printf("%d\n",sqr);
    int a[200],b[200],cnt;
    cnt = 0;
    for(int i = 1; i <= sqr; i++){
        if(N % i == 0){
            a[cnt] = N / i;
            b[cnt++] = i;
        }
    }
    int min_i;
    int min_mn = MAXN;
    for(int i = 0; i < cnt; i++){
        if(a[i]-b[i] < min_mn){
            min_mn = a[i] - b[i];
            min_i = i;
        }
    }
    m = a[min_i];
    n = b[min_i];
}

void fill_ans(int m, int n){
    int left,right,low,high,cnt;
    left = high = cnt = 0;
    right = n - 1;
    low = m - 1;
    while(left <= right){
        for(int i = left; i <= right; i++){
            ans[high][i] = num[cnt++];
        }
        for(int i = high+1; i <= low; i++){
            ans[i][right] = num[cnt++];
        }
        for(int i = right-1;i >= left;i--){
            ans[low][i] = num[cnt++];
        }
        if(left == right) break;  //一定要加这句，否则会出错，如当N=15时!!!!
        for(int i = low-1; i >= high+1; i--){
            ans[i][left] = num[cnt++];
        }
        high++;
        left++;
        right--;
        low--;
    }
}

bool cmp(int a, int b){
    return a > b;
}

int main() {
    int N,m,n;

    //freopen("input.txt","r",stdin);

    scanf("%d",&N);
    for(int i = 0; i < N; i++){
        scanf("%d",&num[i]);
    }
    sort(num,num+N,cmp);
    Find_m_n(N,m,n);
    fill_ans(m,n);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(j==n-1) printf("%d\n",ans[i][j]);
            else printf("%d ",ans[i][j]);
        }
    }
    return 0;
}
