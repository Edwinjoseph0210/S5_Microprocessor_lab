#include <stdio.h>

int swap(int *a, int *b)
{
int t;
t = *a;
*a = *b;
*b = t;
return 0;
}

int main()
{   int op;
   int i,j,k, bt[30];
    float awt,avg_tat,avg_wt;
    int p[30],tot_tat=0,pr[30],wt[30],n,tot_wt=0,tat[30],PR_wt=0,PR_tat=0;

   do{
    printf("Enter the Disk Scheduling to be performed: \n1. FCFS\n2. SJF\n3. Priority\n4. Round Robin\n");
    scanf("%d",&op);

    switch(op)
    {   int pno;
        case 1:
            printf("****** FCFS Scheduling ******\n");
         
            printf("\nEnter the no.of processes \n");
            scanf("%d",&n);
            printf("Enter burst time for each process\n");
            for(i=0;i<n;i++)
            {
                scanf("%d",&bt[i]);
                p[i] = i;
            }
            printf("\n FCFS Algorithm \n");
            for(i=0;i<n;i++)
            {
                if(i==0)
                tat[i] = bt[i];
                else
                tat[i] = tat[i-1] + bt[i];
                tot_tat=tot_tat+tat[i];
            }
            wt[0]=0;
            for(i=1;i<n;i++)
            {
                wt[i]=wt[i-1]+bt[i-1];
                tot_wt = tot_wt+wt[i];
            }
            printf("\nPROCESS\t\tBURST TIME\tTURN AROUND TIME\tWAITING TIME");
            for(i=0; i<n; i++)
                printf("\nprocess[%d]\t\t%d\t\t%d\t\t%d",p[i],bt[i],tat[i],wt[i]);
            printf("\n\nTotal Turn around Time:%d",tot_tat);
            printf("\nAverage Turn around Time :%d ", tot_tat/n);
            printf("\nTotal Waiting Time:%d",tot_wt);
            printf("\nTotal avg. Waiting Time:%d",tot_wt/n);
            int tempp=0;
            printf("\n======================================\n");
            for( i=0; i<n; i++)
            {
                printf("   P%d   ",i);
            }
            
            printf("\n======================================\n");
            for( i=0; i<=n; i++)
            {
                printf("%d\t",tempp);
                tempp=tempp+bt[i];
            }
            printf("\n");
            break;

        case 2:
            printf("****** SJF Scheduling ******\n");
            int p[30],tot_tat=0,wt[30],n,tot_wt=0,tat[30],SJF_wt=0,SJF_tat=0;
        
            printf("\nEnter the no.of processes \n");
            scanf("%d",&n);
            printf("Enter burst time for each process\n");
            for(i=0;i<n;i++)
            {
                scanf("%d",&bt[i]);
                p[i] = i;
            }
            for(i=0;i<n;i++)
            {
                for(j=i+1;j<n;j++)
                {
                    if(bt[i]>bt[j])
                    {
                        swap(&bt[j],&bt[i]);
                        swap(&p[j],&p[i]);
                    }
                }
            }
            for(i=0;i<n;i++)
            {
                if(i==0)
                    tat[i] = bt[i];
                else
                    tat[i] = tat[i-1] + bt[i];
                    tot_tat=tot_tat+tat[i];
            }
            wt[0]=0;
            for(i=1;i<n;i++)
            {
                wt[i]=wt[i-1]+bt[i-1];
                tot_wt = tot_wt+wt[i];
            }
            printf("\nPROCESS\t\tBURST TIME\tTURN AROUND TIME\tWAITING TIME");
            for(i=0; i<n; i++)
                printf("\nprocess[%d]\t\t%d\t\t%d\t\t%d",p[i]+1,bt[i],tat[i],wt[i]);
            printf("\n\nTotal Turn around Time:%d",tot_tat);
            printf("\nAverage Turn around Time :%d ", tot_tat/n);
            printf("\nTotal Waiting Time:%d",tot_wt);
            printf("\nTotal avg. Waiting Time:%d",tot_wt/n);

            printf("\n======================================\n");
            for( i=0; i<n; i++)
            {
                printf("   P%d   ",p[i]);
            }
            
            printf("\n======================================\n");
            tempp=0;
            for( i=0; i<=n; i++)
            {
                printf("%d\t",tempp);
                tempp=tempp+bt[i];
            }
            printf("\n");
            break;

        case 3:
            
            printf("****** Priority Scheduling ******\n");
            printf("\nEnter the no.of processes \n");
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
            printf("Enter burst time and priority of process[%d]:",i+1);
            scanf("%d%d",&bt[i],&pr[i]);
            p[i] = i;
            }
            for(i=0;i<n;i++)
            {
            for(j=0;j<n-1-i;j++)
            {
            if(pr[j]>pr[j+1])
            {
            swap(&bt[j],&bt[j+1]);
            swap(&p[j],&p[j+1]);
            swap(&pr[j],&pr[j+1]);
            }}}
            for(i=0;i<n;i++)
            {
            if(i==0)
            tat[i] = bt[i];
            else
            tat[i] = tat[i-1] + bt[i];
            tot_tat=tot_tat+tat[i];
            }
            wt[0]=0;
            for(i=1;i<n;i++)
            {
            wt[i]=wt[i-1]+bt[i-1];
            tot_wt = tot_wt+wt[i];
            }
            printf("\nPROCESS\t\tBURST TIME\tPRIORITY\tTURN AROUND TIME\tWAITINGTIME");
            for(i=0; i<n; i++)
            printf("\nprocess[%d]\t\t%d\t\t%d\t\t%d\t\t%d",p[i]+1,bt[i],pr[i],tat[i],wt[i]);
            printf("\n\nTotal Turn around Time:%d",tot_tat);
            printf("\nAverage Turn around Time :%d ", tot_tat/n);
            printf("\nTotal Waiting Time:%d",tot_wt);
            printf("\nTotal avg. Waiting Time:%d",tot_wt/n);

            printf("\n======================================\n");
            for( i=0; i<n; i++)
            {
                printf("   P%d   ",p[i]);
            }
            
            printf("\n======================================\n");
            int temppp=0;
            for( i=0; i<=n; i++)
            {
                printf("%d\t",temppp);
                temppp=temppp+bt[i];
            }
            printf("\n");
            break;

        case 4:
            printf("****** Round Robin Scheduling ******\n");

            int i, limit, total = 0, x, counter = 0, time_quantum , j=0 , k=0,sum=0;
            int wait_time = 0, turnaround_time = 0, burst_time[10], temp[10] , gc[50] , id[50];
            float average_wait_time, average_turnaround_time;
            printf("\nEnter Total Number of Processes: ");
            scanf("%d", &limit);
            x  = limit;
            for(i = 0; i < limit; i++) 
            {
                printf("\nEnter Burst Time of Process P[%d]: ", i);
                scanf("%d", &burst_time[i]);
                temp[i] = burst_time[i];
            }
            printf("\nEnter Time Quantum: ");
            scanf("%d", &time_quantum);
            printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
            for(total = 0, i = 0; x != 0;) 
            {
                if(temp[i] <= time_quantum && temp[i] > 0) 
                {
                    total = total + temp[i];
                    gc[j++]=temp[i];
                    id[k++]=i;
                    temp[i] = 0;
                    counter = 1;
                }
                else if(temp[i] > time_quantum) 
                {
                    temp[i] = temp[i] - time_quantum;
                    gc[j++]=time_quantum;
                    id[k++]=i;
                    total = total + time_quantum;
                }

                    if(temp[i] == 0 && counter == 1) 
                {
                    x--;
                    printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i , burst_time[i], total, total - burst_time[i]);
                    wait_time = wait_time + total - burst_time[i];
                    turnaround_time = turnaround_time + total ;
                    counter = 0;
                }
                if(i == limit - 1) 
                    i = 0;
                else 
                    i++;
            }
            printf("\nGantt chart");
            printf("\n-----------------------------------------------------------------\n");
            for (i = 0; i < k; i++)
                printf("    P%d\t",id[i]);
                printf("\n-----------------------------------------------------------------\n");
            int temp12=0;
            for (int m = 0; m <= j; m++)
            {
                printf("%d\t",temp12);
                temp12+=gc[m];
            }
            average_wait_time = wait_time * 1.0 / limit;
            average_turnaround_time = turnaround_time * 1.0 / limit;
            printf("\n\nAverage Waiting Time:\t%f", average_wait_time);
            printf("\nAvg Turnaround Time:\t%f\n", average_turnaround_time);

            break;

        default:
            printf("Invalid Operation - Exiting Program");
            op=0;
            break;
    }
   }while (op>0);
   
   
    
}