#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int head, a[20], i, distance, n, seektime, size;
int main()
{   int check=1,op;
    do{
    printf("Select the Disk Schduling Algorithm that you would like to perform:\n1.C-SCAN\n2.SCAN\n3.FCFS\nYour Choice: ");
    scanf("%d",&op);
    switch(op)
    {
        case 1:
            
                seektime=0;
                printf("\nEnter Head position: ");
                scanf("%d", &head);

                printf("\nEnter number of disk requests: ");
                scanf("%d", &n);

                printf("\nEnter the disk size: ");
                scanf("%d", &size);

                printf("\nEnter the disk requests: ");
                for (i = 0; i < n; i++) {
                    scanf("%d", &a[i]);
                }

                a[n] = head;
                n++;
                a[n] = 0;        
                n++;
                a[n] = size - 1;
                n++;

                bubbleSort(a, n);

                int pos;
                for (i = 0; i < n; i++) {
                    if (a[i] == head) {
                        pos = i;
                        break;
                    }
                }

                printf("\n\tC-SCAN DISK SCHEDULING\n\n");

                for (i = pos; i < n - 1; i++) {
                    distance = a[i + 1] - a[i];
                    printf("Head movement from %d to %d : %d\n", a[i], a[i + 1], distance);
                    seektime += distance;
                }

                if (a[n - 1] != size - 1) {
                    distance = size - 1 - a[n - 2];
                    printf("Head movement from %d to %d : %d\n", a[n - 2], size - 1, distance);
                    seektime += distance;
                }

                if (a[0] != 0) {
                    distance = size - 1;
                    printf("Head movement from %d to %d : %d\n", size - 1, 0, distance);
                    seektime += distance;
                }

                for (i = 0; i < pos - 1; i++) {
                    distance = a[i + 1] - a[i];
                    printf("Head movement from %d to %d : %d\n", a[i], a[i + 1], distance);
                    seektime += distance;
                }

                printf("\nTotal seek time is : %d\n", seektime);
               
            break;
        case 2:
            
            seektime=0;
            printf("\nEnter Head position: ");
            scanf("%d", &head);


            printf("\nEnter number of disk requests: ");
            scanf("%d", &n);


            printf("\nEnter the disk size: ");
            scanf("%d", &size);


            printf("\nEnter the disk requests: ");
            for (i = 0; i < n; i++) {
                scanf("%d", &a[i]);
            }

            a[n] = head;
            n++;


            bubbleSort(a, n);

            pos=0;
            for (i = 0; i < n; i++) {
                if (a[i] == head) {
                    pos = i;
                    break;
                }
            }

        
            printf("\n\tSCAN DISK SCHEDULING\n\n");


            for (i = pos; i < n - 1; i++) {
                distance = a[i + 1] - a[i];
                printf("Head movement from %d to %d : %d\n", a[i], a[i + 1], distance);
                seektime += distance;
            }


            if (a[n - 1] != size - 1) {
                distance = size - 1 - a[n - 1];
                printf("Head movement from %d to %d : %d\n", a[n - 1], size - 1, distance);
                seektime += distance;
            }


            if (pos > 0) {
                printf("Head movement from %d to %d : %d\n", size - 1, a[pos - 1], size - 1 - a[pos - 1]);
                seektime += size - 1 - a[pos - 1];

                for (i = pos - 1; i > 0; i--) {
                    distance = a[i] - a[i - 1];
                    printf("Head movement from %d to %d : %d\n", a[i], a[i - 1], distance);
                    seektime += distance;
                }
            }


            printf("\nTotal seek time is : %d\n", seektime);
            
            break;
        case 3:
            seektime=0;
            printf("\nEnter Head position:");
            scanf("%d",&head);
            printf("\nEnter number of disk requests:");
            scanf("%d",&n);
            printf("\nEnter the disk requests:");
            for(i=1; i<=n; i++)
            scanf("%d",&a[i]);
            a[0]=head;
            printf("*****FCFS DISK SCHEDULING*****************\n");
            for(i=0;i<n;i++)
            {
                distance=(a[i]>a[i+1])?a[i]-a[i+1]:a[i+1]-a[i];
                printf("Head movement from %d to %d : %d\n",a[i],a[i+1],distance);
                seektime=seektime+distance;
            }
            printf("Total seek time is : %d\n",seektime);
            break;

        default:
            printf("Invalid Input - Exiting Operation");
            check=0;
            break;
    }
    }while(check>0);
}