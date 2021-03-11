#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#define ROOT 0
#define N    20

int main()
{
    int ID, P, i;
    int *data, *ldata;

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &ID);
    MPI_Comm_size(MPI_COMM_WORLD, &P);

    if (ID == ROOT) {
        data = malloc(N * sizeof(int));
        for (i = 0; i < N; i++)
            data[i] = rand()%10;
    }

    local_data = malloc(N/P * sizeof(int));
    MPI_Scatter(data, N/P, MPI_INT, ldata, N/P, MPI_INT, ROOT, MPI_COMM_WORLD);

    printf("P[%d] local data: ", ID);
    for (i = 0; i < N/P; i++)
        printf("%d ", local_data[i]);
    printf("\n");
    fflush(stdout);

    MPI_Finalize();
    return 0;
}
