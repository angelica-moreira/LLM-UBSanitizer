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
struct camif_dev {scalar_t__ stream_count; int /*<<< orphan*/  slock; } ;

/* Variables and functions */
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static bool camif_is_streaming(struct camif_dev *camif)
{
	unsigned long flags;
	bool status;

	spin_lock_irqsave(&camif->slock, flags);
	status = camif->stream_count > 0;
	spin_unlock_irqrestore(&camif->slock, flags);

	return status;
}