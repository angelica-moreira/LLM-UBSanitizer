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
struct qstr {char const* name; int /*<<< orphan*/  len; int /*<<< orphan*/  hash; } ;

/* Variables and functions */
 int /*<<< orphan*/  gfs2_disk_hash (char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strlen (char const*) ; 

__attribute__((used)) static inline void gfs2_str2qstr(struct qstr *name, const char *fname)
{
	name->name = fname;
	name->len = strlen(fname);
	name->hash = gfs2_disk_hash(name->name, name->len);
}