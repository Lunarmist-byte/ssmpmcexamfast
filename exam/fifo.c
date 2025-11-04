#include <stdio.h>

void main() {
    int rs[25], m[10], n, f, pf = 0, k = 0, found;

    printf("Enter the length of reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &rs[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (int i = 0; i < f; i++)
        m[i] = -1;

    printf("\nFIFO Page Replacement\n");

    for (int i = 0; i < n; i++) {
        found = 0;

        // check if page already in frame (HIT)
        for (int j = 0; j < f; j++) {
            if (m[j] == rs[i]) {
                found = 1;
                break;
            }
        }

        // Page Fault
        if (found == 0) {
            m[k] = rs[i];
            k = (k + 1) % f;
            pf++;
        }

        // print current state
        for (int j = 0; j < f; j++) {
            if (m[j] != -1)
                printf("%d\t", m[j]);
            else
                printf("-\t");
        }

        // indicate HIT or PAGE FAULT
        if (found == 1)
            printf("HIT");
        else
            printf("PF--%d", pf);

        printf("\n"); // ✅ newline for every reference
    }

    printf("\nTotal number of page faults: %d\n", pf);
}
