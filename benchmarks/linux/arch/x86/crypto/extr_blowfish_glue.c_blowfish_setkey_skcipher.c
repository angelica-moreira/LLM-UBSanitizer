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
struct crypto_skcipher {int /*<<< orphan*/  base; } ;

/* Variables and functions */
 int blowfish_setkey (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,unsigned int) ; 

__attribute__((used)) static int blowfish_setkey_skcipher(struct crypto_skcipher *tfm,
				    const u8 *key, unsigned int keylen)
{
	return blowfish_setkey(&tfm->base, key, keylen);
}