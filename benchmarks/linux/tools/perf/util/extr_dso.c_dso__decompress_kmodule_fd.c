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
struct dso {int dummy; } ;

/* Variables and functions */
 int decompress_kmodule (struct dso*,char const*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

int dso__decompress_kmodule_fd(struct dso *dso, const char *name)
{
	return decompress_kmodule(dso, name, NULL, 0);
}