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
	int i,j,k,l=21,m,n;
	FILE *p=fopen("positive.txt","r");
	FILE *p1=fopen("negative.txt","r");
	FILE *p2=fopen("matrix.txt","w"); 
	freopen("PSAAP.txt","w",stdout);
	double matrixp[25][25];
	double matrixn[25][25];
	double matrix[25][25];
	int frep[25][25];
	int fren[25][25];
	memset(frep,0,sizeof(frep));
	memset(fren,0,sizeof(fren));
	char amino[25]="ACDEFGHIKLMNPQRSTVWYX";
	m=0;
	n=0;
	while(fgets(str,1000,p))
	{
		for(i=0;i<l;i++)
		{
			for(j=0;j<21;j++)
			{
				if(str[i]==amino[j])
				{
					frep[i][j]++;
					break;
				}
			}
		 } 
		n++;
	 } 
	while(fgets(str,1000,p1))
	{
		for(i=0;i<l;i++)
		{
			for(j=0;j<21;j++)
			{
				if(str[i]==amino[j])
				{
					fren[i][j]++;
					break;
				}
			}
		 } 
		m++;
	 } 
	for(i=0;i<l;i++)
	{
		for(j=0;j<21;j++)
		{
			matrixp[i][j]=frep[i][j]*1.0/n;
			matrixn[i][j]=fren[i][j]*1.0/m;
			matrix[i][j]=matrixp[i][j]-matrixn[i][j];
			fprintf(p2,"%g ",matrix[i][j]);
		}
		fprintf(p2,"\n");
	}
	fclose(p);
	fclose(p1);
	FILE *posi=fopen("positive.txt","r");
	FILE *nega=fopen("negative.txt","r");
	while(fgets(str,1000,posi))
	{
		for(i=0;i<l;i++)
		{
			if(i==10)continue;
			for(j=0;j<21;j++)
			{
				if(str[i]==amino[j])
				{
					printf("%g ",matrix[i][j]);
					break;
				}
			}
		 }
		printf("\n"); 
	 } 
	while(fgets(str,1000,nega))
	{
		for(i=0;i<l;i++)
		{
			if(i==10)continue;
			for(j=0;j<21;j++)
			{
				if(str[i]==amino[j])
				{
					printf("%g ",matrix[i][j]);
					break;
				}
			}
		 }
		printf("\n");  
	 } 
	return(0);
}

