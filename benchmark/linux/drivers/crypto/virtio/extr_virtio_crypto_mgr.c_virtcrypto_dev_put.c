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
struct virtio_crypto {int /*<<< orphan*/  owner; int /*<<< orphan*/  ref_count; } ;

/* Variables and functions */
 scalar_t__ atomic_sub_return (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  module_put (int /*<<< orphan*/ ) ; 

void virtcrypto_dev_put(struct virtio_crypto *vcrypto_dev)
{
	if (atomic_sub_return(1, &vcrypto_dev->ref_count) == 0)
		module_put(vcrypto_dev->owner);
}