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
typedef  int /*<<< orphan*/  u16 ;
struct nvkm_mxm {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/ * mxms_data (struct nvkm_mxm*) ; 

u16
mxms_structlen(struct nvkm_mxm *mxm)
{
	return *(u16 *)&mxms_data(mxm)[6];
}