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
typedef  int u32 ;
struct adapter {int dummy; } ;

/* Variables and functions */
 int BYTECNT_V (unsigned int) ; 
 int EBUSY ; 
 int EINVAL ; 
 int /*<<< orphan*/  SF_ATTEMPTS ; 
 int SF_BUSY_F ; 
 int SF_CONT_V (int) ; 
 int /*<<< orphan*/  SF_DATA_A ; 
 int SF_LOCK_V (int) ; 
 int /*<<< orphan*/  SF_OP_A ; 
 int t4_read_reg (struct adapter*,int /*<<< orphan*/ ) ; 
 int t4_wait_op_done (struct adapter*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  t4_write_reg (struct adapter*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int sf1_read(struct adapter *adapter, unsigned int byte_cnt, int cont,
		    int lock, u32 *valp)
{
	int ret;

	if (!byte_cnt || byte_cnt > 4)
		return -EINVAL;
	if (t4_read_reg(adapter, SF_OP_A) & SF_BUSY_F)
		return -EBUSY;
	t4_write_reg(adapter, SF_OP_A, SF_LOCK_V(lock) |
		     SF_CONT_V(cont) | BYTECNT_V(byte_cnt - 1));
	ret = t4_wait_op_done(adapter, SF_OP_A, SF_BUSY_F, 0, SF_ATTEMPTS, 5);
	if (!ret)
		*valp = t4_read_reg(adapter, SF_DATA_A);
	return ret;
}