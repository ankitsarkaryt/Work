#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Process {
 public :
    int id;
    int at;
    int bt;
    int ct;
    int rt;
    int prior;
    int m;
};

void priorityScheduling(Process p[], int n) {
    vector< Process* > q;
    int currTime = p[0].at; 
    q.push_back(&p[0]);
    
    while(!q.empty()){ 
       int min=0;
       Process * temp =  q[0];
       for(int i=0;i<q.size();i++){
 	   if(temp->prior < q[i]->prior){
 		min=i;
 		temp=q[i];
           }
           else if(temp->prior==q[i]->prior){           	
   		if(temp->at> q[i]->at){
   		 temp=q[i];
   		 min=i;
   		} 
   	  }	   
       }    		
       if (temp->at<= currTime && temp->rt > 0){
          
            temp->rt -= 1;
            currTime += 1;
            
            temp->m=1;
            if (temp->rt == 0) {
                   temp->ct=currTime;
            }
            for(int i=0;i<n;i++){
              if(p[i].m==0 && p[i].at<=currTime){
                  q.push_back(&p[i]);
                  p[i].m=1;
              }    
            }
            if (temp->rt > 0) {
                  q.push_back(temp);
            } 
            q.erase(q.begin()+min);
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
        cin >> p[i].prior;
        cin >> p[i].at;
        cin >> p[i].bt;
        p[i].rt= p[i].bt;
        p[i].m=0;
    }
    cout<< "comp"<<endl;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
           if(p[j].at > p[j+1].at){
		Process temp =p[j];
		p[j]=p[j+1];
		p[j+1]=temp;
	   }
	 }
     }	
     cout<< "comp"<<endl;   	
    priorityScheduling(p, n);
     cout<< "comp"<<endl;  
   cout<<"process_id"<<"\t"<<"arrival time"<<"\t"<<"burst time"<<"\t"<<"priority"<<"\t"<<"completion time"<<"\t"<<"turnaround time"<<"\t"<<"waiting time"<<endl;
    for(int i=0;i<n;i++){
     cout<<p[i].id<<"\t\t"<<p[i].at<<"\t\t"<<p[i].bt<<"\t\t"<<p[i].prior<<"\t\t"<<p[i].ct<<"\t\t"<<p[i].ct-p[i].at<<"\t\t"<<p[i].ct-p[i].at-p[i].bt<<endl;
     }
   
    return 0;
}