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
struct tep_handle {int dummy; } ;

/* Variables and functions */
 int get_common_info (struct tep_handle*,char const*,int*,int*) ; 
 int tep_read_number (struct tep_handle*,void*,int) ; 

__attribute__((used)) static int __parse_common(struct tep_handle *tep, void *data,
			  int *size, int *offset, const char *name)
{
	int ret;

	if (!*size) {
		ret = get_common_info(tep, name, offset, size);
		if (ret < 0)
			return ret;
	}
	return tep_read_number(tep, data + *offset, *size);
}