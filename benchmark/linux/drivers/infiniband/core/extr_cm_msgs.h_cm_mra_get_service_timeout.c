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
struct cm_mra_msg {int offset9; } ;

/* Variables and functions */

__attribute__((used)) static inline u8 cm_mra_get_service_timeout(struct cm_mra_msg *mra_msg)
{
	return (u8) (mra_msg->offset9 >> 3);
}