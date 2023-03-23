/* SPDX-License-Identifier: BSD-3-Clause */

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	/* TODO: Implement lseek(). */
	off_t result = syscall(__NR_close, fd);
	if (result < 0)
	{
		errno = -result;
		result = -1;
	}

	return result;
}
