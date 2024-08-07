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
struct amdgpu_mn {int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  up_write (int /*<<< orphan*/ *) ; 

void amdgpu_mn_unlock(struct amdgpu_mn *mn)
{
	if (mn)
		up_write(&mn->lock);
}