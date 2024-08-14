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
struct vhci_data {int /*<<< orphan*/  open_mutex; } ;
typedef  int /*<<< orphan*/  __u8 ;

/* Variables and functions */
 int __vhci_create_device (struct vhci_data*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int vhci_create_device(struct vhci_data *data, __u8 opcode)
{
	int err;

	mutex_lock(&data->open_mutex);
	err = __vhci_create_device(data, opcode);
	mutex_unlock(&data->open_mutex);

	return err;
}