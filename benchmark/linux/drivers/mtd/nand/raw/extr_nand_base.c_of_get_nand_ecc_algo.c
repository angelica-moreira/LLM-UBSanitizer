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
struct device_node {int dummy; } ;

/* Variables and functions */
 int ARRAY_SIZE (char**) ; 
 int ENODEV ; 
 int NAND_ECC_BCH ; 
 int NAND_ECC_HAMMING ; 
 char** nand_ecc_algos ; 
 int of_property_read_string (struct device_node*,char*,char const**) ; 
 int /*<<< orphan*/  strcasecmp (char const*,char*) ; 

__attribute__((used)) static int of_get_nand_ecc_algo(struct device_node *np)
{
	const char *pm;
	int err, i;

	err = of_property_read_string(np, "nand-ecc-algo", &pm);
	if (!err) {
		for (i = NAND_ECC_HAMMING; i < ARRAY_SIZE(nand_ecc_algos); i++)
			if (!strcasecmp(pm, nand_ecc_algos[i]))
				return i;
		return -ENODEV;
	}

	/*
	 * For backward compatibility we also read "nand-ecc-mode" checking
	 * for some obsoleted values that were specifying ECC algorithm.
	 */
	err = of_property_read_string(np, "nand-ecc-mode", &pm);
	if (err < 0)
		return err;

	if (!strcasecmp(pm, "soft"))
		return NAND_ECC_HAMMING;
	else if (!strcasecmp(pm, "soft_bch"))
		return NAND_ECC_BCH;

	return -ENODEV;
}