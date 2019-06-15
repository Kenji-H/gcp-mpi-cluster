#include <iostream>
#include <mpi.h>

using namespace std;

int rnk() {
  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  return rank;
}

string pcr() {
  int len;
  char processor[256];
  MPI_Get_processor_name(processor, &len);
  return string(processor);
}

int main(int argc, char **argv) {
  MPI_Init(&argc, &argv);
  if (!rnk())
    cout << "Hello, master from " << pcr() << endl;
  else
    cout << "Hello, slave from " << pcr() << endl;
  MPI_Finalize();
  return 0;
}
