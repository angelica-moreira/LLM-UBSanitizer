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
typedef  int u8 ;
struct mpc_i2c {scalar_t__ base; int /*<<< orphan*/  dev; } ;
struct i2c_msg {int flags; int len; int /*<<< orphan*/  buf; int /*<<< orphan*/  addr; } ;
struct i2c_adapter {int dummy; } ;

/* Variables and functions */
 int CSR_MAL ; 
 int CSR_MBB ; 
 int CSR_MCF ; 
 int CSR_RXAK ; 
 int EINTR ; 
 int EIO ; 
 scalar_t__ HZ ; 
 int I2C_M_RD ; 
 int I2C_M_RECV_LEN ; 
 scalar_t__ MPC_I2C_SR ; 
 int /*<<< orphan*/  cond_resched () ; 
 int /*<<< orphan*/  current ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,...) ; 
 struct mpc_i2c* i2c_get_adapdata (struct i2c_adapter*) ; 
 unsigned long jiffies ; 
 int /*<<< orphan*/  mpc_i2c_fixup (struct mpc_i2c*) ; 
 int /*<<< orphan*/  mpc_i2c_start (struct mpc_i2c*) ; 
 int /*<<< orphan*/  mpc_i2c_stop (struct mpc_i2c*) ; 
 int mpc_read (struct mpc_i2c*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int) ; 
 int mpc_write (struct mpc_i2c*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int readb (scalar_t__) ; 
 int /*<<< orphan*/  schedule () ; 
 scalar_t__ signal_pending (int /*<<< orphan*/ ) ; 
 scalar_t__ time_after (unsigned long,scalar_t__) ; 
 int /*<<< orphan*/  writeb (int,scalar_t__) ; 
 int /*<<< orphan*/  writeccr (struct mpc_i2c*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int mpc_xfer(struct i2c_adapter *adap, struct i2c_msg *msgs, int num)
{
	struct i2c_msg *pmsg;
	int i;
	int ret = 0;
	unsigned long orig_jiffies = jiffies;
	struct mpc_i2c *i2c = i2c_get_adapdata(adap);

	mpc_i2c_start(i2c);

	/* Allow bus up to 1s to become not busy */
	while (readb(i2c->base + MPC_I2C_SR) & CSR_MBB) {
		if (signal_pending(current)) {
			dev_dbg(i2c->dev, "Interrupted\n");
			writeccr(i2c, 0);
			return -EINTR;
		}
		if (time_after(jiffies, orig_jiffies + HZ)) {
			u8 status = readb(i2c->base + MPC_I2C_SR);

			dev_dbg(i2c->dev, "timeout\n");
			if ((status & (CSR_MCF | CSR_MBB | CSR_RXAK)) != 0) {
				writeb(status & ~CSR_MAL,
				       i2c->base + MPC_I2C_SR);
				mpc_i2c_fixup(i2c);
			}
			return -EIO;
		}
		schedule();
	}

	for (i = 0; ret >= 0 && i < num; i++) {
		pmsg = &msgs[i];
		dev_dbg(i2c->dev,
			"Doing %s %d bytes to 0x%02x - %d of %d messages\n",
			pmsg->flags & I2C_M_RD ? "read" : "write",
			pmsg->len, pmsg->addr, i + 1, num);
		if (pmsg->flags & I2C_M_RD) {
			bool recv_len = pmsg->flags & I2C_M_RECV_LEN;

			ret = mpc_read(i2c, pmsg->addr, pmsg->buf, pmsg->len, i,
				       recv_len);
			if (recv_len && ret > 0)
				pmsg->len = ret;
		} else {
			ret =
			    mpc_write(i2c, pmsg->addr, pmsg->buf, pmsg->len, i);
		}
	}
	mpc_i2c_stop(i2c); /* Initiate STOP */
	orig_jiffies = jiffies;
	/* Wait until STOP is seen, allow up to 1 s */
	while (readb(i2c->base + MPC_I2C_SR) & CSR_MBB) {
		if (time_after(jiffies, orig_jiffies + HZ)) {
			u8 status = readb(i2c->base + MPC_I2C_SR);

			dev_dbg(i2c->dev, "timeout\n");
			if ((status & (CSR_MCF | CSR_MBB | CSR_RXAK)) != 0) {
				writeb(status & ~CSR_MAL,
				       i2c->base + MPC_I2C_SR);
				mpc_i2c_fixup(i2c);
			}
			return -EIO;
		}
		cond_resched();
	}
	return (ret < 0) ? ret : num;
}