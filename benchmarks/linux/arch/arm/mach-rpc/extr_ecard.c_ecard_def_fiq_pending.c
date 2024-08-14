#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int fiqmask; int /*<<< orphan*/  fiqaddr; } ;
typedef  TYPE_1__ ecard_t ;

/* Variables and functions */
 int readb (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ecard_def_fiq_pending(ecard_t *ec)
{
	return !ec->fiqmask || readb(ec->fiqaddr) & ec->fiqmask;
}