/* Program to simulate optimal page replacement */
#include<stdio.h>

int fr[10], n, m;

void display() {
    int i;
    for(i = 0; i < m; i++) {
        if(fr[i] != -1)
            printf("%d\t", fr[i]);
        else
            printf("-1\t");
    }
    printf("\n");
}

int main() {
    int page[50], lg[10];
    int i, j, k, index, max, found, flag1, flag2, pf = 0;
    float pr;

    printf("Enter length of the reference string: ");
    scanf("%d", &n);
    printf("Enter the reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &page[i]);
    printf("Enter no of frames: ");
    scanf("%d", &m);

    for(i = 0; i < m; i++)
        fr[i] = -1;

    for(j = 0; j < n; j++) {
        flag1 = flag2 = 0;

        // Check if page is already in frame
        for(i = 0; i < m; i++) {
            if(fr[i] == page[j]) {
                flag1 = flag2 = 1;
                break;
            }
        }

        // If not in frame, check for empty slot
        if(flag1 == 0) {
            for(i = 0; i < m; i++) {
                if(fr[i] == -1) {
                    fr[i] = page[j];
                    flag2 = 1;
                    pf++;
                    break;
                }
            }
        }

        // If no empty slot, apply optimal replacement
        if(flag2 == 0) {
            for(i = 0; i < m; i++)
                lg[i] = 0;

            for(i = 0; i < m; i++) {
                for(k = j + 1; k < n; k++) {
                    if(fr[i] == page[k]) {
                        lg[i] = k - j;
                        break;
                    }
                }
            }

            found = 0;
            for(i = 0; i < m; i++) {
                if(lg[i] == 0) {
                    index = i;
                    found = 1;
                    break;
                }
            }

            if(found == 0) {
                max = lg[0];
                index = 0;
                for(i = 1; i < m; i++) {
                    if(lg[i] > max) {
                        max = lg[i];
                        index = i;
                    }
                }
            }

            fr[index] = page[j];
            pf++;
        }

        display();
    }

    printf("Number of page faults: %d\n", pf);
    pr = (float)pf / n * 100;
    printf("Page fault rate = %f\n", pr);

    return 0;
}