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
struct ipac_hw {int /*<<< orphan*/  isac; } ;

/* Variables and functions */
 int /*<<< orphan*/  isac_release (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
free_ipac(struct ipac_hw *ipac)
{
	isac_release(&ipac->isac);
}