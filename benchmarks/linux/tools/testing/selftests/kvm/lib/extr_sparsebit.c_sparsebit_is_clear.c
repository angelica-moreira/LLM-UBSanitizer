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
struct sparsebit {int dummy; } ;
typedef  int /*<<< orphan*/  sparsebit_idx_t ;

/* Variables and functions */
 int /*<<< orphan*/  sparsebit_is_set (struct sparsebit*,int /*<<< orphan*/ ) ; 

bool sparsebit_is_clear(struct sparsebit *s,
	sparsebit_idx_t idx)
{
	return !sparsebit_is_set(s, idx);
}