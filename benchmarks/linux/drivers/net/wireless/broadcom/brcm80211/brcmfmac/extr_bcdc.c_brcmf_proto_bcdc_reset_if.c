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
struct brcmf_if {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  brcmf_fws_reset_interface (struct brcmf_if*) ; 

__attribute__((used)) static void
brcmf_proto_bcdc_reset_if(struct brcmf_if *ifp)
{
	brcmf_fws_reset_interface(ifp);
}