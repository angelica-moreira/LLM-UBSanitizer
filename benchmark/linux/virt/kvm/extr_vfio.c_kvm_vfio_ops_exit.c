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

/* Variables and functions */
 int /*<<< orphan*/  KVM_DEV_TYPE_VFIO ; 
 int /*<<< orphan*/  kvm_unregister_device_ops (int /*<<< orphan*/ ) ; 

void kvm_vfio_ops_exit(void)
{
	kvm_unregister_device_ops(KVM_DEV_TYPE_VFIO);
}