#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
struct nvif_object {int dummy; } ;
struct drm_device {int dummy; } ;
struct TYPE_4__ {struct nvif_object object; } ;
struct TYPE_5__ {TYPE_1__ device; } ;
struct TYPE_6__ {TYPE_2__ client; } ;

/* Variables and functions */
 scalar_t__ NV_PRMCIO_CRX__COLOR ; 
 scalar_t__ NV_PRMCIO_CR__COLOR ; 
 int NV_PRMCIO_SIZE ; 
 TYPE_3__* nouveau_drm (struct drm_device*) ; 
 int /*<<< orphan*/  nvif_rd08 (struct nvif_object*,scalar_t__) ; 
 int /*<<< orphan*/  nvif_wr08 (struct nvif_object*,scalar_t__,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline uint8_t NVReadVgaCrtc(struct drm_device *dev,
					int head, uint8_t index)
{
	struct nvif_object *device = &nouveau_drm(dev)->client.device.object;
	uint8_t val;
	nvif_wr08(device, NV_PRMCIO_CRX__COLOR + head * NV_PRMCIO_SIZE, index);
	val = nvif_rd08(device, NV_PRMCIO_CR__COLOR + head * NV_PRMCIO_SIZE);
	return val;
}