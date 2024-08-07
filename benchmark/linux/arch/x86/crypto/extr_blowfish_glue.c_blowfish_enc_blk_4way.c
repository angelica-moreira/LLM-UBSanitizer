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
struct bf_ctx {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  __blowfish_enc_blk_4way (struct bf_ctx*,int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int) ; 

__attribute__((used)) static inline void blowfish_enc_blk_4way(struct bf_ctx *ctx, u8 *dst,
					 const u8 *src)
{
	__blowfish_enc_blk_4way(ctx, dst, src, false);
}