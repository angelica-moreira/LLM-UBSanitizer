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
typedef  scalar_t__ uint32_t ;
typedef  enum mdp5_pipe { ____Placeholder_mdp5_pipe } mdp5_pipe ;

/* Variables and functions */
 scalar_t__ __offset_PIPE (int) ; 

__attribute__((used)) static inline uint32_t REG_MDP5_PIPE_CURRENT_SRC1_ADDR(enum mdp5_pipe i0) { return 0x000000a8 + __offset_PIPE(i0); }