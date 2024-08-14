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
 int nvbios_dp_table (struct nvkm_bios*,int*,int*,int*,int*) ; 
 int nvbios_rd08 (struct nvkm_bios*,int) ; 
 int nvbios_rd16 (struct nvkm_bios*,int) ; 

__attribute__((used)) static u16
nvbios_dpout_entry(struct nvkm_bios *bios, u8 idx,
		   u8 *ver, u8 *hdr, u8 *cnt, u8 *len)
{
	u16 data = nvbios_dp_table(bios, ver, hdr, cnt, len);
	if (data && idx < *cnt) {
		u16 outp = nvbios_rd16(bios, data + *hdr + idx * *len);
		switch (*ver * !!outp) {
		case 0x20:
		case 0x21:
		case 0x30:
			*hdr = nvbios_rd08(bios, data + 0x04);
			*len = nvbios_rd08(bios, data + 0x05);
			*cnt = nvbios_rd08(bios, outp + 0x04);
			break;
		case 0x40:
		case 0x41:
		case 0x42:
			*hdr = nvbios_rd08(bios, data + 0x04);
			*cnt = 0;
			*len = 0;
			break;
		default:
			break;
		}
		return outp;
	}
	*ver = 0x00;
	return 0x0000;
}