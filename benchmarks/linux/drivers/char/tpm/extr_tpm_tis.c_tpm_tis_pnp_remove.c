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
struct tpm_chip {int dummy; } ;
struct pnp_dev {int dummy; } ;

/* Variables and functions */
 struct tpm_chip* pnp_get_drvdata (struct pnp_dev*) ; 
 int /*<<< orphan*/  tpm_chip_unregister (struct tpm_chip*) ; 
 int /*<<< orphan*/  tpm_tis_remove (struct tpm_chip*) ; 

__attribute__((used)) static void tpm_tis_pnp_remove(struct pnp_dev *dev)
{
	struct tpm_chip *chip = pnp_get_drvdata(dev);

	tpm_chip_unregister(chip);
	tpm_tis_remove(chip);
}