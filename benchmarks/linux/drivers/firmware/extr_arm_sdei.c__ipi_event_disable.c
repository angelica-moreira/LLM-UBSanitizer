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
struct sdei_crosscall_args {TYPE_1__* event; } ;
struct TYPE_2__ {int /*<<< orphan*/  event_num; } ;

/* Variables and functions */
 int sdei_api_event_disable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sdei_cross_call_return (struct sdei_crosscall_args*,int) ; 

__attribute__((used)) static void _ipi_event_disable(void *data)
{
	int err;
	struct sdei_crosscall_args *arg = data;

	err = sdei_api_event_disable(arg->event->event_num);

	sdei_cross_call_return(arg, err);
}