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
typedef  int /*<<< orphan*/  u16 ;
struct v4l2_sliced_vbi_format {int /*<<< orphan*/ ** service_lines; } ;

/* Variables and functions */
 int /*<<< orphan*/  select_service_from_set (int,int,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int check_service_set(struct v4l2_sliced_vbi_format *fmt, int is_pal)
{
	int f, l;
	u16 set = 0;

	for (f = 0; f < 2; f++) {
		for (l = 0; l < 24; l++) {
			fmt->service_lines[f][l] = select_service_from_set(f, l, fmt->service_lines[f][l], is_pal);
			set |= fmt->service_lines[f][l];
		}
	}
	return set != 0;
}