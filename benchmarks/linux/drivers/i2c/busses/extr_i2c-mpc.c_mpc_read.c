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
typedef  scalar_t__ u8 ;
typedef  int u32 ;
struct TYPE_2__ {unsigned int timeout; } ;
struct mpc_i2c {scalar_t__ base; TYPE_1__ adap; } ;

/* Variables and functions */
 int CCR_MEN ; 
 int CCR_MIEN ; 
 int CCR_MSTA ; 
 int CCR_MTX ; 
 int CCR_RSTA ; 
 int CCR_TXAK ; 
 int EPROTO ; 
 scalar_t__ I2C_SMBUS_BLOCK_MAX ; 
 scalar_t__ MPC_I2C_DR ; 
 int i2c_wait (struct mpc_i2c*,unsigned int,int) ; 
 scalar_t__ readb (scalar_t__) ; 
 int /*<<< orphan*/  writeb (int,scalar_t__) ; 
 int /*<<< orphan*/  writeccr (struct mpc_i2c*,int) ; 

__attribute__((used)) static int mpc_read(struct mpc_i2c *i2c, int target,
		    u8 *data, int length, int restart, bool recv_len)
{
	unsigned timeout = i2c->adap.timeout;
	int i, result;
	u32 flags = restart ? CCR_RSTA : 0;

	/* Switch to read - restart */
	writeccr(i2c, CCR_MIEN | CCR_MEN | CCR_MSTA | CCR_MTX | flags);
	/* Write target address byte - this time with the read flag set */
	writeb((target << 1) | 1, i2c->base + MPC_I2C_DR);

	result = i2c_wait(i2c, timeout, 1);
	if (result < 0)
		return result;

	if (length) {
		if (length == 1 && !recv_len)
			writeccr(i2c, CCR_MIEN | CCR_MEN | CCR_MSTA | CCR_TXAK);
		else
			writeccr(i2c, CCR_MIEN | CCR_MEN | CCR_MSTA);
		/* Dummy read */
		readb(i2c->base + MPC_I2C_DR);
	}

	for (i = 0; i < length; i++) {
		u8 byte;

		result = i2c_wait(i2c, timeout, 0);
		if (result < 0)
			return result;

		/*
		 * For block reads, we have to know the total length (1st byte)
		 * before we can determine if we are done.
		 */
		if (i || !recv_len) {
			/* Generate txack on next to last byte */
			if (i == length - 2)
				writeccr(i2c, CCR_MIEN | CCR_MEN | CCR_MSTA
					 | CCR_TXAK);
			/* Do not generate stop on last byte */
			if (i == length - 1)
				writeccr(i2c, CCR_MIEN | CCR_MEN | CCR_MSTA
					 | CCR_MTX);
		}

		byte = readb(i2c->base + MPC_I2C_DR);

		/*
		 * Adjust length if first received byte is length.
		 * The length is 1 length byte plus actually data length
		 */
		if (i == 0 && recv_len) {
			if (byte == 0 || byte > I2C_SMBUS_BLOCK_MAX)
				return -EPROTO;
			length += byte;
			/*
			 * For block reads, generate txack here if data length
			 * is 1 byte (total length is 2 bytes).
			 */
			if (length == 2)
				writeccr(i2c, CCR_MIEN | CCR_MEN | CCR_MSTA
					 | CCR_TXAK);
		}
		data[i] = byte;
	}

	return length;
}