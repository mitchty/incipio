#include <stdio.h>
#include "incipio.yucc"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    puts("Nothing to do! Re-run with -h or --help for more options.");
    return 1;
  } else {
    yuck_t argp[1];
    yuck_parse(argp, argc, argv);
    yuck_free(argp);
  }
}
