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
typedef  int /*<<< orphan*/  u16 ;
struct d0_opal_v200 {int /*<<< orphan*/  baseComID; } ;

/* Variables and functions */
 int /*<<< orphan*/  be16_to_cpu (int /*<<< orphan*/ ) ; 

__attribute__((used)) static u16 get_comid_v200(const void *data)
{
	const struct d0_opal_v200 *v200 = data;

	return be16_to_cpu(v200->baseComID);
}