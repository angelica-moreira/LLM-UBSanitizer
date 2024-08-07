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
struct file {int dummy; } ;
struct cred {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  FILE__LOCK ; 
 struct cred* current_cred () ; 
 int file_has_perm (struct cred const*,struct file*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int selinux_file_lock(struct file *file, unsigned int cmd)
{
	const struct cred *cred = current_cred();

	return file_has_perm(cred, file, FILE__LOCK);
}