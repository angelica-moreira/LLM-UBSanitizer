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
struct arglist {int dummy; } ;

/* Variables and functions */
 int ETH_MAX_PACKET ; 
 scalar_t__ kstrtoul (char*,int,long*) ; 
 char* uml_vector_fetch_arg (struct arglist*,char*) ; 

__attribute__((used)) static int get_mtu(struct arglist *def)
{
	char *mtu = uml_vector_fetch_arg(def, "mtu");
	long result;

	if (mtu != NULL) {
		if (kstrtoul(mtu, 10, &result) == 0)
			if ((result < (1 << 16) - 1) && (result >= 576))
				return result;
	}
	return ETH_MAX_PACKET;
}