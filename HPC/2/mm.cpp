#include<iostream>
#include<stdlib.h>
#include<omp.h>

#define MAX 3
using namespace std;

int main()
{
        int i,j,k;
	int a[MAX][MAX],b[MAX][MAX],c[MAX][MAX];
	#pragma omp parallel for	

			 for(int i=0;i<MAX;i++)
			 
			        {
			        for(int j=0;j<MAX;j++)
			        {
			                a[i][j]=rand()%10;
			         }      
			         }
			         cout<<"\nmatrix\n";
			for(int i=0;i<MAX;i++){
			for(int j=0;j<MAX;j++)
			        {
			        cout<<a[i][j]<<"\t";
			               
			         }  
			         cout<<"\n";      
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
			#pragma omp parallel for private(k,j)
			for(int i=0;i<MAX;i++)
			{     
			      for(int j=0;j<MAX;j++)
			        {
			                c[i][j]=0;
			                for(int k=0;k<MAX;k++)
			                {
			                       c[i][j]+=(a[i][k]*b[k][j]);
			                }
			        }              
			         }
			         cout<<"\nMultiplication IS:\n";
			for(int i=0;i<MAX;i++)
			{
			     for(int j=0;j<MAX;j++)
			     {
			       cout <<c[i][j]<<"\t";
			      }         
			         
			         cout<<"\n";
			         }
		
}
