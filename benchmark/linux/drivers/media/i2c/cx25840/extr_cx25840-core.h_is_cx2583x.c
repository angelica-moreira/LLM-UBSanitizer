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
struct cx25840_state {scalar_t__ id; } ;

/* Variables and functions */
 scalar_t__ CX25836 ; 
 scalar_t__ CX25837 ; 

__attribute__((used)) static inline bool is_cx2583x(struct cx25840_state *state)
{
	return state->id == CX25836 ||
	       state->id == CX25837;
}