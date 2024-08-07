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
typedef  int __u32 ;

/* Variables and functions */
 unsigned long EXT4_APPEND_FL ; 
 unsigned long EXT4_IMMUTABLE_FL ; 
 unsigned long EXT4_NOATIME_FL ; 
 unsigned long EXT4_NODUMP_FL ; 
 unsigned long EXT4_PROJINHERIT_FL ; 
 unsigned long EXT4_SYNC_FL ; 
 int FS_XFLAG_APPEND ; 
 int FS_XFLAG_IMMUTABLE ; 
 int FS_XFLAG_NOATIME ; 
 int FS_XFLAG_NODUMP ; 
 int FS_XFLAG_PROJINHERIT ; 
 int FS_XFLAG_SYNC ; 

__attribute__((used)) static inline unsigned long ext4_xflags_to_iflags(__u32 xflags)
{
	unsigned long iflags = 0;

	if (xflags & FS_XFLAG_SYNC)
		iflags |= EXT4_SYNC_FL;
	if (xflags & FS_XFLAG_IMMUTABLE)
		iflags |= EXT4_IMMUTABLE_FL;
	if (xflags & FS_XFLAG_APPEND)
		iflags |= EXT4_APPEND_FL;
	if (xflags & FS_XFLAG_NODUMP)
		iflags |= EXT4_NODUMP_FL;
	if (xflags & FS_XFLAG_NOATIME)
		iflags |= EXT4_NOATIME_FL;
	if (xflags & FS_XFLAG_PROJINHERIT)
		iflags |= EXT4_PROJINHERIT_FL;

	return iflags;
}