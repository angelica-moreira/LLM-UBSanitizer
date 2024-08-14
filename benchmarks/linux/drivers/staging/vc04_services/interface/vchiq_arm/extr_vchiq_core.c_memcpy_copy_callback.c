#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  size_t ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  memcpy (void*,void*,size_t) ; 

__attribute__((used)) static ssize_t
memcpy_copy_callback(
	void *context, void *dest,
	size_t offset, size_t maxsize)
{
	memcpy(dest + offset, context + offset, maxsize);
	return maxsize;
}