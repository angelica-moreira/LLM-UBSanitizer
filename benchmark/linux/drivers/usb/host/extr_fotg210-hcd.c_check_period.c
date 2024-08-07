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
struct fotg210_hcd {unsigned int uframe_periodic_max; unsigned int periodic_size; } ;

/* Variables and functions */
 int periodic_usecs (struct fotg210_hcd*,unsigned int,unsigned int) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static int check_period(struct fotg210_hcd *fotg210, unsigned frame,
		unsigned uframe, unsigned period, unsigned usecs)
{
	int claimed;

	/* complete split running into next frame?
	 * given FSTN support, we could sometimes check...
	 */
	if (uframe >= 8)
		return 0;

	/* convert "usecs we need" to "max already claimed" */
	usecs = fotg210->uframe_periodic_max - usecs;

	/* we "know" 2 and 4 uframe intervals were rejected; so
	 * for period 0, check _every_ microframe in the schedule.
	 */
	if (unlikely(period == 0)) {
		do {
			for (uframe = 0; uframe < 7; uframe++) {
				claimed = periodic_usecs(fotg210, frame,
						uframe);
				if (claimed > usecs)
					return 0;
			}
		} while ((frame += 1) < fotg210->periodic_size);

	/* just check the specified uframe, at that period */
	} else {
		do {
			claimed = periodic_usecs(fotg210, frame, uframe);
			if (claimed > usecs)
				return 0;
		} while ((frame += period) < fotg210->periodic_size);
	}

	/* success! */
	return 1;
}