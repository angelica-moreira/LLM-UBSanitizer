#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {scalar_t__ port_tts; } ;

/* Variables and functions */
 scalar_t__ UART_RX ; 
 float inb_p (scalar_t__) ; 
 TYPE_1__ speakup_info ; 

__attribute__((used)) static inline bool synth_full(void)
{
	return inb_p(speakup_info.port_tts + UART_RX) == 'F';
}