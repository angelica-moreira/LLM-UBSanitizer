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
struct ida {int /*<<< orphan*/  xa; } ;

/* Variables and functions */
 int /*<<< orphan*/  IDA_INIT_FLAGS ; 
 int /*<<< orphan*/  xa_init_flags (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void ida_init(struct ida *ida)
{
	xa_init_flags(&ida->xa, IDA_INIT_FLAGS);
}