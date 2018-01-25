#include<cstdio>
#include<algorithm>
#define MAXN 100005
using namespace std;

struct node{
    int add,data,next;
    int order;
}mylist[MAXN];

bool cmp(node a, node b){
    return a.order < b.order;
}
void reverlist(int first, int k){
    int low = first;
    int high = first + k - 1;
    while(low < high){
        mylist[low].order = high;
        mylist[high].order = low;
        low++;
        high--;
    }
}
int main() {
    int startadd,N,K;

    freopen("input.txt","r",stdin);

    scanf("%d %d %d",&startadd,&N,&K);
    int add;
    for(int i = 0; i < N; i++){
        scanf("%d",&add);
        scanf("%d %d",&mylist[add].data,&mylist[add].next);
        mylist[add].add = add;
    }

    for(int i = 0; i < MAXN; i++){
        mylist[i].order = MAXN;
    }

    int next = startadd;
    int cnt = 0;
    while(next != (-1)){
        mylist[next].order = cnt;
        cnt++;
        next = mylist[next].next;
    }
    sort(mylist,mylist+MAXN,cmp);

    int tmp = cnt / K;   // ！！！不能写成tmp = N/K;因为链表长度可能小于N！！！
    for(int i = 0; i < tmp; i++){
        reverlist(i*K,K);
    }
    sort(mylist,mylist + N,cmp);
    for(int i = 0; i < cnt - 1; i++){
        printf("%05d %d %05d\n",mylist[i].add, mylist[i].data,mylist[i+1].add);
    }
    printf("%05d %d -1\n",mylist[cnt-1].add, mylist[cnt-1].data);

    return 0;
}
