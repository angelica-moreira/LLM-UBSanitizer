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
struct nvkm_disp {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  SOR ; 
 int nvkm_ior_new_ (int /*<<< orphan*/ *,struct nvkm_disp*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  tu102_sor ; 

int
tu102_sor_new(struct nvkm_disp *disp, int id)
{
	return nvkm_ior_new_(&tu102_sor, disp, SOR, id);
}