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
typedef  enum lzma_state { ____Placeholder_lzma_state } lzma_state ;

/* Variables and functions */
 int LIT_STATES ; 

__attribute__((used)) static inline bool lzma_state_is_literal(enum lzma_state state)
{
	return state < LIT_STATES;
}