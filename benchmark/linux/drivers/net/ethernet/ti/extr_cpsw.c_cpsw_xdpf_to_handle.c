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
struct xdp_frame {int dummy; } ;

/* Variables and functions */
 unsigned long BIT (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void *cpsw_xdpf_to_handle(struct xdp_frame *xdpf)
{
	return (void *)((unsigned long)xdpf | BIT(0));
}