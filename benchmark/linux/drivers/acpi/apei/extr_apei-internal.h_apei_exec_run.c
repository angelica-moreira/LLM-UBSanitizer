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
struct apei_exec_context {int dummy; } ;

/* Variables and functions */
 int __apei_exec_run (struct apei_exec_context*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int apei_exec_run(struct apei_exec_context *ctx, u8 action)
{
	return __apei_exec_run(ctx, action, 0);
}