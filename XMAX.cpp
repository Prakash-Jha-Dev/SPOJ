#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 10, LOG_A = 64;

long long basis[LOG_A];

void insertVector(bitset<64> tmp) 
{
	for (int i = LOG_A - 1; i >= 0; i--) 
    {
		if ((tmp[i]) == 0) continue;

		if (!basis[i]) 
        {
			basis[i] = tmp.to_ullong();
            // cout<<i<<" "<<tmp.to_ullong()<<" printed\n";
			return;
		}

		tmp ^= basis[i];
	}
}

int main() 
{
	int n;
	cin >> n;

	while (n--) 
    {
		long long a;
		scanf("%lld", &a);
        bitset<64> tmp(a);
		insertVector(tmp);
	}
    // for(int i=0; i<=63; i++)
    // {
    //     cout<<i<<" :: "<<basis[i]<<"\n";
    // }
	long long ans = 0;

	for (int i = LOG_A - 1; i >= 0; i--) {
		ans = max(ans, ans^basis[i]);
	}
    

	cout << ans << endl;

	return 0;
}