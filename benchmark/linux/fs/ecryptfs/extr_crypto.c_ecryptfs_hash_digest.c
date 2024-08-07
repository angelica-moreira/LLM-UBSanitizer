#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct crypto_shash {int dummy; } ;
struct TYPE_5__ {struct crypto_shash* tfm; } ;

/* Variables and functions */
 int /*<<< orphan*/  SHASH_DESC_ON_STACK (TYPE_1__*,struct crypto_shash*) ; 
 int crypto_shash_digest (TYPE_1__*,char*,int,char*) ; 
 TYPE_1__* desc ; 
 int /*<<< orphan*/  shash_desc_zero (TYPE_1__*) ; 

__attribute__((used)) static int ecryptfs_hash_digest(struct crypto_shash *tfm,
				char *src, int len, char *dst)
{
	SHASH_DESC_ON_STACK(desc, tfm);
	int err;

	desc->tfm = tfm;
	err = crypto_shash_digest(desc, src, len, dst);
	shash_desc_zero(desc);
	return err;
}