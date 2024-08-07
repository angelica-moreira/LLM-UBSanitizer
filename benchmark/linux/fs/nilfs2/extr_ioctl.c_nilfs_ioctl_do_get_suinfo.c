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
struct the_nilfs {int /*<<< orphan*/  ns_segctor_sem; int /*<<< orphan*/  ns_sufile; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  __u64 ;

/* Variables and functions */
 int /*<<< orphan*/  down_read (int /*<<< orphan*/ *) ; 
 int nilfs_sufile_get_suinfo (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*,size_t,size_t) ; 
 int /*<<< orphan*/  up_read (int /*<<< orphan*/ *) ; 

__attribute__((used)) static ssize_t
nilfs_ioctl_do_get_suinfo(struct the_nilfs *nilfs, __u64 *posp, int flags,
			  void *buf, size_t size, size_t nmembs)
{
	int ret;

	down_read(&nilfs->ns_segctor_sem);
	ret = nilfs_sufile_get_suinfo(nilfs->ns_sufile, *posp, buf, size,
				      nmembs);
	up_read(&nilfs->ns_segctor_sem);
	return ret;
}