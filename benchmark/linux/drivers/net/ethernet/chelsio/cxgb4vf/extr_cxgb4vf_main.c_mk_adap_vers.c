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
struct TYPE_2__ {int /*<<< orphan*/  chip; } ;
struct adapter {TYPE_1__ params; } ;

/* Variables and functions */
 int CHELSIO_CHIP_VERSION (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline unsigned int mk_adap_vers(const struct adapter *adapter)
{
	/*
	 * Chip version 4, revision 0x3f (cxgb4vf).
	 */
	return CHELSIO_CHIP_VERSION(adapter->params.chip) | (0x3f << 10);
}