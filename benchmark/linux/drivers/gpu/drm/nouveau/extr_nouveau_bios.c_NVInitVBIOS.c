#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  chip; int /*<<< orphan*/  major; } ;
struct nvkm_bios {scalar_t__ bmp_offset; scalar_t__ bit_offset; TYPE_2__ version; int /*<<< orphan*/  size; int /*<<< orphan*/  data; } ;
struct nvbios {scalar_t__ offset; int /*<<< orphan*/  type; int /*<<< orphan*/  chip_version; int /*<<< orphan*/  major_version; int /*<<< orphan*/  length; int /*<<< orphan*/  data; struct drm_device* dev; int /*<<< orphan*/  lock; } ;
struct TYPE_3__ {int /*<<< orphan*/  device; } ;
struct nouveau_drm {struct nvbios vbios; TYPE_1__ client; } ;
struct drm_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  NVBIOS_BIT ; 
 int /*<<< orphan*/  NVBIOS_BMP ; 
 int /*<<< orphan*/  memset (struct nvbios*,int /*<<< orphan*/ ,int) ; 
 struct nouveau_drm* nouveau_drm (struct drm_device*) ; 
 struct nvkm_bios* nvxx_bios (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  parse_bit_structure (struct nvbios*,scalar_t__) ; 
 int /*<<< orphan*/  parse_bmp_structure (struct drm_device*,struct nvbios*,scalar_t__) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 

__attribute__((used)) static bool NVInitVBIOS(struct drm_device *dev)
{
	struct nouveau_drm *drm = nouveau_drm(dev);
	struct nvkm_bios *bios = nvxx_bios(&drm->client.device);
	struct nvbios *legacy = &drm->vbios;

	memset(legacy, 0, sizeof(struct nvbios));
	spin_lock_init(&legacy->lock);
	legacy->dev = dev;

	legacy->data = bios->data;
	legacy->length = bios->size;
	legacy->major_version = bios->version.major;
	legacy->chip_version = bios->version.chip;
	if (bios->bit_offset) {
		legacy->type = NVBIOS_BIT;
		legacy->offset = bios->bit_offset;
		return !parse_bit_structure(legacy, legacy->offset + 6);
	} else
	if (bios->bmp_offset) {
		legacy->type = NVBIOS_BMP;
		legacy->offset = bios->bmp_offset;
		return !parse_bmp_structure(dev, legacy, legacy->offset);
	}

	return false;
}