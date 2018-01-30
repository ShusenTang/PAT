#include<cstdio>
#include<cstring>
#include <cstdlib>
#include<iostream>
using namespace std;


double str_to_double(char num[]){
    double ans = atof(num);   //atof为stdlib.h下字符串转双精度函数
    return ans;
}

char b[100];
bool islegal(char *num){
    //char b[100];    //最好放到全局
    double temp;
    sscanf(num,"%lf",&temp);//将num字符串转换为格式lf存到temp里
    sprintf(b,"%.2lf",temp);//将格式化的temp写入字符串b
    for(int j=0; j < strlen(num); j++)//判断新的字符串跟原来的是不是相等的
        if(num[j] != b[j]) return false;

    if(temp< -1000 || temp > 1000)
        return false;

    return true;
}

int main(){
    //freopen("input.txt","r",stdin);

    int n,legal_count;
    double sum;
    legal_count = sum = 0;
    char num[1000];
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%s",num);
        if(islegal(num)){
            sum += str_to_double(num);
            legal_count++;
        }
        else printf("ERROR: %s is not a legal number\n",num);
    }
    if(legal_count == 0) printf("The average of 0 numbers is Undefined\n");
    else if(legal_count == 1) printf("The average of 1 number is %.2f\n",sum);
    else printf("The average of %d numbers is %.2f\n",legal_count,sum/legal_count);

    return 0;
}
