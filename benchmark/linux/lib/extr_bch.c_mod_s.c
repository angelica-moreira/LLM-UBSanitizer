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
struct bch_control {int dummy; } ;

/* Variables and functions */
 unsigned int GF_N (struct bch_control*) ; 

__attribute__((used)) static inline int mod_s(struct bch_control *bch, unsigned int v)
{
	const unsigned int n = GF_N(bch);
	return (v < n) ? v : v-n;
}