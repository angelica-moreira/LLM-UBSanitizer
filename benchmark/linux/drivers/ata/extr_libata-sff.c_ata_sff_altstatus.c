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
typedef  int /*<<< orphan*/  u8 ;
struct TYPE_4__ {int /*<<< orphan*/  altstatus_addr; } ;
struct ata_port {TYPE_2__ ioaddr; TYPE_1__* ops; } ;
struct TYPE_3__ {int /*<<< orphan*/  (* sff_check_altstatus ) (struct ata_port*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  ioread8 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (struct ata_port*) ; 

__attribute__((used)) static u8 ata_sff_altstatus(struct ata_port *ap)
{
	if (ap->ops->sff_check_altstatus)
		return ap->ops->sff_check_altstatus(ap);

	return ioread8(ap->ioaddr.altstatus_addr);
}