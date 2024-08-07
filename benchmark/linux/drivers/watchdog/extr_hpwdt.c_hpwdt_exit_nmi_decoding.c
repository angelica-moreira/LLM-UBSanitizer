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

/* Variables and functions */
 int /*<<< orphan*/  NMI_IO_CHECK ; 
 int /*<<< orphan*/  NMI_SERR ; 
 int /*<<< orphan*/  NMI_UNKNOWN ; 
 int /*<<< orphan*/  unregister_nmi_handler (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static void hpwdt_exit_nmi_decoding(void)
{
#ifdef CONFIG_HPWDT_NMI_DECODING
	unregister_nmi_handler(NMI_UNKNOWN, "hpwdt");
	unregister_nmi_handler(NMI_SERR, "hpwdt");
	unregister_nmi_handler(NMI_IO_CHECK, "hpwdt");
#endif
}