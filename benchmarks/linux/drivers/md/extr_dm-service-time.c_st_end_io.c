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
struct path_selector {int dummy; } ;
struct path_info {int /*<<< orphan*/  in_flight_size; } ;
struct dm_path {struct path_info* pscontext; } ;

/* Variables and functions */
 int /*<<< orphan*/  atomic_sub (size_t,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int st_end_io(struct path_selector *ps, struct dm_path *path,
		     size_t nr_bytes)
{
	struct path_info *pi = path->pscontext;

	atomic_sub(nr_bytes, &pi->in_flight_size);

	return 0;
}