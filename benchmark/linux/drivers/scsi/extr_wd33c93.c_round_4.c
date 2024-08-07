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

/* Variables and functions */

__attribute__((used)) static inline unsigned int
round_4(unsigned int x)
{
	switch (x & 3) {
		case 1: --x;
			break;
		case 2: ++x;
			/* fall through */
		case 3: ++x;
	}
	return x;
}