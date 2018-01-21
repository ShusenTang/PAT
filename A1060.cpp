# include <cstdio>
# include <cstring>

# define  MAXN 105

struct myfloat{
	char x[MAXN];
	int n10; // 0.x*10^n10
}num[2];

void A_to_a(char A[],int tag){
	num[tag].x[0] = '0';
	num[tag].n10 = 0;
	
	bool flag = true; //全部由0和点组成 
	
	int dot_pos = strlen(A); 
	
	int i=0;
	while(A[i] == '0' || A[i] == '.' ) {
		if(A[i] == '.') dot_pos = i;
		i++;		
	}
	int tmp = i-1;
	int j=0;
	while(A[i] != '\0'){
		if(A[i++] == '.') {
			dot_pos = i-1;
			continue;
		}
		flag = false;				
		num[tag].x[j++] = A[i-1];
	}
	if(flag == true) num[tag].n10=0;
	else {
		num[tag].n10 = dot_pos - tmp;
		if(num[tag].n10 > 0) num[tag].n10--;		
	} 
	if(j==0) j++;
	num[tag].x[j] = '\0';
}

bool isequal(myfloat a,myfloat b,int n){
	if(a.n10 != b.n10) return false;
	int i = 0;
	while(i < n){
		if(a.x[i] != b.x[i]) return false;
		if(a.x[i] == '\0') break;
		i++;
	}
	return true;
}

void cut(char c[],int n){
	int i;
	if(strlen(c) < n){
		for(i = strlen(c); i<n;i++){
			c[i] = '0';	
		}
		c[i] = '\0';	
	}
	else
		c[n] = '\0';
}

int main() {
	int N;
	char A[MAXN],B[MAXN];
	scanf("%d %s %s",&N,A,B);
	A_to_a(A,0);
	A_to_a(B,1);
	
	cut(num[0].x,N);
	cut(num[1].x,N);
	
	if(isequal(num[0],num[1],N)) printf("YES 0.%s*10^%d\n",num[0].x,num[0].n10);
	else printf("NO 0.%s*10^%d 0.%s*10^%d\n",num[0].x,num[0].n10,num[1].x,num[1].n10);	
	
	return 0;
} 
