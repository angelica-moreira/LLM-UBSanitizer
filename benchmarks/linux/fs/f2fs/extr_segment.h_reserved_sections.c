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
struct f2fs_sb_info {int dummy; } ;

/* Variables and functions */
 int GET_SEC_FROM_SEG (struct f2fs_sb_info*,unsigned int) ; 
 scalar_t__ reserved_segments (struct f2fs_sb_info*) ; 

__attribute__((used)) static inline int reserved_sections(struct f2fs_sb_info *sbi)
{
	return GET_SEC_FROM_SEG(sbi, (unsigned int)reserved_segments(sbi));
}