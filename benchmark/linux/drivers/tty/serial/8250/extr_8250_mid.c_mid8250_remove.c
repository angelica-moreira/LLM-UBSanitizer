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
struct pci_dev {int dummy; } ;
struct mid8250 {TYPE_1__* board; int /*<<< orphan*/  line; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* exit ) (struct mid8250*) ;} ;

/* Variables and functions */
 struct mid8250* pci_get_drvdata (struct pci_dev*) ; 
 int /*<<< orphan*/  serial8250_unregister_port (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (struct mid8250*) ; 

__attribute__((used)) static void mid8250_remove(struct pci_dev *pdev)
{
	struct mid8250 *mid = pci_get_drvdata(pdev);

	serial8250_unregister_port(mid->line);

	if (mid->board->exit)
		mid->board->exit(mid);
}