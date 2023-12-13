#include<stdio.h>
#include<stdlib.h>
int mutex=1,full=0,empty=3,x=0;

int wait(int s){
 return --s;
}
int signal(int s){
 return ++s;
}

void produce(){
 mutex=wait(mutex);
 full=signal(full);
 empty=wait(empty);
 x++;
 printf("\n producer produces the item %d \n",x);
 mutex=signal(mutex);
}

void consume(){
 mutex=wait(mutex);
 full=wait(full);
 empty=signal(empty);
 printf("\n consumer consumes item %d \n",x);
 x--;
 mutex=signal(mutex);
}
void main(){
 int n;
 printf("1:producer 2:consumer 3:exit \n");
 while(1){
  printf("enter choice:  ");
  scanf("%d",&n);
  switch(n)
  {
   case 1:
      if(mutex==1 && empty!=0) produce();
      else printf("buffer is full\n");
      break;
   case 2:
      if(mutex==1 && full!=0) consume();
      else printf("buffer is empty\n");
      break;
   case 3:
      exit(0);
      break;
  }
 }
}