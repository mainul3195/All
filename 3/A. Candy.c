#include<stdio.h>

int main()
{
	int n,i,t;
	scanf("%d", &t);
	while(t--){
	scanf("%d", &n);
	for(i=4; n%(i-1)!=0; i*=2);
		printf("%d\n",n/(i-1));
}
return 0;

}