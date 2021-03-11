#include <mpi.h>
#include <stdio.h>

int main()
{
    int id, x;

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);

    // P0 mengirim pesan x ke P1
    // P1 menerima pesan dari P0, disimpan ke x
    if (id == 0) {
        x = 6;
        MPI_Send(&x, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    }
    if (id == 1)
        MPI_Recv(&x, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, NULL);

    printf("P[%d] x: %d\n", id, x);

    MPI_Finalize();
    return 0;
}
