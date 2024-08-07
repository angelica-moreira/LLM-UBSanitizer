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
struct ata_ering {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ata_ering_clear_cb ; 
 int /*<<< orphan*/  ata_ering_map (struct ata_ering*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void ata_ering_clear(struct ata_ering *ering)
{
	ata_ering_map(ering, ata_ering_clear_cb, NULL);
}