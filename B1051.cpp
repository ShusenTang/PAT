#include<cstdio>
#include<math.h>

using namespace std;

int main() {
    double R1,P1,R2,P2,R,P,A,B;

    //freopen("input.txt","r",stdin);
    scanf("%lf %lf %lf %lf",&R1,&P1,&R2,&P2);
    R = R1*R2;
    P = P1+P2;
    //R(cos(P) + isin(P))
    A = R*cos(P);
    B = R*sin(P);

    if(fabs(A) < 0.01) A = 0;
    if(fabs(B) < 0.01) B = 0; //一定要写这两句，否则不会过。如当B=-0.001时输出格式就会不对

    printf("%.2f",A);
    if(B < 0) printf("%.2fi",B);
    else if(B >= 0) printf("+%.2fi",B);
    printf("\n");
    return 0;
}
