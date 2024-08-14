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
struct __sk_buff {int* cb; int /*<<< orphan*/  priority; } ;

/* Variables and functions */

int process(struct __sk_buff *skb)
{
	#pragma clang loop unroll(full)
	for (int i = 0; i < 5; i++) {
		if (skb->cb[i] != i + 1)
			return 1;
		skb->cb[i]++;
	}
	skb->priority++;

	return 0;
}