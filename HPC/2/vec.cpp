#include<iostream>
#include<stdlib.h>
#include<omp.h>

#define MAX 3
using namespace std;

int main()
{
	int a[MAX],b[MAX][MAX],c[MAX];
	#pragma omp parallel for	

			for(int i=0;i<MAX;i++)
			      {
			        a[i]=rand()%10;
			               
			         }
			         cout<<"\n1st Vec:\n";
			for(int i=0;i<MAX;i++)
			        {
			        cout<<a[i]<<"\t";
			               
			         }
			         
			  #pragma omp parallel for       
			 for(int i=0;i<MAX;i++)
			 
			        {
			        for(int j=0;j<MAX;j++)
			        {
			                b[i][j]=rand()%10;
			         }      
			         }
			         cout<<"\nmatrix\n";
			for(int i=0;i<MAX;i++){
			for(int j=0;j<MAX;j++)
			        {
			        cout<<b[i][j]<<"\t";
			               
			         }  
			         cout<<"\n";      
			}
			#pragma omp parallel for
			for(int i=0;i<MAX;i++)
			{       c[i]=0;
			      for(int j=0;j<MAX;j++)
			        {
			        
			          c[i]+=(b[i][j]*a[j]);
			 
			        }              
			         }
			         cout<<"\nMultiplication IS:\n";
			for(int i=0;i<MAX;i++)
			{
			        
			       cout <<c[i]<<"\t";
			               
			         
			         cout<<"\n";
			         }
		
}
