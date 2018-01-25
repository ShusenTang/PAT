#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<math.h>

#define MAXN 100005

using namespace std;

struct fraction{
    long long up,down;
};

long long gcd(long long a, long long b){
    if(a > b) return gcd(b,a);
    else if(a == 0) return b;
    else return gcd(b%a,a);
}

fraction ans[4]; //加减乘除结果
void compute(int tag,fraction n1, fraction n2){  //tag = 0代表加。。。
    if(tag == 0){
        if(n1.up == 0){
            ans[0].up = n2.up;
            ans[0].down = n2.down;
        }
        else if(n2.up == 0){
            ans[0].up = n1.up;
            ans[0].down = n1.down;
        }
        else{
            ans[0].up = n1.up*n2.down + n1.down*n2.up;
            ans[0].down = n1.down*n2.down;
        }
    }
    else if(tag == 1){
        n2.up = (-1)*n2.up;
        if(n1.up == 0){
            ans[1].up = n2.up;
            ans[1].down = n2.down;
        }
        else if(n2.up == 0){
            ans[1].up = n1.up;
            ans[1].down = n1.down;
        }
        else{
            ans[1].up = n1.up*n2.down + n1.down*n2.up;
            ans[1].down = n1.down*n2.down;
        }
    }
    else if(tag == 2){
        ans[2].up = n1.up * n2.up;
        ans[2].down = n1.down * n2.down;
    }
    else if(tag == 3){
        ans[3].up = n1.up * n2.down;
        ans[3].down = n1.down * n2.up;
    }
}



void print_frac(fraction n){
    if(n.down == 0) printf("Inf");
    else if(n.up == 0) printf("0");
    else{  //分子分母0
        int neg_tag = 0;
        if(n.up < 0 && n.down > 0){ 
            printf("(-");
            neg_tag = 1;
            n.up = (-1)*n.up;
        }
        else if(n.up > 0 && n.down < 0){
            printf("(-");
            neg_tag = 1;
            n.down = (-1)*n.down;
        }
        if(n.up % n.down == 0) printf("%lld",n.up/n.down);
        else{
            int tmp = gcd(n.up,n.down);
            n.up = n.up / tmp;
            n.down = n.down / tmp;
            if(n.up > n.down){
                printf("%lld ",n.up/n.down);
                n.up = n.up % n.down;
            }
            printf("%lld/%lld",n.up,n.down);
        }
        if(neg_tag == 1) printf(")");
    }
}



int main() {
    fraction n1,n2;
    scanf("%lld/%lld %lld/%lld",&n1.up,&n1.down,&n2.up,&n2.down);
    char tmp[4] = {'+','-','*','/'};
    for(int i = 0; i < 4; i++){
        print_frac(n1);
        printf(" %c ",tmp[i]);
        print_frac(n2);
        printf(" = ");
        compute(i,n1,n2);
        print_frac(ans[i]);
        printf("\n");
    }

    //printf("%d\n",gcd(24,24));

    return 0;
}
