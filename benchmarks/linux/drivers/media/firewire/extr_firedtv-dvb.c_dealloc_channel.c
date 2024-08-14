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
struct firedtv {int /*<<< orphan*/  channel_active; } ;

/* Variables and functions */
 int /*<<< orphan*/  __clear_bit (int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void dealloc_channel(struct firedtv *fdtv, int i)
{
	__clear_bit(i, &fdtv->channel_active);
}