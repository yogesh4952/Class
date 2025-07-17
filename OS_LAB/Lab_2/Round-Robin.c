#include <stdio.h>

int main()
{
  int i, j, n, bu[10], wa[10] = {0}, tat[10] = {0}, ct[10], max;
  double awt = 0.0, att = 0.0, temp = 0.0;
  int t;

  // Input number of processes
  printf("Enter the number of processes (max 10): ");
  scanf("%d", &n);                                  
  if (n <= 0 || n > 10)
  {
    printf("Invalid number of processes. Must be between 1 and 10.\n");
    return 1;
  }

  // Input burst times
  for (i = 0; i < n; i++)
  {
    printf("Enter Burst Time for process %d: ", i + 1);
    scanf("%d", &bu[i]);
    if (bu[i] <= 0)
    {
      printf("Burst time must be positive.\n");
      return 1;
    }
    ct[i] = bu[i]; // Store original burst time
  }

  // Input time slice
  printf("Enter the size of time slice: ");
  scanf("%d", &t);
  if (t <= 0)
  {
    printf("Time slice must be positive.\n");
    return 1;
  }

  // Find maximum burst time
  max = bu[0];
  for (i = 1; i < n; i++)
  {
    if (max < bu[i])
    {
      max = bu[i];
    }
  }

  // Round Robin simulation
  int remaining = n; // Track processes with non-zero burst time
  while (remaining > 0)
  {
    for (i = 0; i < n; i++)
    {
      if (bu[i] > 0)
      {
        if (bu[i] <= t)
        {
          temp += bu[i];
          tat[i] = temp; // Turnaround time
          bu[i] = 0;
          remaining--;
        }
        else
        {
          bu[i] -= t;
          temp += t;
        }
      }
    }
  }

  // Calculate waiting times and averages
  for (i = 0; i < n; i++)
  {
    wa[i] = tat[i] - ct[i]; // Waiting time = Turnaround time - Burst time
    att += tat[i];
    awt += wa[i];
  }

  // Output results
  printf("\nAverage Turnaround Time: %.2f\n", att / n);
  printf("Average Waiting Time: %.2f\n", awt / n);
  printf("\n%-10s%-15s%-15s%-15s\n", "Process", "Burst Time", "Waiting Time", "Turnaround Time");
  for (i = 0; i < n; i++)
  {
    printf("%-10d%-15d%-15d%-15d\n", i + 1, ct[i], wa[i], tat[i]);
  }

  return 0;
}