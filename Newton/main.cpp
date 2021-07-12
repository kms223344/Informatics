#include<stdio.h>
class polynomial
{
private:
	int n;
	double cffcnt[1000];
public:
	polynomial()
	{
		n = 0;
		for(int i = 0; i <= 999; i++) cffcnt[i] = 0;
	}
	polynomial(const int& n,const double cffcnt[]) : n(n),cffcnt(cffcnt) {;}
	int ord() const {return n;}
	double insert(double n);
	double differenciate_insert(double n);
	polynomial differenciate_f();
};

double polynomial::insert(double n)
{
	double a = 1,ans = 0;
	for(int i = 0; i<= n; i++, a *= n) ans += (this->cffcnt[i]) * a;
	return ans;
}

polynomial polynomial::differenciate_f()
{
	polynomial fprime;
	fprime.n = this->n-1;
	for(int i = 1; i <= n; i++) fprime.cffcnt[i-1] = this->cffcnt[i] * i;
	return fprime;
}
double polynomial::differenciate_insert(double n)
{
	return (this->differenciate_f()).insert(n);
}
int main()
{
	int n;
	double cffcnt[1000];
	double start;
	printf("방정식의 차수를 입력하세요");     
	scanf("%d",&n);
	printf("방정식의 계수를 입력하세요(0부터 n까지)");
	for(int i = 0; i <= n; i++)
		scanf("%d",&cffcnt[i]);
	polynomial a(n,cffcnt);
	printf("초깃값은?");
	scanf("%lf",&start);		
}

