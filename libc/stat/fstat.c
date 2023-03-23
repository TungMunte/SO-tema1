/* SPDX-License-Identifier: BSD-3-Clause */

#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <internal/syscall.h>
#include <stdlib.h>
#include <string.h>

int fstat(int fd, struct stat *st)
{
	/* TODO: Implement lseek(). */
	struct stat *s = malloc(sizeof(struct stat));
	int result = syscall(__NR_fstat, fd, s);
	if (result < 0)
	{
		errno = -result;
		result = -1;
	}
	else
	{
		/* Copy the stat data to the output buffer */
		memcpy(st, s, sizeof(struct stat));
	}

	return result;
}
