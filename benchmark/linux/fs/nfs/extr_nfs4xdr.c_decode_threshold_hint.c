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
typedef  scalar_t__ uint64_t ;
typedef  int uint32_t ;
struct xdr_stream {int dummy; } ;
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 int EIO ; 
 scalar_t__ likely (int) ; 
 scalar_t__ unlikely (int) ; 
 int /*<<< orphan*/  xdr_decode_hyper (int /*<<< orphan*/ *,scalar_t__*) ; 
 int /*<<< orphan*/ * xdr_inline_decode (struct xdr_stream*,int) ; 

__attribute__((used)) static int decode_threshold_hint(struct xdr_stream *xdr,
				  uint32_t *bitmap,
				  uint64_t *res,
				  uint32_t hint_bit)
{
	__be32 *p;

	*res = 0;
	if (likely(bitmap[0] & hint_bit)) {
		p = xdr_inline_decode(xdr, 8);
		if (unlikely(!p))
			return -EIO;
		xdr_decode_hyper(p, res);
	}
	return 0;
}