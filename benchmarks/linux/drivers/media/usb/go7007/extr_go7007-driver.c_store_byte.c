#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
struct TYPE_6__ {TYPE_2__* planes; } ;
struct TYPE_4__ {TYPE_3__ vb2_buf; } ;
struct go7007_buffer {TYPE_1__ vb; } ;
struct TYPE_5__ {scalar_t__ bytesused; } ;

/* Variables and functions */
 scalar_t__ GO7007_BUF_SIZE ; 
 int /*<<< orphan*/ * vb2_plane_vaddr (TYPE_3__*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void store_byte(struct go7007_buffer *vb, u8 byte)
{
	if (vb && vb->vb.vb2_buf.planes[0].bytesused < GO7007_BUF_SIZE) {
		u8 *ptr = vb2_plane_vaddr(&vb->vb.vb2_buf, 0);

		ptr[vb->vb.vb2_buf.planes[0].bytesused++] = byte;
	}
}