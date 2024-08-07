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
typedef  void u8 ;
typedef  int /*<<< orphan*/  u32 ;

/* Variables and functions */
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,void*,int) ; 

__attribute__((used)) static u8 *ecrdsa_unpack_u32(u32 *dst, void *src)
{
	memcpy(dst, src, sizeof(u32));
	return src + sizeof(u32);
}