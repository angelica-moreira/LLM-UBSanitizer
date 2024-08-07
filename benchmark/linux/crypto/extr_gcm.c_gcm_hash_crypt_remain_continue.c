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
typedef  int /*<<< orphan*/  u32 ;
struct aead_request {int dummy; } ;

/* Variables and functions */
 scalar_t__ gcm_hash_len (struct aead_request*,int /*<<< orphan*/ ) ; 
 int gcm_hash_len_continue (struct aead_request*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int gcm_hash_crypt_remain_continue(struct aead_request *req, u32 flags)
{
	return gcm_hash_len(req, flags) ?:
	       gcm_hash_len_continue(req, flags);
}