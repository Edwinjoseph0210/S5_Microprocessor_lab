#include <stdio.h>

int main() {
    int avail[10], alloc[10][10], max[10][10], need[10][10], maxres[10], m, n, i, j, k, sum;
    int finish[10], safeseq[10], ind = 0;

    printf("\nEnter the number of processes and the number of resources:\n");
    scanf("%d %d", &n, &m);

    printf("\nEnter maximum instances of resources\n");
    for (j = 0; j < m; j++) {
        scanf("%d", &maxres[j]);
        avail[j] = maxres[j];
    }

    printf("\nEnter the Allocated Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("\nEnter the Max Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    printf("\nThe Need Matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    for (j = 0; j < m; j++) { 
        sum = 0;
        for (i = 0; i < n; i++) {
            sum += alloc[i][j];
        }
        avail[j] -= sum;
    }

    for (k = 0; k < n; k++) {
        finish[k] = 0;
    }

    int y = 0;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int safe = 1; 
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        safe = 0; 
                        break;
                    }
                }
                if (safe) {
          
                    safeseq[ind++] = i;
                    for (y = 0; y < m; y++) {
                        avail[y] += alloc[i][y];
                    }
                    finish[i] = 1;
                }
            }
        }
    }


    int all_safe = 1;
    for (i = 0; i < n; i++) {
        if (finish[i] == 0) {
            all_safe = 0;
            break;
        }
    }

    if (!all_safe) 
	{
        printf("System is in an unsafe state.\n");
    } else {
        printf("\nFollowing is the SAFE Sequence:\n");
        for (i = 0; i < n - 1; i++) {
            printf(" P%d ->", safeseq[i]);
        }
        printf(" P%d\n", safeseq[n - 1]);
    }

    return 0;
}