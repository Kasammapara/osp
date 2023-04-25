Best fit
#include <stdio.h>

#define MAX_BLOCKS 100
#define MAX_PROCESSES 100

int main() {
    int nb, np, b[MAX_BLOCKS], p[MAX_PROCESSES], i, j, allocation[MAX_PROCESSES];

    printf("Enter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the size of each block:\n");
    for(i=0; i<nb; i++) scanf("%d", &b[i]);

    printf("Enter the number of processes: ");
    scanf("%d", &np);
    printf("Enter the size of each process:\n");
    for(i=0; i<np; i++) scanf("%d", &p[i]);

    for(i=0; i<np; i++) {
        allocation[i] = -1;
        for(j=0; j<nb; j++) {
            if(b[j] >= p[i] && (allocation[i] == -1 || b[j] < b[allocation[i]])) {
                allocation[i] = j;
            }
        }
        if(allocation[i] != -1) b[allocation[i]] -= p[i];
    }

    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for(i=0; i<np; i++) {
        printf("%d\t\t%d\t\t", i+1, p[i]);
        if(allocation[i] != -1) printf("%d\n", allocation[i]+1);
        else printf("Not Allocated\n");
    }

    return 0;
}



First fit
#include <stdio.h>

#define MAX_BLOCKS 100
#define MAX_PROCESSES 100

int main() {
    int nb, np, b[MAX_BLOCKS], p[MAX_PROCESSES], i, j, allocation[MAX_PROCESSES];

    printf("Enter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the size of each block:\n");
    for(i=0; i<nb; i++) scanf("%d", &b[i]);

    printf("Enter the number of processes: ");
    scanf("%d", &np);
    printf("Enter the size of each process:\n");
    for(i=0; i<np; i++) scanf("%d", &p[i]);

    for(i=0; i<np; i++) {
        allocation[i] = -1;
        for(j=0; j<nb; j++) {
            if(b[j] >= p[i]) {
                allocation[i] = j;
                b[j] -= p[i];
                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for(i=0; i<np; i++) printf("%d\t\t%d\t\t%s\n", i+1, p[i], allocation[i] != -1 ? (char[]){allocation[i]+1+'0', '\0'} : "Not Allocated");

    return 0;
}



Worst fit
#include <stdio.h>

#define MAX_BLOCKS 10 // Maximum number of memory blocks
#define MAX_PROCESSES 10 // Maximum number of processes

void worst_fit(int blocks[], int m, int processes[], int n);

int main() {
    int blocks[MAX_BLOCKS], processes[MAX_PROCESSES];
    int m, n, i;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);

    printf("Enter the size of each memory block:\n");
    for (i = 0; i < m; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blocks[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the size of each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processes[i]);
    }

    worst_fit(blocks, m, processes, n);

    return 0;
}

void worst_fit(int blocks[], int m, int processes[], int n) {
    int allocation[MAX_PROCESSES] = {-1}; // To store block allocation for each process
    int i, j;

    for (i = 0; i < n; i++) {
        int max_block_index = -1; // Index of the memory block with maximum size
        for (j = 0; j < m; j++) {
            if (blocks[j] >= processes[i]) {
                if (max_block_index == -1 || blocks[j] > blocks[max_block_index]) {
                    max_block_index = j;
                }
            }
        }

        if (max_block_index != -1) {
            allocation[i] = max_block_index;
            blocks[max_block_index] -= processes[i];
        }
    }

    printf("\nProcess\tProcess Size\tBlock Index\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t", i + 1, processes[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }
}

