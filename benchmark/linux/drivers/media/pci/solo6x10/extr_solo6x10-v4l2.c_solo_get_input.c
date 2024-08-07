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
struct solo_dev {unsigned int cur_disp_ch; } ;
struct file {int dummy; } ;

/* Variables and functions */
 struct solo_dev* video_drvdata (struct file*) ; 

__attribute__((used)) static int solo_get_input(struct file *file, void *priv, unsigned int *index)
{
	struct solo_dev *solo_dev = video_drvdata(file);

	*index = solo_dev->cur_disp_ch;

	return 0;
}