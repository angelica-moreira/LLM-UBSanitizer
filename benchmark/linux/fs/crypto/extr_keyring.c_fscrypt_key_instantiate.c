#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct key_preparsed_payload {scalar_t__ data; } ;
struct TYPE_2__ {struct fscrypt_master_key** data; } ;
struct key {TYPE_1__ payload; } ;
struct fscrypt_master_key {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static int fscrypt_key_instantiate(struct key *key,
				   struct key_preparsed_payload *prep)
{
	key->payload.data[0] = (struct fscrypt_master_key *)prep->data;
	return 0;
}