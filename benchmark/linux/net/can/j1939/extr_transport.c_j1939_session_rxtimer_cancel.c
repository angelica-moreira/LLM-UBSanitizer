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
struct j1939_session {int /*<<< orphan*/  rxtimer; } ;

/* Variables and functions */
 scalar_t__ hrtimer_cancel (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  j1939_session_put (struct j1939_session*) ; 

__attribute__((used)) static void j1939_session_rxtimer_cancel(struct j1939_session *session)
{
	if (hrtimer_cancel(&session->rxtimer))
		j1939_session_put(session);
}