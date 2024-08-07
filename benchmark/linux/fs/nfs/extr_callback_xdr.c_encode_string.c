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
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 int /*<<< orphan*/  NFS4ERR_RESOURCE ; 
 int /*<<< orphan*/  cpu_to_be32 (int /*<<< orphan*/ ) ; 
 scalar_t__ unlikely (int) ; 
 scalar_t__ xdr_stream_encode_opaque (struct xdr_stream*,char const*,unsigned int) ; 

__attribute__((used)) static __be32 encode_string(struct xdr_stream *xdr, unsigned int len, const char *str)
{
	if (unlikely(xdr_stream_encode_opaque(xdr, str, len) < 0))
		return cpu_to_be32(NFS4ERR_RESOURCE);
	return 0;
}