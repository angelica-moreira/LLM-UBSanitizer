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
typedef  int /*<<< orphan*/  uint32_t ;
struct scb {int /*<<< orphan*/  sense_busaddr; } ;
struct ahd_softc {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static inline uint32_t
ahd_get_sense_bufaddr(struct ahd_softc *ahd, struct scb *scb)
{
	return (scb->sense_busaddr);
}