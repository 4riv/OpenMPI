#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int size, id;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);

    printf("Hello from process %d-of-%d\n", id, size);

    MPI_Finalize();
    return 0;
}
