# include <stdio.h>
# include <iostream>
# include <string>
using namespace std;

int main(){
    int n,P_pos,T_pos,P_count,T_count,all_PAT;

    //freopen("input.txt","r",stdin);

    scanf("%d",&n);
    //printf("%d\n",n);
    string str;
    while(n != 0){
        cin >> str;
        all_PAT = 1;
        P_count = T_count = 0;
        P_pos = T_pos = -1;
        for(int i = 0;i<str.length();i++){
            if(str[i] == 'P'){
                P_count++;
                P_pos = i;
            }
            else if(str[i] == 'T'){
                T_count++;
                T_pos = i;
            }
            else if(str[i] != 'A'){
                all_PAT = 0;
                break;
            }
            if(T_count > 1 || P_count > 1) break;
        }
        if(T_count != 1 || P_count != 1 || T_pos-P_pos <= 1 || !all_PAT){
            printf("NO\n");
            //continue;
        }
        else {
            int tmp = T_pos - P_pos -1;  //PT之间A的个数
            //cout << str << endl;
            str.erase(P_pos+1,tmp-1);
            //cout << str << endl;
            T_pos = P_pos + 2;
            if(P_pos != 0){
                if(P_pos*(tmp-1) > str.length()-3) {
                    printf("NO\n");
                    continue;
                }
                else str.erase(str.length()-P_pos*(tmp-1),P_pos*(tmp-1));
            }
            if(P_pos == str.length()-T_pos-1) printf("YES\n");
            else printf("NO\n");
        }
        n--;
    }
    return 0;

}
