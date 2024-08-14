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
struct jit_buf_desc {int /*<<< orphan*/ * in; } ;

/* Variables and functions */
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  funlockfile (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
jit_close(struct jit_buf_desc *jd)
{
	if (!(jd && jd->in))
		return;
	funlockfile(jd->in);
	fclose(jd->in);
	jd->in = NULL;
}