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
struct hid_device {int dummy; } ;
typedef  int __u8 ;

/* Variables and functions */
 int /*<<< orphan*/  samsung_irda_dev_trace (struct hid_device*,int) ; 

__attribute__((used)) static __u8 *samsung_irda_report_fixup(struct hid_device *hdev, __u8 *rdesc,
		unsigned int *rsize)
{
	if (*rsize == 184 && rdesc[175] == 0x25 && rdesc[176] == 0x40 &&
			rdesc[177] == 0x75 && rdesc[178] == 0x30 &&
			rdesc[179] == 0x95 && rdesc[180] == 0x01 &&
			rdesc[182] == 0x40) {
		samsung_irda_dev_trace(hdev, 184);
		rdesc[176] = 0xff;
		rdesc[178] = 0x08;
		rdesc[180] = 0x06;
		rdesc[182] = 0x42;
	} else
	if (*rsize == 203 && rdesc[192] == 0x15 && rdesc[193] == 0x0 &&
			rdesc[194] == 0x25 && rdesc[195] == 0x12) {
		samsung_irda_dev_trace(hdev, 203);
		rdesc[193] = 0x1;
		rdesc[195] = 0xf;
	} else
	if (*rsize == 135 && rdesc[124] == 0x15 && rdesc[125] == 0x0 &&
			rdesc[126] == 0x25 && rdesc[127] == 0x11) {
		samsung_irda_dev_trace(hdev, 135);
		rdesc[125] = 0x1;
		rdesc[127] = 0xe;
	} else
	if (*rsize == 171 && rdesc[160] == 0x15 && rdesc[161] == 0x0 &&
			rdesc[162] == 0x25 && rdesc[163] == 0x01) {
		samsung_irda_dev_trace(hdev, 171);
		rdesc[161] = 0x1;
		rdesc[163] = 0x3;
	}
	return rdesc;
}