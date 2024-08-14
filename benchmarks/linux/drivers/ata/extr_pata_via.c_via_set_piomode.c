#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct via_isa_bridge {int flags; int /*<<< orphan*/  udma_mask; } ;
struct ata_port {TYPE_1__* host; } ;
struct ata_device {int /*<<< orphan*/  pio_mode; } ;
struct TYPE_2__ {struct via_isa_bridge* private_data; } ;

/* Variables and functions */
 int VIA_BAD_AST ; 
 int /*<<< orphan*/  via_do_set_mode (struct ata_port*,struct ata_device*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void via_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
	const struct via_isa_bridge *config = ap->host->private_data;
	int set_ast = (config->flags & VIA_BAD_AST) ? 0 : 1;

	via_do_set_mode(ap, adev, adev->pio_mode, set_ast, config->udma_mask);
}