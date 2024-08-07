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
struct cqhci_host {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CQHCI_VER ; 
 unsigned int CQHCI_VER_MAJOR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cqhci_readl (struct cqhci_host*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static unsigned int cqhci_ver_major(struct cqhci_host *cq_host)
{
	return CQHCI_VER_MAJOR(cqhci_readl(cq_host, CQHCI_VER));
}