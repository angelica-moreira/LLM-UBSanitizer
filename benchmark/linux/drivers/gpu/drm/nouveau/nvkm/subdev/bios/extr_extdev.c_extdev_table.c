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
typedef  int u8 ;
typedef  int u16 ;
struct nvkm_bios {int dummy; } ;

/* Variables and functions */
 int dcb_table (struct nvkm_bios*,int*,int*,int*,int*) ; 
 int nvbios_rd08 (struct nvkm_bios*,int) ; 
 int nvbios_rd16 (struct nvkm_bios*,int) ; 

__attribute__((used)) static u16
extdev_table(struct nvkm_bios *bios, u8 *ver, u8 *hdr, u8 *len, u8 *cnt)
{
	u8  dcb_ver, dcb_hdr, dcb_cnt, dcb_len;
	u16 dcb, extdev = 0;

	dcb = dcb_table(bios, &dcb_ver, &dcb_hdr, &dcb_cnt, &dcb_len);
	if (!dcb || (dcb_ver != 0x30 && dcb_ver != 0x40 && dcb_ver != 0x41))
		return 0x0000;

	extdev = nvbios_rd16(bios, dcb + 18);
	if (!extdev)
		return 0x0000;

	*ver = nvbios_rd08(bios, extdev + 0);
	*hdr = nvbios_rd08(bios, extdev + 1);
	*cnt = nvbios_rd08(bios, extdev + 2);
	*len = nvbios_rd08(bios, extdev + 3);
	return extdev + *hdr;
}