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
typedef  scalar_t__ u32 ;
struct nvkm_gpuobj {scalar_t__ map; } ;

/* Variables and functions */
 scalar_t__ ioread32_native (scalar_t__) ; 

__attribute__((used)) static u32
nvkm_gpuobj_rd32_fast(struct nvkm_gpuobj *gpuobj, u32 offset)
{
	return ioread32_native(gpuobj->map + offset);
}