Fcfs page 
#include <stdio.h>
#include <stdbool.h>

#define MAX_FRAMES 10 // Maximum number of page frames
#define MAX_PAGES 50 // Maximum number of pages in the reference string

void fcfs(int frames[], int n, int pages[], int m);

int main() {
    int frames[MAX_FRAMES], pages[MAX_PAGES];
    int n, m, i;

    printf("Enter the number of page frames: ");
    scanf("%d", &n);

    printf("Enter the size of reference string: ");
    scanf("%d", &m);

    printf("Enter the reference string:\n");
    for (i = 0; i < m; i++) {
        printf("Page %d: ", i + 1);
        scanf("%d", &pages[i]);
    }

    fcfs(frames, n, pages, m);

    return 0;
}

void fcfs(int frames[], int n, int pages[], int m) {
    int i, j, k = 0, faults = 0;
    bool is_present;

    for (i = 0; i < m; i++) {
        is_present = false;

        // Check if page is already present in any frame
        for (j = 0; j < n; j++) {
            if (frames[j] == pages[i]) {
                is_present = true;
                break;
            }
        }

        // If page is not present, replace the oldest page in the frame
        if (!is_present) {
            frames[k] = pages[i];
            k = (k + 1) % n;
            faults++;
        }

        printf("\nReference String: ");
        for (j = 0; j <= i; j++) {
            printf("%d ", pages[j]);
        }

        printf("\nCurrent Page Frames: ");
        for (j = 0; j < n; j++) {
            printf("%d ", frames[j]);
        }

        printf("\nPage Faults: %d\n", faults);
    }
}






Lru 
#include <stdio.h>
#include <stdbool.h>

#define MAX_FRAMES 10 // Maximum number of page frames
#define MAX_PAGES 50 // Maximum number of pages in the reference string

void lru(int frames[], int n, int pages[], int m);

int main() {
    int frames[MAX_FRAMES], pages[MAX_PAGES];
    int n, m, i;

    printf("Enter the number of page frames: ");
    scanf("%d", &n);

    printf("Enter the size of reference string: ");
    scanf("%d", &m);

    printf("Enter the reference string:\n");
    for (i = 0; i < m; i++) {
        printf("Page %d: ", i + 1);
        scanf("%d", &pages[i]);
    }

    lru(frames, n, pages, m);

    return 0;
}

void lru(int frames[], int n, int pages[], int m) {
    int i, j, k, faults = 0, min, max;
    int counter[MAX_FRAMES] = {0};
    bool is_present;

    for (i = 0; i < m; i++) {
        is_present = false;

        // Check if page is already present in any frame
        for (j = 0; j < n; j++) {
            if (frames[j] == pages[i]) {
                is_present = true;
                counter[j] = i;
                break;
            }
        }

        // If page is not present, replace the least recently used page in the frame
        if (!is_present) {
            min = counter[0];
            k = 0;
            for (j = 1; j < n; j++) {
                if (counter[j] < min) {
                    min = counter[j];
                    k = j;
                }
            }
            frames[k] = pages[i];
            counter[k] = i;
            faults++;
        }

        printf("\nReference String: ");
        for (j = 0; j <= i; j++) {
            printf("%d ", pages[j]);
        }

        printf("\nCurrent Page Frames: ");
        for (j = 0; j < n; j++) {
            printf("%d ", frames[j]);
        }

        printf("\nPage Faults: %d\n", faults);
    }
}






Opr 
#include <stdio.h>
#include <stdbool.h>

#define MAX_FRAMES 10 // Maximum number of page frames
#define MAX_PAGES 50 // Maximum number of pages in the reference string

void opr(int frames[], int n, int pages[], int m);

int main() {
    int frames[MAX_FRAMES], pages[MAX_PAGES];
    int n, m, i;

    printf("Enter the number of page frames: ");
    scanf("%d", &n);

    printf("Enter the size of reference string: ");
    scanf("%d", &m);

    printf("Enter the reference string:\n");
    for (i = 0; i < m; i++) {
        printf("Page %d: ", i + 1);
        scanf("%d", &pages[i]);
    }

    opr(frames, n, pages, m);

    return 0;
}

void opr(int frames[], int n, int pages[], int m) {
    int i, j, k, faults = 0, max, index;
    bool is_present;

    for (i = 0; i < m; i++) {
        is_present = false;

        // Check if page is already present in any frame
        for (j = 0; j < n; j++) {
            if (frames[j] == pages[i]) {
                is_present = true;
                break;
            }
        }

        // If page is not present, replace the page that will not be used for the longest period of time
        if (!is_present) {
            faults++;

            // Find the page that will not be used for the longest period of time
            max = -1;
            for (j = 0; j < n; j++) {
                for (k = i + 1; k < m; k++) {
                    if (frames[j] == pages[k]) {
                        if (k > max) {
                            max = k;
                            index = j;
                        }
                        break;
                    }
                    else if (k == m - 1 && max == -1) {
                        index = j;
                    }
                }
            }

            frames[index] = pages[i];
        }

        printf("\nReference String: ");
        for (j = 0; j <= i; j++) {
            printf("%d ", pages[j]);
        }

        printf("\nCurrent Page Frames: ");
        for (j = 0; j < n; j++) {
            printf("%d ", frames[j]);
        }

        printf("\nPage Faults: %d\n", faults);
    }
}
