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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  uint32_t ;
struct fsi_msg {int dummy; } ;
struct fsi_master_acf {int /*<<< orphan*/  lock; int /*<<< orphan*/  dev; } ;
struct fsi_master {int dummy; } ;

/* Variables and functions */
 int ENODEV ; 
 int /*<<< orphan*/  build_ar_command (struct fsi_master_acf*,struct fsi_msg*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,size_t,void const*) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,...) ; 
 int fsi_master_acf_xfer (struct fsi_master_acf*,int /*<<< orphan*/ ,struct fsi_msg*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  last_address_update (struct fsi_master_acf*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct fsi_master_acf* to_fsi_master_acf (struct fsi_master*) ; 

__attribute__((used)) static int fsi_master_acf_write(struct fsi_master *_master, int link,
				uint8_t id, uint32_t addr, const void *val,
				size_t size)
{
	struct fsi_master_acf *master = to_fsi_master_acf(_master);
	struct fsi_msg cmd;
	int rc;

	if (link != 0)
		return -ENODEV;

	mutex_lock(&master->lock);
	build_ar_command(master, &cmd, id, addr, size, val);
	dev_dbg(master->dev, "write id %d addr %x size %zd raw_data: %08x\n",
		id, addr, size, *(uint32_t *)val);
	rc = fsi_master_acf_xfer(master, id, &cmd, 0, NULL);
	last_address_update(master, id, rc == 0, addr);
	if (rc)
		dev_dbg(master->dev, "write id %d addr 0x%08x err: %d\n",
			id, addr, rc);
	mutex_unlock(&master->lock);

	return rc;
}