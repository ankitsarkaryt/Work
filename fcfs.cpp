#include<iostream>
using namespace std;
void findWaitingTime(int n,int bt[], int wt[],int tat[])
{
	for (int i = 0; i < n ; i++ )
		wt[i] = tat[i]-bt[i];
}
void findTurnAroundTime( int n,int at[], int ct[], int tat[])
{
	for (int i = 0; i < n ; i++)
		tat[i] = ct[i]-at[i];
}
void completiontime(int at[],int ct[],int n,int bt[]){
	ct[0]=bt[0];
    for(int i=1;i<n;i++)
        ct[i]=max(ct[i-1],at[i])+bt[i];
    
}
void findavgTime(  int n, int bt[],int at[])
{
	int wt[n], tat[n],ct[n] , total_wt = 0, total_tat = 0;
    completiontime(at,ct,n,bt);
	findTurnAroundTime( n, at, ct, tat);
	findWaitingTime(n,bt,wt,tat);
	cout << "Processes "<< " arrival time "<< " burst time " << " completion time "<<" Turn Around Time "<<" Waiting Time\n";
	for (int i=0; i<n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		cout << " " << i+1 << "\t\t" << at[i] <<"\t\t"
			<< bt[i] <<"\t\t " << ct[i] <<"\t\t" <<tat[i]<<"\t\t"<< wt[i]<<"\n";
	}

	cout << "Average waiting time = "
		<< (float)total_wt / (float)n;
	cout << "\nAverage turn around time = "
		<< (float)total_tat / (float)n;
}
int main()
{
	int n;
	cout<<"enter the number of processes ";
	cin>>n;
	int burst_time[n] ;
    int arrival_time[n];
	for(int i=0;i<n;i++){
		cin>>arrival_time[i]>>burst_time[i];
	}
	findavgTime( n, burst_time,arrival_time);
	return 0;
}