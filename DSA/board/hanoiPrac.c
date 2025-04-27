#include <stdio.h>

void hanoi(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    hanoi(n - 1, from, aux, to);
    printf("Disk %d move from %c to % c\n", n, from, to);
    hanoi(n - 1, aux, to, from);
}
int main()
{
    hanoi(2, 'A', 'B', 'C');
}