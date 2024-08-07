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
typedef  int /*<<< orphan*/  u64 ;
struct xdr_stream {int dummy; } ;

/* Variables and functions */
 int decode_uint64 (struct xdr_stream*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int decode_cookie3(struct xdr_stream *xdr, u64 *cookie)
{
	return decode_uint64(xdr, cookie);
}