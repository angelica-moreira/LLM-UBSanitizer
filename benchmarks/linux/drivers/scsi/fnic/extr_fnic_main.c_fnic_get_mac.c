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
typedef  int /*<<< orphan*/  u8 ;
struct fnic {int /*<<< orphan*/ * data_src_addr; } ;
struct fc_lport {int dummy; } ;

/* Variables and functions */
 struct fnic* lport_priv (struct fc_lport*) ; 

__attribute__((used)) static u8 *fnic_get_mac(struct fc_lport *lport)
{
	struct fnic *fnic = lport_priv(lport);

	return fnic->data_src_addr;
}