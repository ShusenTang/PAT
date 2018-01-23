# include <cstdio>
# include <algorithm>
using namespace std;

# define  MAXN 65


int main() {
    char str[4][MAXN];
    char DAY,H,M;
    char week[7][4] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};

    //freopen("input.txt","r",stdin);

    for(int i = 0; i < 4; i++){
        scanf("%s",str[i]);
    }
    int tmp = 0;
    for(int i = 0; i < MAXN; i++){
        if( str[0][i] >= 'A' && str[0][i] <= 'G' && str[0][i] == str[1][i] && tmp == 0){
            tmp++;
            DAY = str[0][i];
        }
        else if(str[0][i] == str[1][i] && tmp == 1){
            if(str[0][i] >= '0' && str[0][i] <= '9'){
                    H = str[0][i];
                    break;
            }
            else if(str[0][i] >= 'A' && str[0][i] <= 'N'){
                    H = str[0][i];
                    break;
            }
        }
    }
    for(int i = 0; i < MAXN; i++){
        if( str[2][i] >= 'A' && str[2][i] <= 'z' && str[2][i] == str[3][i]) {
            M = i;
            break;
        }
    }

    int H_tmp;
    if(H >= '0' && H <= '9') H_tmp = H - '0';
    else H_tmp = H - 'A' + 10;
    printf("%s %02d:%02d\n",week[DAY-'A'],H_tmp,M);
  return 0;
}
