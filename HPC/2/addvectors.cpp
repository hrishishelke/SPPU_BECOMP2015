//How to add two largest vectors by Parallel execution

#include<stdio.h>
#include<math.h>
#include<iostream>
#include<cstdlib>
//****important to add following library to allow a programmer to use parallel paradigms*****
#include<omp.h>	
using namespace std;
#define MAX 10
int main()
{
float a[MAX],sum;
int i;
float deviation,sumsqr,mean,variance,stddeviation;
printf("\n First Vector:\t");

//Instruct a master thread to fork and generate more threads to process following loop structure
#pragma omp parallel for
for(i=0;i<MAX;i++)
	{
		a[i]=rand()%10;
	}

//Discuss issue of this for loop below-if we make it parallel, possibly values that get printed will not be in sequence as we dont have any control on order of threads execution
for(i=0;i<MAX;i++)
	{
		printf("%f\t",a[i]);
		sum+=a[i];
	}




printf("\n Parallel-Vector Addition:(a)\t");

printf("\n%f\n",sum);

   mean = sum/(float)MAX;                                   
                                                               
        for (i = 1 ; i<=MAX; i++)                               
        {                                                      
            deviation = a[i] - mean;                       
            sumsqr += deviation * deviation;                   
        }                                                      
        variance = sumsqr/(float)MAX ;                           
        stddeviation = sqrt(variance) ;                        
                                                               
        printf("\nNumber of items : %d\n",MAX);                  
        printf("Mean : %f\n", mean);                           
        printf("Standard deviation : %f\n", stddeviation);
	
}



/*
 root@comp414-desktop:/home/comp414/Downloads# g++ addvectors.cpp -fopenmp
root@comp414-desktop:/home/comp414/Downloads# ./a.out

 First Vector:	5.000000	6.000000	2.000000	7.000000	5.000000	3.000000	3.000000	6.000000	9.000000	1.000000	
 Parallel-Vector Addition:(a)	
47.000000

Number of items : 10
Mean : 4.700000
Standard deviation : 2.758623
root@comp414-desktop:/home/comp414/Downloads# 











*/
