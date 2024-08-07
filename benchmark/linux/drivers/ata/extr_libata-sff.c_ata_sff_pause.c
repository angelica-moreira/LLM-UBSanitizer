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
struct ata_port {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ata_sff_sync (struct ata_port*) ; 
 int /*<<< orphan*/  ndelay (int) ; 

void ata_sff_pause(struct ata_port *ap)
{
	ata_sff_sync(ap);
	ndelay(400);
}