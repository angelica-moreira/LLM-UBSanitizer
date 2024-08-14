#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct firmware {int dummy; } ;
struct dvb_frontend {TYPE_1__* dvb; } ;
struct TYPE_8__ {TYPE_3__* dev; } ;
struct budget_ci {TYPE_4__ budget; } ;
struct TYPE_7__ {TYPE_2__* pci; } ;
struct TYPE_6__ {int /*<<< orphan*/  dev; } ;
struct TYPE_5__ {scalar_t__ priv; } ;

/* Variables and functions */
 int request_firmware (struct firmware const**,char*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int philips_tdm1316l_request_firmware(struct dvb_frontend *fe,
					     const struct firmware **fw, char *name)
{
	struct budget_ci *budget_ci = (struct budget_ci *) fe->dvb->priv;

	return request_firmware(fw, name, &budget_ci->budget.dev->pci->dev);
}