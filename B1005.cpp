#include <stdio.h>
#include<algorithm>
using namespace std;
#define MAXN 105

bool cmp(int a,int b){
    return a>b;
}

int main(){
    int K,n[MAXN];
    int tag[MAXN] = {0};
    scanf("%d",&K);
    for(int i = 0;i<K;i++){
        scanf("%d",&n[i]);
        int tmp = n[i];
        if(tmp%2==0) tmp/=2;
        else tmp = (3*tmp+1)/2;
        while(tmp!=1){
            if(tmp < MAXN)  // !!!!!!不加这个判断的话很可能越界！！！！
                tag[tmp] = 1; 
            if(tmp%2==0) tmp/=2;
            else tmp = (3*tmp+1)/2;
        }
    }
    int tmp[MAXN];
    int j=0;
    for(int i = 0 ; i < K ; i++){
        if(tag[n[i]]==0) {
            tmp[j++] = n[i];
        }
    }
    sort(tmp,tmp+j,cmp);
    for(int k=0 ; k<j ; k++){
        printf("%d",tmp[k]);
        if(k==j-1) printf("\n");
        else printf(" ");
    }
    return 0;
}
