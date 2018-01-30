#include<cstdio>
#include<map>
#include<algorithm>

using namespace std;

map<int ,int > mp;

#define MAXN 10005

char Award[3][20] = {"Mystery Award","Minion","Chocolate"};

struct student{
    int award,ID,checked;
}stu[MAXN];

bool isprime(int num){
    if(num == 1) return false;
    for(int i = 2; i*i <= num; i++){
        if(num % i == 0) return false;
    }
    return true;
}


int main(){
    //freopen("input.txt","r",stdin);
    int n,k;
    scanf("%d",&n);
    for(int i = 0; i <n; i++){
        scanf("%d",&stu[i].ID);
        mp[stu[i].ID] = i;

        stu[i].checked = 0;
        if( i == 0) stu[i].award = 0;
        else if(isprime(i+1)) stu[i].award = 1;
        else stu[i].award = 2;
    }

    scanf("%d",&k);
    int id;
    for(int i = 0; i < k; i++){
        scanf("%d",&id);
        if(mp.count(id) == 0) printf("%04d: Are you kidding?\n",id);
        else if(stu[mp[id]].checked == 0){
            printf("%04d: %s\n",id,Award[stu[mp[id]].award]);
            stu[mp[id]].checked = 1;
        }
        else if(stu[mp[id]].checked == 1) printf("%04d: Checked\n",id);
    }



    return 0;
}
