#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;


int main() {
    string num;
    //string::iterator it;
    int E_pos,E,neg_tag;
    cin >> num;
    if(num[0] == '-') neg_tag = 1;
    else neg_tag = 0;
    E_pos = num.find("E");
    E = 0;
    for(int i = E_pos+2; i < num.length(); i++){
        E = 10*E + (num[i]-'0');
    }
    if(num[E_pos+1] == '-') E = (-1)*E;
    //printf("E=%d\n",E);
    num.erase(E_pos,num.length()-E_pos);
    num.erase(0,1);
    num.erase(1,1);
    if(E >= 0){
        if(num.length() > E+1)
            num.insert(E+1,".");
        else{
            int tmp = E+1-num.length();
            while(tmp){
                num.insert(num.length(),"0");
                tmp--;
            }
        }
    }
    else{
        while(E < 0){
           num.insert(0,"0");
           E++;
        }
        num.insert(1,".");
    }
    if(neg_tag) num.insert(0,"-");
    cout << num;
    return 0;
}
