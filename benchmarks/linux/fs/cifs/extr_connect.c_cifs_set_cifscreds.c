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
struct smb_vol {int dummy; } ;
struct cifs_ses {int dummy; } ;

/* Variables and functions */
 int ENOSYS ; 

__attribute__((used)) static inline int
cifs_set_cifscreds(struct smb_vol *vol __attribute__((unused)),
		   struct cifs_ses *ses __attribute__((unused)))
{
	return -ENOSYS;
}