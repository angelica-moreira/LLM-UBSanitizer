#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct rpmsg_device {int dummy; } ;
struct btqcomsmd {TYPE_2__* hdev; } ;
struct TYPE_3__ {int byte_rx; } ;
struct TYPE_4__ {TYPE_1__ stat; } ;

/* Variables and functions */
 int /*<<< orphan*/  HCI_ACLDATA_PKT ; 
 int btqcomsmd_recv (TYPE_2__*,int /*<<< orphan*/ ,void*,int) ; 

__attribute__((used)) static int btqcomsmd_acl_callback(struct rpmsg_device *rpdev, void *data,
				  int count, void *priv, u32 addr)
{
	struct btqcomsmd *btq = priv;

	btq->hdev->stat.byte_rx += count;
	return btqcomsmd_recv(btq->hdev, HCI_ACLDATA_PKT, data, count);
}