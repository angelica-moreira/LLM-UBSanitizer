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
struct ahd_softc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  INTSTAT ; 
 int /*<<< orphan*/  ahd_inb (struct ahd_softc*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void
ahd_flush_device_writes(struct ahd_softc *ahd)
{
	/* XXX Is this sufficient for all architectures??? */
	ahd_inb(ahd, INTSTAT);
}