#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u64 ;
struct xiocb_buffer {int dummy; } ;
struct TYPE_3__ {unsigned int buf_ioctlcmd; int buf_length; int buf_retlen; int /*<<< orphan*/  buf_ptr; int /*<<< orphan*/  buf_offset; } ;
struct TYPE_4__ {TYPE_1__ xiocb_buffer; } ;
struct cfe_xiocb {int xiocb_status; int xiocb_handle; int xiocb_psize; TYPE_2__ plist; scalar_t__ xiocb_flags; int /*<<< orphan*/  xiocb_fcode; } ;

/* Variables and functions */
 int /*<<< orphan*/  CFE_CMD_DEV_IOCTL ; 
 int /*<<< orphan*/  XPTR_FROM_NATIVE (unsigned char*) ; 
 int /*<<< orphan*/  cfe_iocb_dispatch (struct cfe_xiocb*) ; 

int
cfe_ioctl(int handle, unsigned int ioctlnum, unsigned char *buffer,
	  int length, int *retlen, u64 offset)
{
	struct cfe_xiocb xiocb;

	xiocb.xiocb_fcode = CFE_CMD_DEV_IOCTL;
	xiocb.xiocb_status = 0;
	xiocb.xiocb_handle = handle;
	xiocb.xiocb_flags = 0;
	xiocb.xiocb_psize = sizeof(struct xiocb_buffer);
	xiocb.plist.xiocb_buffer.buf_offset = offset;
	xiocb.plist.xiocb_buffer.buf_ioctlcmd = ioctlnum;
	xiocb.plist.xiocb_buffer.buf_ptr = XPTR_FROM_NATIVE(buffer);
	xiocb.plist.xiocb_buffer.buf_length = length;

	cfe_iocb_dispatch(&xiocb);

	if (retlen)
		*retlen = xiocb.plist.xiocb_buffer.buf_retlen;
	return xiocb.xiocb_status;
}