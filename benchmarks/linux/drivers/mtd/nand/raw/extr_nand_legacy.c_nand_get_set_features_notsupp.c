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
typedef  int /*<<< orphan*/  u8 ;
struct nand_chip {int dummy; } ;

/* Variables and functions */
 int ENOTSUPP ; 

int nand_get_set_features_notsupp(struct nand_chip *chip, int addr,
				  u8 *subfeature_param)
{
	return -ENOTSUPP;
}