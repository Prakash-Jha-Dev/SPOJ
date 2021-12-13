#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		double x;
		cin>>x;
		if(x==0)
			printf("1.000000\n");
		else
			printf("%.6lf\n",(1-(sqrt(2/x)/3)));
	}
	return 0;
}