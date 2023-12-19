#include <stdio.h>

int main()
{
    int arrival_time[10], burst_time[10], temp[10];
    int order[10]; // Array to store the order of processes
    int i, smallest, count = 0, time, limit;
    double wait_time = 0, turnaround_time = 0, end;
    float average_waiting_time, average_turnaround_time;

    printf("\nEnter the Total Number of Processes:\t");
    scanf("%d", &limit);
    printf("\nEnter Details of %d Processes\n", limit);

    for (i = 0; i < limit; i++)
    {
        printf("\nEnter Arrival Time:\t");
        scanf("%d", &arrival_time[i]);
        printf("Enter Burst Time:\t");
        scanf("%d", &burst_time[i]);
        temp[i] = burst_time[i];
    }

    burst_time[9] = 9999;

    for (time = 0; count != limit; time++)
    {
        smallest = 9;
        for (i = 0; i < limit; i++)
        {
            if (arrival_time[i] <= time && burst_time[i] < burst_time[smallest] && burst_time[i] > 0)
            {
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
            order[count - 1] = smallest; // Store the order of the completed process
        }
    }

    average_waiting_time = wait_time / limit;
    average_turnaround_time = turnaround_time / limit;

    printf("\n\nAverage Waiting Time:\t%lf\n", average_waiting_time);
    printf("Average Turnaround Time:%lf\n", average_turnaround_time);

    // Print the order of processes
    printf("\nOrder of Processes: ");
    for (i = 0; i < limit; i++)
    {
        printf("P%d ", order[i] + 1); // Adding 1 to match the process numbering
    }

    return 0;
}
