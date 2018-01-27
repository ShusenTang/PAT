#include<cstdio>
#include<cstring>

using namespace std;

void rever(char c[]){
    char tmp;
    int low = 0;
    int high = strlen(c)-1;
    while(low < high){
        tmp = c[low];
        c[low++] = c[high];
        c[high--] = tmp;
    }
}

int main() {

    char A[105],B[105];
    char tmp[13] = {'0','1','2','3','4','5','6','7','8','9','J','Q','K'};
    //freopen("input.txt","r",stdin);
    scanf("%s %s",A,B);
    rever(A);
    rever(B);
    if(strlen(B) < strlen(A)){         //B长度小于A时要补0！！！！！！！！！
        for(int i = strlen(B); i < strlen(A); i++){
            B[i] = '0';
        }
        B[strlen(A)] = '\0';
    }
    for(int i = 0; i < strlen(A); i++){
        if(i > strlen(B)-1) break;
        if(i % 2 == 0){
            B[i] = tmp[(A[i]+B[i]-'0'-'0') % 13];
        }
        else{
            int n = B[i] - A[i];
            if(n < 0) n += 10;
            B[i] = n + '0';
        }
    }
    rever(B);
    printf("%s\n",B);

    return 0;
}
