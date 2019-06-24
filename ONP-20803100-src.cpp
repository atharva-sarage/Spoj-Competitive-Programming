#include<stack>
#include<iostream>
#include<string.h>

using namespace std;
int isalpha(char a)
{
	if(a>=97 && a<=122)
		return 1;
	else
		return 0;
}
int ischar(char b )
{
	
	if(b=='+'|| b=='-'|| b=='*'|| b=='/' || b=='^')
		return 1;
	return 0;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char str[401];
		cin>>str;
		stack <char> eqn;
		int i,n=strlen(str);
		for(i=0;i<n;i++)
		{
			if(isalpha(str[i]))
				cout<<str[i];
			else if(str[i]==')')
				{
					cout<<eqn.top();
					eqn.pop();
				}
			else if(ischar(str[i]))
			{
				eqn.push(str[i]);
			}
		}
		cout<<endl;


		}
	}
