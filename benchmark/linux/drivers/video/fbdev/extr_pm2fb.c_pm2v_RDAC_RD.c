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
typedef  int /*<<< orphan*/  u32 ;
struct pm2fb_par {int dummy; } ;
typedef  int s32 ;

/* Variables and functions */
 int /*<<< orphan*/  PM2VR_RD_INDEXED_DATA ; 
 int /*<<< orphan*/  PM2VR_RD_INDEX_LOW ; 
 int /*<<< orphan*/  mb () ; 
 int /*<<< orphan*/  pm2_RD (struct pm2fb_par*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pm2_WR (struct pm2fb_par*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline u32 pm2v_RDAC_RD(struct pm2fb_par *p, s32 idx)
{
	pm2_WR(p, PM2VR_RD_INDEX_LOW, idx & 0xff);
	mb();
	return pm2_RD(p,  PM2VR_RD_INDEXED_DATA);
}