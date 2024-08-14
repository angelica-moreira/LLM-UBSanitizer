#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {scalar_t__ datum; } ;
typedef  TYPE_1__ dn_fib_key_t ;

/* Variables and functions */

__attribute__((used)) static inline int dn_key_leq(dn_fib_key_t a, dn_fib_key_t b)
{
	return a.datum <= b.datum;
}