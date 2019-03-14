#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h>

struct cgid_file_handle
{
  //struct file_handle handle;
  unsigned int handle_bytes;
  int handle_type;
  uint64_t cgid;
};

int main(int argc, char **argv) {
  struct cgid_file_handle *h;
  int mount_id;
  int err;

  if (argc != 2)
    return 1;

  h = malloc(sizeof(struct cgid_file_handle));
  if (!h)
    return 1;

  h->handle_bytes = 8;
  err = name_to_handle_at(AT_FDCWD, argv[1], (struct file_handle *)h, &mount_id, 0);
  if (err != 0)
    return 1;

  if (h->handle_bytes != 8)
    return 1;

  printf("%lu\n", h->cgid);

  return 0;
}

