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
typedef  int /*<<< orphan*/  u32 ;
struct ast_private {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  mmc_test2 (struct ast_private*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static u32 mmc_test_burst2(struct ast_private *ast, u32 datagen)
{
	return mmc_test2(ast, datagen, 0x41);
}