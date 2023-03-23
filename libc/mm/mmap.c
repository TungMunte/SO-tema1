/* SPDX-License-Identifier: BSD-3-Clause */

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/* TODO: Implement mmap(). */
	off_t result = syscall(__NR_mmap, addr, length, prot, flags, fd, offset);
	if (result < 0)
	{
		errno = -result;
		result = -1;
	}

	return result;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/* TODO: Implement mremap(). */
	off_t result = syscall(__NR_mremap, old_address, old_size, new_size, flags);
	if (result < 0)
	{
		errno = -result;
		result = -1;
	}

	return result;
}

int munmap(void *addr, size_t length)
{
	/* TODO: Implement munmap(). */
	off_t result = syscall(__NR_munmap, addr, length);
	if (result < 0)
	{
		errno = -result;
		result = -1;
	}

	return result;
}
