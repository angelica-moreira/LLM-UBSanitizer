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
struct gspca_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  snd_val (struct gspca_dev*,int,int) ; 

__attribute__((used)) static void set_par(struct gspca_dev *gspca_dev,
		   int parval)
{
	snd_val(gspca_dev, 0x003f08, parval);
}