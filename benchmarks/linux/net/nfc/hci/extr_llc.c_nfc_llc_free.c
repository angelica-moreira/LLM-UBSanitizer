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
struct nfc_llc {TYPE_1__* ops; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* deinit ) (struct nfc_llc*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct nfc_llc*) ; 
 int /*<<< orphan*/  stub1 (struct nfc_llc*) ; 

void nfc_llc_free(struct nfc_llc *llc)
{
	llc->ops->deinit(llc);
	kfree(llc);
}