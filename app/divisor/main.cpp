#include <iostream>
#include <mpi.h>

using namespace std;

int rnk() {
  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  return rank;
}

int nums_of_process() {
  int n;
  MPI_Comm_size(MPI_COMM_WORLD, &n);
  return n;
}

void send_int(int x, int dest) {
  MPI_Send(&x, 1, MPI_INT, dest, 0, MPI_COMM_WORLD);
}

int receive_int(int src) {
  int x;
  MPI_Recv(&x, 1, MPI_INT, src, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  return x;
}

int main(int argc, char **argv) {
  MPI_Init(&argc, &argv);

  const long long n = 1LL<<60;

  int ret = 0;
  for (long long d = 1 + rnk(); d * d <= n; d += nums_of_process()) {
    if (n % d == 0) {
      ++ret;
      if (n / d != d)
        ++ret;
    }
  }

  if (rnk() > 0) {
    send_int(ret, 0);
  } else {
    for (int i = 1; i < nums_of_process(); i++) {
      ret += receive_int(i);
    }
    cout << ret << endl;
  }

  MPI_Finalize();
  return 0;
}
