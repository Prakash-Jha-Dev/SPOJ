#include <bits/stdc++.h>
using namespace std;

typedef struct TrieNode
{
	struct TrieNode* next[10];
	bool leaf[10];
}trie;

trie* newNode()
{
	trie* node=(trie*)malloc(sizeof(trie));
	for(int i=0;i<10;i++)
	{
		node->leaf[i]=false;
		node->next[i]=NULL;
	}
	return node;
}

bool insert(string& s, trie* node)
{
	int i;
	int j=0;
	bool flag=false;
	for(i=0;i<s.length()-1;i++)
	{
		if(!node->next[s[i]-'0'])
		{
			j++;
			node->next[s[i]-'0']=newNode();
		}
		flag|=node->leaf[s[i]-'0'];

		node=node->next[s[i]-'0'];
	}
	flag|=node->leaf[s[i]-'0'];
	if(node->next[s[i]-'0']==false) j++;
	node->leaf[s[i]-'0']=true;
	if(!j) flag=1;
	return flag;
}

void solve()
{
	int n;
	cin>>n;
	string s;
    trie *head=newNode();
    bool flag=false;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		flag|=insert(s, head);
	}

	flag?cout<<"NO\n":cout<<"YES\n";
}


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;

	while(t--)
		solve();
}