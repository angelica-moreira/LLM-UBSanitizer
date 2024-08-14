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
struct cifs_tcon {int dummy; } ;
struct cifs_fid {int /*<<< orphan*/  netfid; } ;

/* Variables and functions */
 int CIFSFindClose (unsigned int const,struct cifs_tcon*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
cifs_close_dir(const unsigned int xid, struct cifs_tcon *tcon,
	       struct cifs_fid *fid)
{
	return CIFSFindClose(xid, tcon, fid->netfid);
}