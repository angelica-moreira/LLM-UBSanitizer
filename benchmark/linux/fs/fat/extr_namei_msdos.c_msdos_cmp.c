#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct qstr {char const* name; unsigned int len; } ;
struct fat_mount_options {int dummy; } ;
struct dentry {int /*<<< orphan*/  d_sb; } ;
struct TYPE_2__ {struct fat_mount_options options; } ;

/* Variables and functions */
 int MSDOS_NAME ; 
 TYPE_1__* MSDOS_SB (int /*<<< orphan*/ ) ; 
 int memcmp (unsigned char*,...) ; 
 int msdos_format_name (char const*,unsigned int,unsigned char*,struct fat_mount_options*) ; 

__attribute__((used)) static int msdos_cmp(const struct dentry *dentry,
		unsigned int len, const char *str, const struct qstr *name)
{
	struct fat_mount_options *options = &MSDOS_SB(dentry->d_sb)->options;
	unsigned char a_msdos_name[MSDOS_NAME], b_msdos_name[MSDOS_NAME];
	int error;

	error = msdos_format_name(name->name, name->len, a_msdos_name, options);
	if (error)
		goto old_compare;
	error = msdos_format_name(str, len, b_msdos_name, options);
	if (error)
		goto old_compare;
	error = memcmp(a_msdos_name, b_msdos_name, MSDOS_NAME);
out:
	return error;

old_compare:
	error = 1;
	if (name->len == len)
		error = memcmp(name->name, str, len);
	goto out;
}