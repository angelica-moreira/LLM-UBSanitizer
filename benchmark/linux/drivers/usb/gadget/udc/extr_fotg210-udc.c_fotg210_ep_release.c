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
struct fotg210_ep {scalar_t__ epnum; int /*<<< orphan*/  fotg210; scalar_t__ wedged; scalar_t__ stall; } ;

/* Variables and functions */
 int /*<<< orphan*/  fotg210_reset_tseq (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static int fotg210_ep_release(struct fotg210_ep *ep)
{
	if (!ep->epnum)
		return 0;
	ep->epnum = 0;
	ep->stall = 0;
	ep->wedged = 0;

	fotg210_reset_tseq(ep->fotg210, ep->epnum);

	return 0;
}