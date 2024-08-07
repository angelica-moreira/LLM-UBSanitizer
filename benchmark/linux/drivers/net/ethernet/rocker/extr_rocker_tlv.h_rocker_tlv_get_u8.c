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
typedef  int /*<<< orphan*/  u8 ;
struct rocker_tlv {int dummy; } ;

/* Variables and functions */
 scalar_t__ rocker_tlv_data (struct rocker_tlv const*) ; 

__attribute__((used)) static inline u8 rocker_tlv_get_u8(const struct rocker_tlv *tlv)
{
	return *(u8 *) rocker_tlv_data(tlv);
}