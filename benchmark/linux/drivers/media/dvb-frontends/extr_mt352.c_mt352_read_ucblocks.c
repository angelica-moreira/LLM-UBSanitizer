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
struct mt352_state {int dummy; } ;
struct dvb_frontend {struct mt352_state* demodulator_priv; } ;

/* Variables and functions */
 int /*<<< orphan*/  RS_UBC_0 ; 
 int /*<<< orphan*/  RS_UBC_1 ; 
 int mt352_read_register (struct mt352_state*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int mt352_read_ucblocks(struct dvb_frontend* fe, u32* ucblocks)
{
	struct mt352_state* state = fe->demodulator_priv;

	*ucblocks = (mt352_read_register (state,  RS_UBC_1) << 8) |
		    (mt352_read_register (state,  RS_UBC_0));

	return 0;
}