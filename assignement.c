#include <stdio.h>

int main()
{
    int n, cost[10][10];
    int i, j, min, sum = 0, assigned[10] = {0};

    printf("Enter number of jobs/workers: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    for (i = 0; i < n; i++) {
        min = 9999;
        int min_index = -1;
        for (j = 0; j < n; j++) {
            if (!assigned[j] && cost[i][j] < min) {
                min = cost[i][j];
                min_index = j;
            }
        }
        assigned[min_index] = 1;
        sum += min;
        printf("Worker %d assigned to Job %d with cost %d\n", i + 1, min_index + 1, min);
    }

    printf("Minimum total cost: %d\n", sum);

    return 0;
}
