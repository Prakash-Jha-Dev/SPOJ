#include <bits/stdc++.h>
using namespace std;
int main(){
    int test=1;
    while(1){
	    string s;
	    cin>>s;
	    if(s[0]=='-') break;
	    int c=0,o=0,a=0;
	    for(char c:s)
	    	if(c=='{') o++;
	    	else{
	    		c++;
	    		if(o>0)	o--,c--;
	    		else	a++,o++,c--;
	    	}
		cout<<test++<<". "<<a+(o/2)+(c/2)<<"\n";
	}
}