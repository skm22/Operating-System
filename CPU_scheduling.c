/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<stdio.h> 
int main() 
{ 
int time,remain;
  int num,j,n;
  
  int flag=0,q_time=10; 
  int w_time=0,TAT=0,arrival_time[10],BT[10],rt[10]; 
  printf("\n\nWrite  the Total number of Process:\t "); 
  scanf("%d",&n); 
  remain=n; 
  for(num=0;num<n;num++) 
  { 
    printf("Enter Burst Time and Arrival Time for Process Process Number %d :",num+1); 
    scanf("%d",&BT[num]); 
    scanf("%d",&arrival_time[num]); 
    rt[num]=BT[num]; 
  } 
  printf("Enter Time Quantum:%d\t",q_time); 

  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
  for(time=0,num=0;remain!=0;) 
  { 
    if(rt[num]<=q_time && rt[num]>0) 
    { 
      time+=rt[num]; 
      rt[num]=0; 
      flag=1; 
    } 
    else if(rt[num]>0) 
    { 
      rt[num]-=q_time; 
      time+=q_time; 
    } 
    if(rt[num]==0 && flag==1) 
    { 
      remain--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",num+1,time-arrival_time[num],time-arrival_time[num]-BT[num]); 
      w_time+=time-arrival_time[num]-BT[num]; 
     TAT+=time-arrival_time[num]; 
      flag=0; 
    } 
    if(num==n-1) 
      num=0; 
    else if(arrival_time[num+1]<=time) 
      num++; 
    else 
      num=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",w_time*1.0/n); 
  printf("\nAverage Turnaround Time = %f",TAT*1.0/n); 

  return 0; 
}
