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
struct crypto_tfm {int dummy; } ;

/* Variables and functions */
 int omap_sham_cra_init_alg (struct crypto_tfm*,char*) ; 

__attribute__((used)) static int omap_sham_cra_sha224_init(struct crypto_tfm *tfm)
{
	return omap_sham_cra_init_alg(tfm, "sha224");
}