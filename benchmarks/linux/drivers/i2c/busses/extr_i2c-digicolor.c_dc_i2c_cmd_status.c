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
typedef  int /*<<< orphan*/  u8 ;
struct dc_i2c {scalar_t__ regs; } ;

/* Variables and functions */
 scalar_t__ II_COMMAND ; 
 int II_COMMAND_COMPLETION_STATUS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  readb_relaxed (scalar_t__) ; 

__attribute__((used)) static int dc_i2c_cmd_status(struct dc_i2c *i2c)
{
	u8 cmd = readb_relaxed(i2c->regs + II_COMMAND);

	return II_COMMAND_COMPLETION_STATUS(cmd);
}