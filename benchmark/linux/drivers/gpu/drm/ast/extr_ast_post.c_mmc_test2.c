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
typedef  int u32 ;
struct ast_private {int dummy; } ;

/* Variables and functions */
 int TIMEOUT ; 
 int ast_mindwm (struct ast_private*,int) ; 
 int /*<<< orphan*/  ast_moutdwm (struct ast_private*,int,int) ; 

__attribute__((used)) static u32 mmc_test2(struct ast_private *ast, u32 datagen, u8 test_ctl)
{
	u32 data, timeout;

	ast_moutdwm(ast, 0x1e6e0070, 0x00000000);
	ast_moutdwm(ast, 0x1e6e0070, (datagen << 3) | test_ctl);
	timeout = 0;
	do {
		data = ast_mindwm(ast, 0x1e6e0070) & 0x1000;
		if (++timeout > TIMEOUT) {
			ast_moutdwm(ast, 0x1e6e0070, 0x0);
			return 0xffffffff;
		}
	} while (!data);
	data = ast_mindwm(ast, 0x1e6e0078);
	data = (data | (data >> 16)) & 0xffff;
	ast_moutdwm(ast, 0x1e6e0070, 0x00000000);
	return data;
}