/* SPDX-License-Identifier: BSD-3-Clause */

#include <time.h>

int main(void)
{
	struct timespec wait = {10, 0};

	nanosleep(&wait, NULL);

	return 0;
}
