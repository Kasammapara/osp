sstf
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, head, total = 0;
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);
    int requests[n];
    printf("Enter the requests in order: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }
    printf("Enter the initial position of the head: ");
    scanf("%d", &head);
    total += abs(head - requests[0]);
    for(i = 1; i < n; i++) {
        total += abs(requests[i] - requests[i-1]);
    }
    printf("Total head movement = %d", total);
    return 0;
}




fcfs disk
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, head, pos, total = 0, min;
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);
    int requests[n];
    printf("Enter the requests: ");
    for(i = 0; i < n; i++)
        scanf("%d", &requests[i]);
    printf("Enter the initial position of the head: ");
    scanf("%d", &head);
    for(i = 0; i < n; i++) {
        min = 1e9;
        for(j = 0; j < n; j++) {
            if(abs(requests[j] - head) < min) {
                min = abs(requests[j] - head);
                pos = j;
            }
        }
        total += min;
        head = requests[pos];
        requests[pos] = 1e9;
    }
    printf("Total head movement = %d", total);
    return 0;
}




Look disk
#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 1000

void swap(int x, inty) {
    int temp = *x;
    x =y;
    *y = temp;
}

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

int main() {
    int requests[MAX_REQUESTS];
    int n, head, total_distance = 0;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    printf("Enter the requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the starting head position: ");
    scanf("%d", &head);

    sort(requests, n);

    int index = 0;
    while (index < n && requests[index] < head) {
        index++;
    }

    // Move towards higher requests
    for (int i = index; i < n; i++) {
        total_distance += abs(head - requests[i]);
        head = requests[i];
    }

    // Move towards lower requests
    for (int i = index - 1; i >= 0; i--) {
        total_distance += abs(head - requests[i]);
        head = requests[i];
    }

    printf("Total head movement: %d\n", total_distance);

    return 0;
}



Scan disk 
#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 1000

void swap(int x, inty) {
    int temp = *x;
    x =y;
    *y = temp;
}

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

int main() {
    int requests[MAX_REQUESTS];
    int n, head, total_distance = 0;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    printf("Enter the requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the starting head position: ");
    scanf("%d", &head);

    sort(requests, n);

    int index = 0;
    while (index < n && requests[index] < head) {
        index++;
    }

    // Move towards higher requests
    for (int i = index; i < n; i++) {
        total_distance += abs(head - requests[i]);
        head = requests[i];
    }

    // Move towards lower requests
    total_distance += abs(head - requests[index-1]);
    head = requests[index-1];
    for (int i = index - 2; i >= 0; i--) {
        total_distance += abs(head - requests[i]);
        head = requests[i];
    }

    printf("Total head movement: %d\n", total_distance);

    return 0;
}
