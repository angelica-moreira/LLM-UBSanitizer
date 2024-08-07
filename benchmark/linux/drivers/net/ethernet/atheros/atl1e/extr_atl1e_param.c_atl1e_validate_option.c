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
struct TYPE_5__ {int nr; struct atl1e_opt_list* p; } ;
struct TYPE_4__ {int min; int max; } ;
struct TYPE_6__ {TYPE_2__ l; TYPE_1__ r; } ;
struct atl1e_option {int def; int type; int /*<<< orphan*/  err; int /*<<< orphan*/  name; TYPE_3__ arg; } ;
struct atl1e_opt_list {int i; char* str; } ;
struct atl1e_adapter {int /*<<< orphan*/  netdev; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG () ; 
#define  OPTION_DISABLED 132 
#define  OPTION_ENABLED 131 
 int OPTION_UNSET ; 
#define  enable_option 130 
#define  list_option 129 
 int /*<<< orphan*/  netdev_info (int /*<<< orphan*/ ,char*,char*,...) ; 
#define  range_option 128 

__attribute__((used)) static int atl1e_validate_option(int *value, struct atl1e_option *opt,
				 struct atl1e_adapter *adapter)
{
	if (*value == OPTION_UNSET) {
		*value = opt->def;
		return 0;
	}

	switch (opt->type) {
	case enable_option:
		switch (*value) {
		case OPTION_ENABLED:
			netdev_info(adapter->netdev,
				    "%s Enabled\n", opt->name);
			return 0;
		case OPTION_DISABLED:
			netdev_info(adapter->netdev,
				    "%s Disabled\n", opt->name);
			return 0;
		}
		break;
	case range_option:
		if (*value >= opt->arg.r.min && *value <= opt->arg.r.max) {
			netdev_info(adapter->netdev, "%s set to %i\n",
				    opt->name, *value);
			return 0;
		}
		break;
	case list_option:{
			int i;
			struct atl1e_opt_list *ent;

			for (i = 0; i < opt->arg.l.nr; i++) {
				ent = &opt->arg.l.p[i];
				if (*value == ent->i) {
					if (ent->str[0] != '\0')
						netdev_info(adapter->netdev,
							    "%s\n", ent->str);
					return 0;
				}
			}
			break;
		}
	default:
		BUG();
	}

	netdev_info(adapter->netdev, "Invalid %s specified (%i) %s\n",
		    opt->name, *value, opt->err);
	*value = opt->def;
	return -1;
}