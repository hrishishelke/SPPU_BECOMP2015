#include<iostream>
using namespace std;

struct H_table{
	int h;
	int t[9];
};

class BFS
{
	public:
	H_table HT[50];
	int visited[50];
	int k;
	BFS(){
		for(int i = 0; i<50; i++)
			visited[i] = 0;
		k = 0;	
	}
	
	int display(int a[]);
	int explore(int a[], int t);
	void left_move(int a[],int t);
	void right_move(int a[],int t);
	void up_move(int a[],int t);
	void down_move(int a[],int t);
	void getHeuristic(int a[]);
	
};
	void BFS::getHeuristic(int a[])
	{
		int h = 0;
		for(int i = 0; i < 9; i++)
		{
			HT[k].t[i] = a[i];
			if(a[i] == i+1)
				h++;
		}
		HT[k].h = h;
		k++; 
	}	
	int BFS::explore(int a[], int t)
	{
		int v1[9], v2[9], v3[9], v4[9], i = 0;
		int h;
		for(i = 0; i < 9; i++)
		{
			v1[i]=a[i]; v2[i]=a[i]; v3[i]=a[i]; v4[i]=a[i];
		}
		
		//Left Move
		left_move(v1,t);
		
		//Right Move
		right_move(v2,t);
		
		//Up Move
		up_move(v3,t);
		
		//Down Move
		down_move(v4,t);
				
		//Find Maximum Heuristic Value	
		int j , t1 = 0;
		for(i = 0; i < k; i++)
		{
			if(t1 < HT[i].h && visited[i]==0)
			{
				t1 = HT[i].h;
				j = i;
			}
		}
		visited[j] = 1;
		
		return j;
				
	}
	void BFS::left_move(int a[], int t)
	{	int temp;
		if(t != 0 && t != 3 && t != 6)
		{
			temp = a[t];
			a[t] = a[t-1];
			a[t-1] = temp;
			getHeuristic(a);
		}
	}
	void BFS::right_move(int a[],int t)
	{	int temp;
		if(t != 2 && t != 5 && t != 8)
		{
			temp = a[t];
			a[t] = a[t+1];
			a[t+1] = temp;
			getHeuristic(a);
		}
		
	}
	void BFS::up_move(int a[],int t)
	{
		int temp;
		if(t != 1 && t != 2 && t != 3)
		{
			temp = a[t];
			a[t] = a[t-3];
			a[t-3] = temp;
			getHeuristic(a);
		}
	}
	void BFS::down_move(int a[],int t)
	{
		int temp;
		if(t != 7 && t != 8 && t != 9)
		{
			temp = a[t];
			a[t] = a[t+3];
			a[t+3] = temp;
			getHeuristic(a);
		}
		
	}
	
	int BFS::display(int t[])
	{	int i, count = 0, k;
		for(i = 0; i < 9; i++)
		{
			if(t[i] == 0){
				cout<<"-"<<" ";
				k = i;
			}
			else
			{
				cout<<t[i]<<" ";
			}
			count++;
			if(count == 3)
			{
				cout<<"\n";
				count = 0;
			}
		}
		cout<<"\n";
		return k;
	}
int main()
{
	BFS b;
	int i, p, a[9] = {0, 1, 2, 5, 6, 3, 4, 7, 8}, aa = 0;
		
	cout<<"\nInitial State: \n";
	b.display(a);
	cout<<"\nGoal State: \n";
	cout<<"1 2 3\n4 5 6\n7 8 -\n";
	cout<<"\nProcess for reaching goal state: \n";
	b.display(a);
	aa = b.explore(a,p);
	do{
		p = b.display(b.HT[aa].t);
		cout<<"Heuristic is "<<b.HT[aa].h<<endl;
		aa = b.explore(b.HT[aa].t,p);
	}while(b.HT[aa].h != 8);
	p = b.display(b.HT[aa].t);
	return 0;
}
