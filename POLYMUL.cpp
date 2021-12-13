#include <bits/stdc++.h>
using namespace std;

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd>& A, bool invert)
{
	int n = A.size();
	if(n==1) return;

	vector<cd> A0(n/2),A1(n/2);
	for(int i=0; i*2<n; i++)
	{
		A0[i]=A[i*2];
		A1[i]=A[i*2+1];
	}

	fft(A0, invert);
	fft(A1, invert);

	double ang = 2*PI/n *(invert?-1:1);
	cd w(1), wn(cos(ang),sin(ang));

	for(int i=0;i*2<n;i++)
	{
		A[i]=A0[i] + w*A1[i];
		A[i+n/2]=A0[i] - w*A1[i];

		w*=wn;
	}

	if(invert)
	{
		for(int i=0;i<n;i++) A[i]/=2;
	}
}

vector<long long>multiply(auto& v1, auto& v2)
{
	int n=1;
	while(v1.size()+v2.size() >n) n*=2;
	vector<cd>f1(v1.begin(),v1.end());
	vector<cd>f2(v2.begin(),v2.end());
	f1.resize(n);
	f2.resize(n);

	fft(f1,0);
	fft(f2,0);

	for(int i=0;i<n;i++) 
	{
		f1[i]=f1[i]*f2[i];
	}

	fft(f1,1);
	vector<long long>f(n);
	for(int i=0;i<n;i++)
	{
		f[i]=round(f1[i].real());
	}

	for(int i=n-1;i>0 && !f[i];i--)
	return f;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;

		vector<long long>v1(n+1),v2(n+1);
		for(int i=0;i<=n;i++) cin>>v1[i];
		for(int i=0;i<=n;i++) cin>>v2[i];

		vector<long long>v=multiply(v1,v2);
		v.resize(n+n+1);
		for(auto x:v) cout<<x<<" "; cout<<"\n";
	}
}