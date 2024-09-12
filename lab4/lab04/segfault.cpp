// There are two errors for you to discover with GDB
// You won't turn this file in
// Remove the first error to discover the second

int main(int argc, char* argv[]) {
  int *i = new int;
  delete i;
  delete i;

  double *d = nullptr;
  *d += 3.14;

  return 0;
}
