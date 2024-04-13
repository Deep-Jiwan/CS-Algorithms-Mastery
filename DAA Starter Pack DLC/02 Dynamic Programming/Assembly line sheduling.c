#include <stdio.h>

#define NUM_STATIONS 5 // Number of stations


int min(int a, int b) {
    return (a < b) ? a : b;
}


int assemblyLineScheduling(int a[][NUM_STATIONS], int t[][NUM_STATIONS], int *e, int *x) {
    int T1[NUM_STATIONS], T2[NUM_STATIONS]; // time taken
    int line1Route[NUM_STATIONS], line2Route[NUM_STATIONS]; // route
    int i;

    // initializtion
    T1[0] = e[0] + a[0][0];
    T2[0] = e[1] + a[1][0];


    for (i = 1; i < NUM_STATIONS; ++i) {

        // Calculate times for assembly line 1
        if (T1[i - 1] < T2[i - 1] + t[1][i]) {
            T1[i] = a[0][i] + T1[i - 1];
            line1Route[i] = 1; // Station on assembly line 1
        } else {
            T1[i] = a[0][i] + T2[i - 1] + t[1][i];
            line1Route[i] = 2; // Station on assembly line 2
        }

        // Calculate times for assembly line 2
        if (T2[i - 1] < T1[i - 1] + t[0][i]) {
            T2[i] = a[1][i] + T2[i - 1];
            line2Route[i] = 2; // Station on assembly line 2
        } else {
            T2[i] = a[1][i] + T1[i - 1] + t[0][i];
            line2Route[i] = 1; // Station on assembly line 1
        }
    }

    // Add exit times, return min element
    int minTime = min(T1[NUM_STATIONS - 1] + x[0], T2[NUM_STATIONS - 1] + x[1]);

    // route table
    printf("Route Table:\n");
    printf("Station\tLine\n");
    printf("-------\t----\n");
    int station = 1;
    printf("  Entry\t  %d\n", (minTime == T1[NUM_STATIONS - 1] + x[0]) ? 1 : 2);
    for (i = NUM_STATIONS - 1; i > 0; --i) {
        
        printf("    %d\t  %d\n", (station), (minTime == T1[NUM_STATIONS - 1] + x[0]) ? line1Route[i] : line2Route[i]);
        station++;
    }
    printf("  Exit\t  %d\n", (minTime == T1[NUM_STATIONS - 1] + x[0]) ? 1 : 2);

    return minTime;
}

int main() {
    int a[2][NUM_STATIONS] = {{8,10,4,5,9}, {9,6,7,5,6}}; 
    int t[2][NUM_STATIONS] = {{0, 2,3,1,3}, {0, 2,1,2,2}}; 
    int e[2] = {3,5}; // entry
    int x[2] = {2,1}; // exit

    printf("Minimum time to complete production: %d\n", assemblyLineScheduling(a, t, e, x));
    printf("22BCE3789 - Deep Mukesh Jiwan 2024");
    return 0;
}
