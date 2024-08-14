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
typedef  int /*<<< orphan*/  u64 ;
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  tmp ;
struct nfp_cpp {int dummy; } ;

/* Variables and functions */
 int EIO ; 
 int /*<<< orphan*/  get_unaligned_le64 (int /*<<< orphan*/ *) ; 
 int nfp_cpp_read (struct nfp_cpp*,int /*<<< orphan*/ ,unsigned long long,int /*<<< orphan*/ *,int) ; 

int nfp_cpp_readq(struct nfp_cpp *cpp, u32 cpp_id,
		  unsigned long long address, u64 *value)
{
	u8 tmp[8];
	int n;

	n = nfp_cpp_read(cpp, cpp_id, address, tmp, sizeof(tmp));
	if (n != sizeof(tmp))
		return n < 0 ? n : -EIO;

	*value = get_unaligned_le64(tmp);
	return 0;
}