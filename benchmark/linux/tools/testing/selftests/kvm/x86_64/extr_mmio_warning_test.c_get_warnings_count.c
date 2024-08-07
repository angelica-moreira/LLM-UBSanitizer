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
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  fscanf (int /*<<< orphan*/ *,char*,int*) ; 
 int /*<<< orphan*/ * popen (char*,char*) ; 

int get_warnings_count(void)
{
	int warnings;
	FILE *f;

	f = popen("dmesg | grep \"WARNING:\" | wc -l", "r");
	fscanf(f, "%d", &warnings);
	fclose(f);

	return warnings;
}