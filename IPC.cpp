#include <iostream>
#include <queue>
using namespace std;

class Process {
 public :
    int id;
    int at;
    int bt;
    int ct;
    int rt;
    int m;
};

void roundRobinScheduling(Process p[], int n, int time) {
    queue< Process* > q;
    int currTime = 0; 
    q.push(&p[0]);
    while(!q.empty()){    
       if (q.front()->at<= currTime && q.front()->rt > 0){
            int executionTime = min(time, q.front()->rt);
            q.front()->rt -= executionTime;
            currTime += executionTime;
            
            q.front()->m=1;
            if (q.front()->rt == 0) {
                   q.front()->ct=currTime;
            }
            for(int i=0;i<n;i++){
              if(p[i].m==0 && p[i].at<=currTime){
                  q.push(&p[i]);
                  p[i].m=1;
              }    
            }
            if (q.front()->rt > 0) {
                  q.push(q.front());
            } 
            q.pop();
       }
       else currTime++;
    } 		  
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    Process p[n];
    cout << "Enter arrival time and burst time for processes"<<endl;
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        cin >> p[i].at;
        cin >> p[i].bt;
        p[i].rt= p[i].bt;
        p[i].m=0;
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
           if(p[j].at > p[j+1].at){
		Process temp =p[j];
		p[j]=p[j+1];
		p[j+1]=temp;
	   }
	 }
     }	   	
    int time = 2;
    roundRobinScheduling(p, n, time);
     
   cout<<"process_id"<<"\t"<<"arrival time"<<"\t"<<"burst time"<<"\t"<<"completion time"<<"\t"<<"turnaround time"<<"\t"<<"waiting tiem"<<endl;
    for(int i=0;i<n;i++)
     cout<<p[i].id<<"\t\t"<<p[i].at<<"\t\t"<<p[i].bt<<"\t\t"<<p[i].ct<<"\t\t"<<p[i].ct-p[i].at<<"\t\t"<<p[i].ct-p[i].at-p[i].bt<<endl;
   
    return 0;
}
