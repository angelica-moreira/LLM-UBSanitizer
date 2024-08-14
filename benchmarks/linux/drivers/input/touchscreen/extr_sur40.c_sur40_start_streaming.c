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
struct vb2_queue {int dummy; } ;
struct sur40_state {scalar_t__ sequence; } ;

/* Variables and functions */
 struct sur40_state* vb2_get_drv_priv (struct vb2_queue*) ; 

__attribute__((used)) static int sur40_start_streaming(struct vb2_queue *vq, unsigned int count)
{
	struct sur40_state *sur40 = vb2_get_drv_priv(vq);

	sur40->sequence = 0;
	return 0;
}