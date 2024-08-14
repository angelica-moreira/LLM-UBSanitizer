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
typedef  int /*<<< orphan*/  u32 ;
struct cast6_ctx {int /*<<< orphan*/ ** Kr; int /*<<< orphan*/ ** Km; } ;
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 int /*<<< orphan*/  Q (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  QBAR (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  be32_to_cpu (int /*<<< orphan*/  const) ; 
 int /*<<< orphan*/  cpu_to_be32 (int /*<<< orphan*/ ) ; 

void __cast6_encrypt(struct cast6_ctx *c, u8 *outbuf, const u8 *inbuf)
{
	const __be32 *src = (const __be32 *)inbuf;
	__be32 *dst = (__be32 *)outbuf;
	u32 block[4];
	u32 *Km;
	u8 *Kr;

	block[0] = be32_to_cpu(src[0]);
	block[1] = be32_to_cpu(src[1]);
	block[2] = be32_to_cpu(src[2]);
	block[3] = be32_to_cpu(src[3]);

	Km = c->Km[0]; Kr = c->Kr[0]; Q(block, Kr, Km);
	Km = c->Km[1]; Kr = c->Kr[1]; Q(block, Kr, Km);
	Km = c->Km[2]; Kr = c->Kr[2]; Q(block, Kr, Km);
	Km = c->Km[3]; Kr = c->Kr[3]; Q(block, Kr, Km);
	Km = c->Km[4]; Kr = c->Kr[4]; Q(block, Kr, Km);
	Km = c->Km[5]; Kr = c->Kr[5]; Q(block, Kr, Km);
	Km = c->Km[6]; Kr = c->Kr[6]; QBAR(block, Kr, Km);
	Km = c->Km[7]; Kr = c->Kr[7]; QBAR(block, Kr, Km);
	Km = c->Km[8]; Kr = c->Kr[8]; QBAR(block, Kr, Km);
	Km = c->Km[9]; Kr = c->Kr[9]; QBAR(block, Kr, Km);
	Km = c->Km[10]; Kr = c->Kr[10]; QBAR(block, Kr, Km);
	Km = c->Km[11]; Kr = c->Kr[11]; QBAR(block, Kr, Km);

	dst[0] = cpu_to_be32(block[0]);
	dst[1] = cpu_to_be32(block[1]);
	dst[2] = cpu_to_be32(block[2]);
	dst[3] = cpu_to_be32(block[3]);
}