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
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 scalar_t__ fprintf (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  perror (char*) ; 
 int /*<<< orphan*/  rewind (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void __set(FILE *stream, int value, char *err_msg)
{
	rewind(stream);
	if (fprintf(stream, "%d", value) < 0)
		perror(err_msg);
}