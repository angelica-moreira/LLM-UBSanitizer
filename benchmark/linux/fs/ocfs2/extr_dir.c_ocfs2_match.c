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
struct ocfs2_dir_entry {int name_len; int /*<<< orphan*/  name; int /*<<< orphan*/  inode; } ;

/* Variables and functions */
 int /*<<< orphan*/  memcmp (char const* const,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline int ocfs2_match(int len,
			      const char * const name,
			      struct ocfs2_dir_entry *de)
{
	if (len != de->name_len)
		return 0;
	if (!de->inode)
		return 0;
	return !memcmp(name, de->name, len);
}