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
typedef  int u_int ;
struct ahd_softc {int dummy; } ;

/* Variables and functions */
 int ahd_inb_scbram (struct ahd_softc*,int) ; 

u_int
ahd_inw_scbram(struct ahd_softc *ahd, u_int offset)
{
	return (ahd_inb_scbram(ahd, offset)
	      | (ahd_inb_scbram(ahd, offset+1) << 8));
}