#include <stdio.h>

int main()
{
    int n, W;
    int p[100], w[100];
    int cur_w;
    float tot_v = 0;
    int i, maxi;
    int used[100];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the maximum capacity of the bag: ");
    scanf("%d", &W);

    printf("Enter the weight and value of each item (weight value):\n");
    for (i = 0; i < n; ++i) {
        scanf("%d%d", &p[i], &w[i]);
    }

    for (i = 0; i < n; ++i)
        used[i] = 0;

    cur_w = W;

    while (cur_w > 0) {
        maxi = -1;
        for (i = 0; i < n; ++i)
            if ((used[i] == 0) &&
                ((maxi == -1) || ((float)w[i]/p[i] > (float)w[maxi]/p[maxi])))
                maxi = i;

        if (maxi == -1) break;

        used[maxi] = 1;
        cur_w -= p[maxi];
        tot_v += w[maxi];

        if (cur_w < 0) {
            tot_v -= w[maxi];
            tot_v += (1 + (float)cur_w/p[maxi]) * w[maxi];
        }
    }

    printf("Filled the bag with objects worth %.2f.\n", tot_v);

    return 0;
}
