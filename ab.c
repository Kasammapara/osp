Fcfs scheduling
#include<stdio.h>

int main() {
    int n, i, waiting_time = 0, turnaround_time = 0;
    float avg_waiting_time, avg_turnaround_time;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int bt[n], at[n], wt[n], tat[n];

    // get input for burst time and arrival time of each process
    printf("Enter burst time and arrival time for each process:\n");
    for(i=0; i<n; i++) {
        printf("Process %d: ", i+1);
        scanf("%d %d", &bt[i], &at[i]);
    }

    // calculate waiting time and turnaround time for each process
    for(i=0; i<n; i++) {
        if(i == 0) {
            wt[i] = 0;
        } else {
            wt[i] = wt[i-1] + bt[i-1] - at[i];
            if(wt[i] < 0) {
                wt[i] = 0;
            }
        }
        tat[i] = wt[i] + bt[i];
        waiting_time += wt[i];
        turnaround_time += tat[i];
    }

    // calculate average waiting time and average turnaround time
    avg_waiting_time = (float)waiting_time / n;
    avg_turnaround_time = (float)turnaround_time / n;

    // print the results
    printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for(i=0; i<n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i+1, bt[i], at[i], wt[i], tat[i]);
    }
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}




Sjf scheduling
#include<stdio.h>

int main() {
    int n, i, j, min_index, total_time = 0;
    float avg_waiting_time = 0, avg_turnaround_time = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int bt[n], at[n], wt[n], tat[n], ct[n];

    printf("Enter burst time and arrival time for each process:\n");
    for(i=0; i<n; i++) {
        printf("Process %d: ", i+1);
        scanf("%d %d", &bt[i], &at[i]);
    }

    for(i=0; i<n; i++) {
        min_index = i;
        for(j=i+1; j<n; j++) {
            if(bt[j] < bt[min_index] && at[j] <= total_time) {
                min_index = j;
            }
        }
        if(min_index != i) {
            int temp = bt[i];
            bt[i] = bt[min_index];
            bt[min_index] = temp;
            temp = at[i];
            at[i] = at[min_index];
            at[min_index] = temp;
        }
        wt[i] = total_time - at[i];
        tat[i] = wt[i] + bt[i];
        ct[i] = total_time + bt[i];
        total_time += bt[i];
        avg_waiting_time += wt[i];
        avg_turnaround_time += tat[i];
    }

    printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for(i=0; i<n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, bt[i], at[i], wt[i], tat[i], ct[i]);
    }
    printf("Average Waiting Time: %.2f\n", avg_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time / n);

    return 0;
}




RR
#include <stdio.h>

#define MAX_PROCESS 10 // Maximum number of processes
#define TIME_QUANTUM 2 // Time quantum

struct process {
    int pid; // Process ID
    int burst_time; // Burst time
    int remaining_time; // Remaining time
    int waiting_time; // Waiting time
    int turnaround_time; // Turnaround time
};

void calculate_time(struct process p[], int n);
void display(struct process p[], int n);

int main() {
    struct process p[MAX_PROCESS];
    int n, i;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    printf("Enter burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i+1);
        scanf("%d", &p[i].burst_time);
        p[i].remaining_time = p[i].burst_time;
        p[i].pid = i+1;
    }
    
    calculate_time(p, n);
    display(p, n);
    
    return 0;
}

void calculate_time(struct process p[], int n) {
    int i, time = 0, completed = 0, flag = 0;
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    
    while (completed != n) {
        flag = 0;
        for (i = 0; i < n; i++) {
            if (p[i].remaining_time > 0) {
                flag = 1;
                if (p[i].remaining_time > TIME_QUANTUM) {
                    time += TIME_QUANTUM;
                    p[i].remaining_time -= TIME_QUANTUM;
                } else {
                    time += p[i].remaining_time;
                    p[i].waiting_time = time - p[i].burst_time;
                    p[i].remaining_time = 0;
                    p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
                    completed++;
                }
            }
        }
        if (flag == 0) // All processes are completed
            break;
    }
    
    for (i = 0; i < n; i++) {
        avg_waiting_time += p[i].waiting_time;
        avg_turnaround_time += p[i].turnaround_time;
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    
    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);
}

void display(struct process p[], int n) {
    int i;
    
    printf("PID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time);
    }
}
