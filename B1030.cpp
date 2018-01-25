#include<cstdio>
#include<algorithm>
#define MAXN 100005

using namespace std;

int num[MAXN],N;
int ans = 0;

bool isperfect(int M, int m, int p){
    double tmp = (double)M / m;
    if(tmp <= p) return true;
    return false;
}

void binarysearch(int low,int p){
    if(N - low > ans){
        int i = low;
        int j = N - 1;
        int mid;
        while(i < j){
            mid = (i + j)/2;
            if(isperfect(num[mid],num[low],p)) i = mid + 1;
            else j = mid - 1;
        }
        if(i - low + 1 > ans){
            if(isperfect(num[i],num[low],p)) ans = i - low + 1;
            else if(isperfect(num[i-1],num[low],p) && i - low > ans) ans = i - low;
        }
    }
}

void find_ans(int low, int high ,int p){
    for(int i = low; i <= high; i++){
        binarysearch(i,p);
    }
}

int main() {
    int p,low,high;

    //freopen("input.txt","r",stdin);

    scanf("%d %d",&N,&p);
    for(int i = 0; i < N; i++){
        scanf("%d",&num[i]);
    }
    sort(num,num+N);
    find_ans(0,N-1,p);
    printf("%d\n",ans);

    return 0;
}
