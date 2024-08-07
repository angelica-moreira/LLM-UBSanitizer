#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u64 ;
struct ntb_dev {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  db_valid_mask; } ;

/* Variables and functions */
 TYPE_1__* ntb_ndev (struct ntb_dev*) ; 

u64 intel_ntb_db_valid_mask(struct ntb_dev *ntb)
{
	return ntb_ndev(ntb)->db_valid_mask;
}