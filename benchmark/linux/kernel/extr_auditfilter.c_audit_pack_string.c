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

/* Variables and functions */
 int /*<<< orphan*/  memcpy (void*,char const*,size_t) ; 
 size_t strlen (char const*) ; 

__attribute__((used)) static inline size_t audit_pack_string(void **bufp, const char *str)
{
	size_t len = strlen(str);

	memcpy(*bufp, str, len);
	*bufp += len;

	return len;
}