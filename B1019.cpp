#include<cstdio>

int A[3] = {0};
int B[3] = {0}; //胜、平、负次数

int A_win[3] = {0};
int B_win[3] = {0}; //获胜手势计数

int judge(char a, char b){
    if(a == b) return 1;  //平局
    else if(a == 'J'){
        if(b == 'B') return 2;//a胜b
        else return 0;
    }
    else if(a == 'B'){
        if(b == 'C') return 2;//a胜b
        else return 0;
    }
    else {
        if(b == 'J') return 2;//a胜b
        else return 0;
    }
}

void _count(int judge,char a, char b){
    if(judge == 0){
        A[2]++;
        B[0]++;
        if(b == 'C') B_win[0]++;
        else if(b == 'J') B_win[1]++;
        else B_win[2]++;
    }
    else if(judge == 2){
        A[0]++;
        B[2]++;
        if(a == 'C') A_win[0]++;
        else if(a == 'J') A_win[1]++;
        else A_win[2]++;
    }
    else{
        A[1]++;
        B[1]++;
    }
}

char findmax(int tag){
    char tmp[3] = {'C','J','B'};
    int _max;
    char min_i;
    if(tag == 0){
        _max = 0;
        for(int i = 0; i < 3; i++){
            if(A_win[i] >= _max) _max = A_win[i];
        }
        min_i = 'Z';
        for(int i = 0; i < 3; i++){
            if(A_win[i] == _max && tmp[i] < min_i ) min_i = tmp[i];
        }
        return min_i;
    }
    else{
        _max = 0;
        for(int i = 0; i < 3; i++){
            if(B_win[i] >= _max) _max = B_win[i];
        }
        min_i = 'Z';
        for(int i = 0; i < 3; i++){
            if(B_win[i] == _max && tmp[i] < min_i ) min_i = tmp[i];
        }
        return min_i;
    }
}


int main() {
    int N;
    char inA,inB;
    //freopen("input.txt","r",stdin);
    scanf("%d",&N);
    getchar();
    while(N){
        scanf("%c %c",&inA,&inB);
        getchar();
        //printf("%c %c",inA,inB);
        //printf("% d\n",judge(inA,inB));
        _count(judge(inA,inB),inA,inB);
        N--;
    }
    printf("%d %d %d\n",A[0],A[1],A[2]);
    printf("%d %d %d\n",B[0],B[1],B[2]);
    printf("%c %c\n",findmax(0),findmax(1));

    return 0;
}
