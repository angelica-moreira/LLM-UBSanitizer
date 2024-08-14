#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct list_head {int dummy; } ;
struct TYPE_4__ {unsigned int version; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
 TYPE_1__* aes_aead_algs ; 
 int ccp_register_aes_aead (struct list_head*,TYPE_1__*) ; 
 unsigned int ccp_version () ; 

int ccp_register_aes_aeads(struct list_head *head)
{
	int i, ret;
	unsigned int ccpversion = ccp_version();

	for (i = 0; i < ARRAY_SIZE(aes_aead_algs); i++) {
		if (aes_aead_algs[i].version > ccpversion)
			continue;
		ret = ccp_register_aes_aead(head, &aes_aead_algs[i]);
		if (ret)
			return ret;
	}

	return 0;
}