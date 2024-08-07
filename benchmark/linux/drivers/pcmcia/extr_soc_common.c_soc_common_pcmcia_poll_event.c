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
struct timer_list {int dummy; } ;
struct soc_pcmcia_socket {int /*<<< orphan*/  poll_timer; } ;

/* Variables and functions */
 scalar_t__ SOC_PCMCIA_POLL_PERIOD ; 
 int /*<<< orphan*/  debug (struct soc_pcmcia_socket*,int,char*) ; 
 struct soc_pcmcia_socket* from_timer (int /*<<< orphan*/ ,struct timer_list*,int /*<<< orphan*/ ) ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  mod_timer (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  poll_timer ; 
 struct soc_pcmcia_socket* skt ; 
 int /*<<< orphan*/  soc_common_check_status (struct soc_pcmcia_socket*) ; 

__attribute__((used)) static void soc_common_pcmcia_poll_event(struct timer_list *t)
{
	struct soc_pcmcia_socket *skt = from_timer(skt, t, poll_timer);
	debug(skt, 4, "polling for events\n");

	mod_timer(&skt->poll_timer, jiffies + SOC_PCMCIA_POLL_PERIOD);

	soc_common_check_status(skt);
}