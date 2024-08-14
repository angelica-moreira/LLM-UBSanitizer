#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct typec_altmode {TYPE_2__* ops; } ;
struct TYPE_6__ {TYPE_1__* partner; } ;
struct TYPE_5__ {int /*<<< orphan*/  (* attention ) (struct typec_altmode*,int /*<<< orphan*/ ) ;} ;
struct TYPE_4__ {struct typec_altmode adev; } ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (struct typec_altmode*,int /*<<< orphan*/ ) ; 
 TYPE_3__* to_altmode (struct typec_altmode*) ; 

void typec_altmode_attention(struct typec_altmode *adev, u32 vdo)
{
	struct typec_altmode *pdev = &to_altmode(adev)->partner->adev;

	if (pdev->ops && pdev->ops->attention)
		pdev->ops->attention(pdev, vdo);
}