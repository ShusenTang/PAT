# include <cstdio>

struct answer{
  int x,x_num;
}ans[20];

void ansprint(answer ans){
  printf("%d",ans.x);
  if(ans.x_num > 1)
    printf("^%d",ans.x_num);
}

bool isprime(int n){
  if(n <= 3) return true;
  for(int i = 2; i*i <= n; i++ ){
    if(n%i == 0) return false;
  }
  return true;
}

int main() {
  int N;
  scanf("%d",&N);
  printf("%d=",N);
  if(N==1 || isprime(N)){
    printf("%d\n",N);
    return 0;
  }
  int prime = 2;
  int i = 0;
  while(N != 1){
    while(isprime(prime) == false) prime++;
    if(N % prime == 0){
      ans[i].x = prime;
      ans[i].x_num = 0;
      while(N % prime == 0){
        ans[i].x_num++ ;
        N = N/prime;
      }
      i++; 
    }
    prime++;    
  }
  for(int j=0;j < i;j++){
    ansprint(ans[j]);
    if(j < i-1) printf("*");
    else printf("\n");
  }  
  return 0;
}
