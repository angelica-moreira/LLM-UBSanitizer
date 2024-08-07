#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct cifs_tcon {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  netfid; } ;
struct cifsFileInfo {TYPE_1__ fid; } ;

/* Variables and functions */
 int CIFSSMB_set_compression (unsigned int const,struct cifs_tcon*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
cifs_set_compression(const unsigned int xid, struct cifs_tcon *tcon,
		   struct cifsFileInfo *cfile)
{
	return CIFSSMB_set_compression(xid, tcon, cfile->fid.netfid);
}