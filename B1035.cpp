#include<cstdio>
#include<algorithm>
using namespace std;

int N,ori[105],changed[105],ori_back[105];

bool issame(int a[], int b[]){
    bool flag = true;
    for(int i = 0; i < N; i++){
        if(a[i] != b[i]){
            flag = false;
            break;
        }
    }
    return flag;
}

bool IsInsertsort(){
    for(int i = 2; i < N; i++){
        sort(ori,ori+i);
        if(issame(ori,changed)){
            printf("Insertion Sort\n");
            sort(ori,ori+i+1);
            for(int i = 0; i < N-1; i++)printf("%d ",ori[i]);
            printf("%d\n",ori[N-1]);
            return true;
        }
    }
    return false;
}

void MergeSort(){
    printf("Merge Sort\n");
    bool flag = false;
    for(int step = 2; step / 2 <= N; step *= 2){
        if(step != 2 && issame(ori_back,changed)){ //非初始序列且相等
            flag = true;
        }
        for(int i = 0; i < N; i+=step){
            sort(ori_back+i,ori_back+min(i+step,N));
        }
        if(flag == true){
            for(int i = 0; i < N-1; i++)printf("%d ",ori_back[i]);
            printf("%d\n",ori_back[N-1]);
            return;
        }
    }
}


int main() {

    //freopen("input.txt","r",stdin);

    scanf("%d",&N);
    for(int i = 0; i < N; i++){
        scanf("%d",&ori[i]);
        ori_back[i] = ori[i];
    }
    for(int i = 0; i < N; i++){
        scanf("%d",&changed[i]);
    }
    if(IsInsertsort() == false){
        MergeSort();
    }

    return 0;
}
