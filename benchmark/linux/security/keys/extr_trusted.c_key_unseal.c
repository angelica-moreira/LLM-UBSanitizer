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
struct trusted_key_payload {size_t key_len; int /*<<< orphan*/ * key; int /*<<< orphan*/  migratable; int /*<<< orphan*/  blob_len; int /*<<< orphan*/  blob; } ;
struct trusted_key_options {int /*<<< orphan*/  blobauth; int /*<<< orphan*/  keyauth; int /*<<< orphan*/  keyhandle; } ;
struct tpm_buf {int dummy; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 struct tpm_buf* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kzfree (struct tpm_buf*) ; 
 int /*<<< orphan*/  pr_info (char*,int) ; 
 int tpm_unseal (struct tpm_buf*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,size_t*) ; 

__attribute__((used)) static int key_unseal(struct trusted_key_payload *p,
		      struct trusted_key_options *o)
{
	struct tpm_buf *tb;
	int ret;

	tb = kzalloc(sizeof *tb, GFP_KERNEL);
	if (!tb)
		return -ENOMEM;

	ret = tpm_unseal(tb, o->keyhandle, o->keyauth, p->blob, p->blob_len,
			 o->blobauth, p->key, &p->key_len);
	if (ret < 0)
		pr_info("trusted_key: srkunseal failed (%d)\n", ret);
	else
		/* pull migratable flag out of sealed key */
		p->migratable = p->key[--p->key_len];

	kzfree(tb);
	return ret;
}