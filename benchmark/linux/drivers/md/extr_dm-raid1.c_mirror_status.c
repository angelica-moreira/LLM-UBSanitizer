#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct mirror_set {unsigned int nr_mirrors; TYPE_3__* mirror; scalar_t__ nr_regions; int /*<<< orphan*/  rh; } ;
struct dm_target {scalar_t__ private; } ;
struct dm_dirty_log {TYPE_1__* type; } ;
typedef  int status_type_t ;
struct TYPE_6__ {scalar_t__ offset; TYPE_2__* dev; } ;
struct TYPE_5__ {int /*<<< orphan*/  name; } ;
struct TYPE_4__ {unsigned int (* status ) (struct dm_dirty_log*,int,char*,unsigned int) ;scalar_t__ (* get_sync_count ) (struct dm_dirty_log*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  DMEMIT (char*,...) ; 
 int /*<<< orphan*/  MAX_NR_MIRRORS ; 
#define  STATUSTYPE_INFO 129 
#define  STATUSTYPE_TABLE 128 
 char device_status_char (TYPE_3__*) ; 
 struct dm_dirty_log* dm_rh_dirty_log (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  errors_handled (struct mirror_set*) ; 
 int /*<<< orphan*/  keep_log (struct mirror_set*) ; 
 scalar_t__ stub1 (struct dm_dirty_log*) ; 
 unsigned int stub2 (struct dm_dirty_log*,int,char*,unsigned int) ; 
 unsigned int stub3 (struct dm_dirty_log*,int,char*,unsigned int) ; 

__attribute__((used)) static void mirror_status(struct dm_target *ti, status_type_t type,
			  unsigned status_flags, char *result, unsigned maxlen)
{
	unsigned int m, sz = 0;
	int num_feature_args = 0;
	struct mirror_set *ms = (struct mirror_set *) ti->private;
	struct dm_dirty_log *log = dm_rh_dirty_log(ms->rh);
	char buffer[MAX_NR_MIRRORS + 1];

	switch (type) {
	case STATUSTYPE_INFO:
		DMEMIT("%d ", ms->nr_mirrors);
		for (m = 0; m < ms->nr_mirrors; m++) {
			DMEMIT("%s ", ms->mirror[m].dev->name);
			buffer[m] = device_status_char(&(ms->mirror[m]));
		}
		buffer[m] = '\0';

		DMEMIT("%llu/%llu 1 %s ",
		      (unsigned long long)log->type->get_sync_count(log),
		      (unsigned long long)ms->nr_regions, buffer);

		sz += log->type->status(log, type, result+sz, maxlen-sz);

		break;

	case STATUSTYPE_TABLE:
		sz = log->type->status(log, type, result, maxlen);

		DMEMIT("%d", ms->nr_mirrors);
		for (m = 0; m < ms->nr_mirrors; m++)
			DMEMIT(" %s %llu", ms->mirror[m].dev->name,
			       (unsigned long long)ms->mirror[m].offset);

		num_feature_args += !!errors_handled(ms);
		num_feature_args += !!keep_log(ms);
		if (num_feature_args) {
			DMEMIT(" %d", num_feature_args);
			if (errors_handled(ms))
				DMEMIT(" handle_errors");
			if (keep_log(ms))
				DMEMIT(" keep_log");
		}

		break;
	}
}