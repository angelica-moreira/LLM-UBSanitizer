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
struct mb86a16_state {int dummy; } ;

/* Variables and functions */
 int EREMOTEIO ; 
 int /*<<< orphan*/  MB86A16_ERROR ; 
 int /*<<< orphan*/  dprintk (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,char*) ; 
 int mb86a16_read (struct mb86a16_state*,int,unsigned char*) ; 
 int /*<<< orphan*/  verbose ; 

__attribute__((used)) static int dagcm_val_get(struct mb86a16_state *state)
{
	int DAGCM;
	unsigned char DAGCM_H, DAGCM_L;

	if (mb86a16_read(state, 0x45, &DAGCM_L) != 2)
		goto err;
	if (mb86a16_read(state, 0x46, &DAGCM_H) != 2)
		goto err;

	DAGCM = (DAGCM_H << 8) + DAGCM_L;

	return DAGCM;

err:
	dprintk(verbose, MB86A16_ERROR, 1, "I2C transfer error");
	return -EREMOTEIO;
}