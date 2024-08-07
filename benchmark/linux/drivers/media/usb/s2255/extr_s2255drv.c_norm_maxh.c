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
struct s2255_vc {int std; } ;

/* Variables and functions */
 int NUM_LINES_1CIFS_NTSC ; 
 int NUM_LINES_1CIFS_PAL ; 
 int V4L2_STD_525_60 ; 

__attribute__((used)) static int norm_maxh(struct s2255_vc *vc)
{
	return (vc->std & V4L2_STD_525_60) ?
	    (NUM_LINES_1CIFS_NTSC * 2) : (NUM_LINES_1CIFS_PAL * 2);
}