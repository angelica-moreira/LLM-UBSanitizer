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
struct ata_taskfile {int /*<<< orphan*/  command; } ;
struct TYPE_2__ {int /*<<< orphan*/  command_addr; } ;
struct ata_port {TYPE_1__ ioaddr; int /*<<< orphan*/  host; } ;

/* Variables and functions */
 int /*<<< orphan*/  ata_outb (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ata_sff_pause (struct ata_port*) ; 

__attribute__((used)) static void pata_s3c_exec_command(struct ata_port *ap,
				const struct ata_taskfile *tf)
{
	ata_outb(ap->host, tf->command, ap->ioaddr.command_addr);
	ata_sff_pause(ap);
}