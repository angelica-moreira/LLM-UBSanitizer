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
struct seq_file {int dummy; } ;
struct Scsi_Host {scalar_t__ hostdata; } ;
typedef  int /*<<< orphan*/  ips_ha_t ;

/* Variables and functions */
 int EINVAL ; 
 int ips_host_info (int /*<<< orphan*/ *,struct seq_file*) ; 
 int ips_next_controller ; 
 struct Scsi_Host** ips_sh ; 

__attribute__((used)) static int
ips_show_info(struct seq_file *m, struct Scsi_Host *host)
{
	int i;
	ips_ha_t *ha = NULL;

	/* Find our host structure */
	for (i = 0; i < ips_next_controller; i++) {
		if (ips_sh[i]) {
			if (ips_sh[i] == host) {
				ha = (ips_ha_t *) ips_sh[i]->hostdata;
				break;
			}
		}
	}

	if (!ha)
		return (-EINVAL);

	return ips_host_info(ha, m);
}