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
struct adapter {int dummy; } ;

/* Variables and functions */
 int t4_wr_mbox_meat_timeout (struct adapter*,int,void const*,int,void*,int,int) ; 

__attribute__((used)) static inline int t4_wr_mbox_timeout(struct adapter *adap, int mbox,
				     const void *cmd, int size, void *rpl,
				     int timeout)
{
	return t4_wr_mbox_meat_timeout(adap, mbox, cmd, size, rpl, true,
				       timeout);
}