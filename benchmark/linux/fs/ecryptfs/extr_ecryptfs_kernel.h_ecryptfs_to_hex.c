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
 char* bin2hex (char*,char*,size_t) ; 

__attribute__((used)) static inline void
ecryptfs_to_hex(char *dst, char *src, size_t src_size)
{
	char *end = bin2hex(dst, src, src_size);
	*end = '\0';
}