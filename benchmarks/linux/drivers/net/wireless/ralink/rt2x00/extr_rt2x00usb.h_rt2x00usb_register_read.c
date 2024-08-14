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
struct rt2x00_dev {int dummy; } ;
typedef  int /*<<< orphan*/  reg ;
typedef  int /*<<< orphan*/  __le32 ;

/* Variables and functions */
 int /*<<< orphan*/  USB_MULTI_READ ; 
 int /*<<< orphan*/  USB_VENDOR_REQUEST_IN ; 
 int /*<<< orphan*/  le32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rt2x00usb_vendor_request_buff (struct rt2x00_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int const,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static inline u32 rt2x00usb_register_read(struct rt2x00_dev *rt2x00dev,
					  const unsigned int offset)
{
	__le32 reg = 0;
	rt2x00usb_vendor_request_buff(rt2x00dev, USB_MULTI_READ,
				      USB_VENDOR_REQUEST_IN, offset,
				      &reg, sizeof(reg));
	return le32_to_cpu(reg);
}