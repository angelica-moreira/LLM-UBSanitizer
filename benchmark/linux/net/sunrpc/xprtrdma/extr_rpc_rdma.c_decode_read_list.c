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
struct xdr_stream {int dummy; } ;
typedef  scalar_t__ __be32 ;

/* Variables and functions */
 int EIO ; 
 scalar_t__ unlikely (int) ; 
 scalar_t__* xdr_inline_decode (struct xdr_stream*,int) ; 
 scalar_t__ xdr_zero ; 

__attribute__((used)) static int decode_read_list(struct xdr_stream *xdr)
{
	__be32 *p;

	p = xdr_inline_decode(xdr, sizeof(*p));
	if (unlikely(!p))
		return -EIO;
	if (unlikely(*p != xdr_zero))
		return -EIO;
	return 0;
}