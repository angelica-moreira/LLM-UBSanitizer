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
typedef  int /*<<< orphan*/  u64 ;
struct nvkm_vmm_page {TYPE_1__* desc; } ;
struct nvkm_vmm_desc_func {scalar_t__ unmap; scalar_t__ invalid; scalar_t__ sparse; } ;
struct nvkm_vmm {int dummy; } ;
struct TYPE_2__ {struct nvkm_vmm_desc_func* func; } ;

/* Variables and functions */
 int /*<<< orphan*/  nvkm_vmm_iter (struct nvkm_vmm*,struct nvkm_vmm_page const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,int,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,scalar_t__) ; 

__attribute__((used)) static void
nvkm_vmm_ptes_unmap(struct nvkm_vmm *vmm, const struct nvkm_vmm_page *page,
		    u64 addr, u64 size, bool sparse, bool pfn)
{
	const struct nvkm_vmm_desc_func *func = page->desc->func;
	nvkm_vmm_iter(vmm, page, addr, size, "unmap", false, pfn,
		      NULL, NULL, NULL,
		      sparse ? func->sparse : func->invalid ? func->invalid :
							      func->unmap);
}