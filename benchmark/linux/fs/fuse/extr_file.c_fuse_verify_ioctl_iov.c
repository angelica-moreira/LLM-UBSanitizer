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
typedef  int u32 ;
struct iovec {size_t iov_len; } ;
struct fuse_conn {int max_pages; } ;

/* Variables and functions */
 int ENOMEM ; 
 int PAGE_SHIFT ; 

__attribute__((used)) static int fuse_verify_ioctl_iov(struct fuse_conn *fc, struct iovec *iov,
				 size_t count)
{
	size_t n;
	u32 max = fc->max_pages << PAGE_SHIFT;

	for (n = 0; n < count; n++, iov++) {
		if (iov->iov_len > (size_t) max)
			return -ENOMEM;
		max -= iov->iov_len;
	}
	return 0;
}