#include <stdio.h>

int fr[3];

void display() {
    for (int i = 0; i < 3; i++)
        printf(" %d", fr[i]);
    printf("\n");
}

int findLRU(int time[], int n) {
    int min = time[0], pos = 0;
    for (int i = 1; i < n; ++i) {
        if (time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int p[12] = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2};
    int time[3];
    int pf = 0, count = 0;
    int frsize = 3;

    for (int i = 0; i < frsize; i++)
        fr[i] = -1;

    for (int j = 0; j < 12; j++) {
        int flag = 0;
        for (int i = 0; i < frsize; i++) {
            if (fr[i] == p[j]) {
                count++;
                time[i] = count;
                flag = 1;
                break;
            }
        }

        if (!flag) {
            int empty = -1;
            for (int i = 0; i < frsize; i++) {
                if (fr[i] == -1) {
                    empty = i;
                    break;
                }
            }

            if (empty != -1) {
                fr[empty] = p[j];
                count++;
                time[empty] = count;
                pf++;
            } else {
                int pos = findLRU(time, frsize);
                fr[pos] = p[j];
                count++;
                time[pos] = count;
                pf++;
            }
        }

        display();
    }

    printf("No of page faults: %d\n", pf);
    return 0;
}