#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv){

	MPI_Init(&argc, &argv);

	int rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int len;
	char processor[256];
	MPI_Get_processor_name(processor, &len);

	printf("%s-%d: hello world!!\n", processor, rank);

	MPI_Finalize();

	return 0;
}
