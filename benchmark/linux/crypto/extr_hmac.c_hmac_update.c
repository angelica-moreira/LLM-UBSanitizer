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
struct shash_desc {int dummy; } ;

/* Variables and functions */
 int crypto_shash_update (struct shash_desc*,int /*<<< orphan*/  const*,unsigned int) ; 
 struct shash_desc* shash_desc_ctx (struct shash_desc*) ; 

__attribute__((used)) static int hmac_update(struct shash_desc *pdesc,
		       const u8 *data, unsigned int nbytes)
{
	struct shash_desc *desc = shash_desc_ctx(pdesc);

	return crypto_shash_update(desc, data, nbytes);
}