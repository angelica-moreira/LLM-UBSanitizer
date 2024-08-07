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
typedef  scalar_t__ u8 ;

/* Variables and functions */
 int ARRAY_SIZE (scalar_t__*) ; 
 scalar_t__* digital_payload_bits_map ; 

__attribute__((used)) static u8 digital_payload_size_to_bits(u8 payload_size)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(digital_payload_bits_map); i++)
		if (digital_payload_bits_map[i] == payload_size)
			return i;

	return 0xff;
}