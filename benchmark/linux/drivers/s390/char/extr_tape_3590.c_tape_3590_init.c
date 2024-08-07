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
 int /*<<< orphan*/  DBF_EVENT (int,char*) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  TAPE_DBF_AREA ; 
 int /*<<< orphan*/  alloc_workqueue (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int ccw_driver_register (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  debug_register (char*,int,int,int) ; 
 int /*<<< orphan*/  debug_register_view (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  debug_set_level (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  debug_sprintf_view ; 
 int /*<<< orphan*/  destroy_workqueue (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tape_3590_driver ; 
 int /*<<< orphan*/  tape_3590_wq ; 

__attribute__((used)) static int
tape_3590_init(void)
{
	int rc;

	TAPE_DBF_AREA = debug_register("tape_3590", 2, 2, 4 * sizeof(long));
	debug_register_view(TAPE_DBF_AREA, &debug_sprintf_view);
#ifdef DBF_LIKE_HELL
	debug_set_level(TAPE_DBF_AREA, 6);
#endif

	DBF_EVENT(3, "3590 init\n");

	tape_3590_wq = alloc_workqueue("tape_3590", 0, 0);
	if (!tape_3590_wq)
		return -ENOMEM;

	/* Register driver for 3590 tapes. */
	rc = ccw_driver_register(&tape_3590_driver);
	if (rc) {
		destroy_workqueue(tape_3590_wq);
		DBF_EVENT(3, "3590 init failed\n");
	} else
		DBF_EVENT(3, "3590 registered\n");
	return rc;
}