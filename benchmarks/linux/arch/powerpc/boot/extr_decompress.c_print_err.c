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
 scalar_t__ decompressed_bytes ; 
 scalar_t__ limit ; 
 int /*<<< orphan*/  printf (char*,char*) ; 

__attribute__((used)) static void print_err(char *s)
{
	/* suppress the "error" when we terminate the decompressor */
	if (decompressed_bytes >= limit)
		return;

	printf("Decompression error: '%s'\n\r", s);
}