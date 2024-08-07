#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  dmacon; TYPE_1__* aud; } ;
struct TYPE_3__ {scalar_t__ audvol; } ;

/* Variables and functions */
 int /*<<< orphan*/  AMI_AUDIO_OFF ; 
 TYPE_2__ custom ; 
 int /*<<< orphan*/  enable_heartbeat () ; 

__attribute__((used)) static inline void StopDMA(void)
{
	custom.aud[0].audvol = custom.aud[1].audvol = 0;
	custom.aud[2].audvol = custom.aud[3].audvol = 0;
	custom.dmacon = AMI_AUDIO_OFF;
	enable_heartbeat();
}