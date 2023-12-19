#include <stdio.h>
int main()
{

    int arrival_time[100], burst_time[100];
    int count = 0;
    int end;
    int n;
    int temp[100], order[100];
    int wait_time, turnaround_time;
    printf("Enter The Number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter Arrival Time:\t");
        scanf("%d", &arrival_time[i]);
        printf("Enter Burst Time:\t");
        scanf("%d", &burst_time[i]);
        temp[i] = burst_time[i];
    }

    burst_time[9] = 9999;
    for (int time = 0; time != count; time++)
    {
        /* code */
        int smallest = 9;
        for (int i = 0; i < n; i++)
        {
            /* code */
            if (arrival_time[i] < time && burst_time[i] < burst_time[smallest] && burst_time[i] > 0)
            {
                /* code */
                smallest = i;
            }
        }

        burst_time[smallest]--;
        if (burst_time[smallest] == 0)
        {
            count++;
            end = time + 1;
            wait_time += end - arrival_time[smallest] - temp[smallest];
            turnaround_time += end - arrival_time[smallest];
            order[count - 1] = end;
        }
    }

    return 0;
}