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
typedef  int /*<<< orphan*/  s32 ;

/* Variables and functions */
 int /*<<< orphan*/  dprintk (char*,char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void altera_export_int(char *key, s32 value)
{
	dprintk("Export: key = \"%s\", value = %d\n", key, value);
}