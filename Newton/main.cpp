#include<stdio.h>
int cffcnt[1000];
int main()
{
	int n;
	double start;
	printf("방정식의 차수를 입력하세요");     
	scanf("%d",&n);
	printf("방정식의 계수를 입력하세요(0부터 n까지)");
	for(int i = 0; i <= n; i++)
		scanf("%d",&cffcnt[i]);
	printf("초깃값은?");
	scanf("%lf",&start);
	
}

