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
struct chksum_desc_ctx {int /*<<< orphan*/  crc; } ;
typedef  int /*<<< orphan*/  __u16 ;

/* Variables and functions */
 struct chksum_desc_ctx* shash_desc_ctx (struct shash_desc*) ; 

__attribute__((used)) static int chksum_final(struct shash_desc *desc, u8 *out)
{
	struct chksum_desc_ctx *ctx = shash_desc_ctx(desc);

	*(__u16 *)out = ctx->crc;
	return 0;
}