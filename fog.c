#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FOG_SPEED_GHZ 2.5       // processing speed of local fog node
#define CLOUD_SPEED_GHZ 15.0    // processing speed of distant cloud
#define NETWORK_BANDWIDTH 2.0   // Mbps (fog to cloud)
#define PROPAGATION_DELAY 0.05  // 50ms base round-trip to cloud
#define MAX_FOG_MEM_KB 2048     // 2MB simulated memory limit for fog

//  task structure 
typedef struct Task {
    int id;
    float dataSize;      // in KB
    float cpuCycles;     // in GigaCycles
    float arrivalTime;   // simulation clock time
    struct Task* next;   // pointer for linked list queue
} Task;


//  fog node state 
float current_fog_mem_usage = 0;

// function to calculate latency
float calculate_latency(Task* t, int is_cloud) {
    if (is_cloud) {
        // latency = transmission time + propagation + execution Time
        float transmission = (t->dataSize / 1024.0) / (NETWORK_BANDWIDTH / 8.0);
        float execution = t->cpuCycles / CLOUD_SPEED_GHZ;
        return transmission + PROPAGATION_DELAY + execution;
    } else {
        // latency = execution time only (minimal network delay)
        return t->cpuCycles / FOG_SPEED_GHZ;
    }
}

// function to create a new task
Task* create_task(int id, float clock) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    if (newTask == NULL) return NULL;

    newTask->id = id;
    newTask->dataSize = (rand() % 1000) + 100;   // 100-1100 KB
    newTask->cpuCycles = (rand() % 5) + 0.5;     //0.5-5.5 GigaCycles
    newTask->arrivalTime = clock;
    newTask->next = NULL;
    return newTask;
}

int main() {
    FILE *fp = fopen("results.csv", "w");
    srand(time(NULL));
    Task *head = NULL, *tail = NULL;
    int total_tasks = 10;
    
    printf("Fog Computing Offloading Simulator \n");
    printf("Fog Limit: %d KB | Cloud Bandwidth: %.1f Mbps\n\n", MAX_FOG_MEM_KB, NETWORK_BANDWIDTH);

    for (int i = 1; i <= total_tasks; i++) {
        Task* t = create_task(i, (float)i * 0.2); //tasks arrive every 0.2s

        printf("Task [%d]: Size=%.2fKB, Complexity=%.2fGC\n", t->id, t->dataSize, t->cpuCycles);

        float t_local = calculate_latency(t, 0);
        float t_cloud = calculate_latency(t, 1);

        // decision logic 
        // 1. check if fog has memory
        // 2. check if local is faster
        if (current_fog_mem_usage + t->dataSize <= MAX_FOG_MEM_KB && t_local < t_cloud) {
            current_fog_mem_usage += t->dataSize;
            printf(" -> DECISION: PROCESS AT FOG\n");
            printf(" -> LATENCY: %.4fs | FOG MEMORY: %.2f/%d KB\n", t_local, current_fog_mem_usage, MAX_FOG_MEM_KB);
            
            // simulation of finishing task: free memory immediately for next task
            current_fog_mem_usage -= t->dataSize; 
        } else {
            printf(" -> DECISION: OFFLOAD TO CLOUD\n");
            if (current_fog_mem_usage + t->dataSize > MAX_FOG_MEM_KB)
                printf(" -> REASON: FOG MEMORY CONGESTION\n");
            else
                printf(" -> REASON: CLOUD IS FASTER (High Comp/Low Data)\n");
            
            printf(" -> LATENCY: %.4fs\n", t_cloud);
        }
        fprintf(fp, "%d,%.2f,%.4f,%.4f\n", t->id, t->cpuCycles, t_local, t_cloud);
        printf("\n");
        free(t); 
    }
    fclose(fp);
    return 0;
}