#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int arr[], int n) {
    int i,j,min_idx;
    for(i=0;i<n-1;i++) {
        min_idx = i;
        for(j=j+1;j<n;j++)
            if(arr[j]<arr[min_idx])
                min_idx = j;
            if(min_idx!=i)
                swap(&arr[min_idx], &arr[i]);
    }
}

int main() {
    int arr[100];
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    pid_t pid = fork();

    if (pid == -1) {
        printf("Failed to create a child process\n");
        exit(1);
    } else if (pid == 0) { // child process
        printf("Sorting in the child process...\n");
        selectionSort(arr, n);
        printf("Sorted array in the child process: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        exit(0);
    } else { // parent process
        printf("Sorting in the parent process...\n");
        selectionSort(arr, n);
        printf("Sorted array in the parent process: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        wait(NULL); // wait for the child process to finish
        sleep(10); // sleep for 10 seconds to demonstrate zombie state
    }

    printf("Process %d is finished\n", getpid());
    return 0;
}
