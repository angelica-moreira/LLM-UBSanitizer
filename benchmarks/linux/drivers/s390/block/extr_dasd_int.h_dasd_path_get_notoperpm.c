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
struct dasd_device {int dummy; } ;
typedef  int __u8 ;

/* Variables and functions */
 scalar_t__ dasd_path_is_cuir (struct dasd_device*,int) ; 
 scalar_t__ dasd_path_is_ifcc (struct dasd_device*,int) ; 
 scalar_t__ dasd_path_is_miscabled (struct dasd_device*,int) ; 
 scalar_t__ dasd_path_is_nohpf (struct dasd_device*,int) ; 

__attribute__((used)) static inline __u8 dasd_path_get_notoperpm(struct dasd_device *device)
{
	int chp;
	__u8 nopm = 0x00;

	for (chp = 0; chp < 8; chp++)
		if (dasd_path_is_nohpf(device, chp) ||
		    dasd_path_is_ifcc(device, chp) ||
		    dasd_path_is_cuir(device, chp) ||
		    dasd_path_is_miscabled(device, chp))
			nopm |= 0x80 >> chp;
	return nopm;
}