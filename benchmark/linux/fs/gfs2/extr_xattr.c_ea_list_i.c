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
struct gfs2_inode {int dummy; } ;
struct gfs2_ea_request {unsigned int er_data_len; scalar_t__* er_data; } ;
struct gfs2_ea_header {int ea_type; unsigned int ea_name_len; } ;
struct ea_list {unsigned int ei_size; struct gfs2_ea_request* ei_er; } ;
struct buffer_head {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG () ; 
 int ERANGE ; 
 char* GFS2_EA2NAME (struct gfs2_ea_header*) ; 
#define  GFS2_EATYPE_SECURITY 130 
#define  GFS2_EATYPE_SYS 129 
 int GFS2_EATYPE_UNUSED ; 
#define  GFS2_EATYPE_USR 128 
 int /*<<< orphan*/  memcpy (scalar_t__*,char*,unsigned int) ; 

__attribute__((used)) static int ea_list_i(struct gfs2_inode *ip, struct buffer_head *bh,
		     struct gfs2_ea_header *ea, struct gfs2_ea_header *prev,
		     void *private)
{
	struct ea_list *ei = private;
	struct gfs2_ea_request *er = ei->ei_er;
	unsigned int ea_size;
	char *prefix;
	unsigned int l;

	if (ea->ea_type == GFS2_EATYPE_UNUSED)
		return 0;

	switch (ea->ea_type) {
	case GFS2_EATYPE_USR:
		prefix = "user.";
		l = 5;
		break;
	case GFS2_EATYPE_SYS:
		prefix = "system.";
		l = 7;
		break;
	case GFS2_EATYPE_SECURITY:
		prefix = "security.";
		l = 9;
		break;
	default:
		BUG();
	}

	ea_size = l + ea->ea_name_len + 1;
	if (er->er_data_len) {
		if (ei->ei_size + ea_size > er->er_data_len)
			return -ERANGE;

		memcpy(er->er_data + ei->ei_size, prefix, l);
		memcpy(er->er_data + ei->ei_size + l, GFS2_EA2NAME(ea),
		       ea->ea_name_len);
		er->er_data[ei->ei_size + ea_size - 1] = 0;
	}

	ei->ei_size += ea_size;

	return 0;
}