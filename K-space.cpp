#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
	char str[1000];
	int i,j,k,l,m,n,t1,t2;
	FILE *p=fopen("window21.txt","r");
	char s[25]="ACDEFGHIKLMNPQRSTVWYX";
	freopen("K-space1.txt","w",stdout);
	int amino[25];
	while(fgets(str,1000,p))
	{
		l=strlen(str);
		memset(amino,0,sizeof(amino));
		for(i=0;i<l;i++)
		{
			for(j=0;j<21;j++)
			{
				if(str[i]==s[j])
				{
					amino[i]=j;
					break;
				}
			}
		}
		for(i=0;i<21;i++)
		{
			for(j=0;j<21;j++)
			{
				n=0;
				for(k=0;k<l-1;k++)
				{
					if(amino[k]==i&&amino[k+1]==j)
					{
						n++;
					}
				}
				printf("%d ",n);
			}
		}
		printf("\n");
	 } 
	return(0);
}

