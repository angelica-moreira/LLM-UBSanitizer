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
struct page {int dummy; } ;
struct file {int dummy; } ;
struct address_space {int /*<<< orphan*/  host; } ;
typedef  unsigned int loff_t ;
struct TYPE_2__ {int /*<<< orphan*/  phys_size; } ;

/* Variables and functions */
 TYPE_1__* HFSPLUS_I (int /*<<< orphan*/ ) ; 
 int cont_write_begin (struct file*,struct address_space*,unsigned int,unsigned int,unsigned int,struct page**,void**,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  hfsplus_get_block ; 
 int /*<<< orphan*/  hfsplus_write_failed (struct address_space*,unsigned int) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static int hfsplus_write_begin(struct file *file, struct address_space *mapping,
			loff_t pos, unsigned len, unsigned flags,
			struct page **pagep, void **fsdata)
{
	int ret;

	*pagep = NULL;
	ret = cont_write_begin(file, mapping, pos, len, flags, pagep, fsdata,
				hfsplus_get_block,
				&HFSPLUS_I(mapping->host)->phys_size);
	if (unlikely(ret))
		hfsplus_write_failed(mapping, pos + len);

	return ret;
}