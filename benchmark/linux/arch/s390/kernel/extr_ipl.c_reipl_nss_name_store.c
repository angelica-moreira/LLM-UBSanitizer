#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct kobject {int dummy; } ;
struct kobj_attribute {int dummy; } ;
typedef  size_t ssize_t ;
struct TYPE_3__ {int /*<<< orphan*/  vm_flags; int /*<<< orphan*/  nss_name; } ;
struct TYPE_4__ {TYPE_1__ ccw; } ;

/* Variables and functions */
 int /*<<< orphan*/  ASCEBC (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  EBC_TOUPPER (int /*<<< orphan*/ ,int) ; 
 size_t EINVAL ; 
 int /*<<< orphan*/  IPL_PB0_CCW_VM_FLAG_NSS ; 
 int NSS_NAME_SIZE ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,char const*,int) ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ ,int,int) ; 
 TYPE_2__* reipl_block_nss ; 

__attribute__((used)) static ssize_t reipl_nss_name_store(struct kobject *kobj,
				    struct kobj_attribute *attr,
				    const char *buf, size_t len)
{
	int nss_len;

	/* ignore trailing newline */
	nss_len = len;
	if ((len > 0) && (buf[len - 1] == '\n'))
		nss_len--;

	if (nss_len > NSS_NAME_SIZE)
		return -EINVAL;

	memset(reipl_block_nss->ccw.nss_name, 0x40, NSS_NAME_SIZE);
	if (nss_len > 0) {
		reipl_block_nss->ccw.vm_flags |= IPL_PB0_CCW_VM_FLAG_NSS;
		memcpy(reipl_block_nss->ccw.nss_name, buf, nss_len);
		ASCEBC(reipl_block_nss->ccw.nss_name, nss_len);
		EBC_TOUPPER(reipl_block_nss->ccw.nss_name, nss_len);
	} else {
		reipl_block_nss->ccw.vm_flags &= ~IPL_PB0_CCW_VM_FLAG_NSS;
	}

	return len;
}