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
struct crypto_skcipher {int dummy; } ;

/* Variables and functions */
 unsigned int crypto_cipher_blocksize (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  skcipher_cipher_simple (struct crypto_skcipher*) ; 

__attribute__((used)) static unsigned int crypto_cfb_bsize(struct crypto_skcipher *tfm)
{
	return crypto_cipher_blocksize(skcipher_cipher_simple(tfm));
}