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
struct mvebu_sei {int /*<<< orphan*/  cp_msi_lock; int /*<<< orphan*/  cp_msi_bitmap; } ;

/* Variables and functions */
 int /*<<< orphan*/  clear_bit (unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void mvebu_sei_cp_release_irq(struct mvebu_sei *sei, unsigned long hwirq)
{
	mutex_lock(&sei->cp_msi_lock);
	clear_bit(hwirq, sei->cp_msi_bitmap);
	mutex_unlock(&sei->cp_msi_lock);
}