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
struct mid_q_entry {struct TCP_Server_Info* callback_data; } ;
struct cifs_credits {int value; int /*<<< orphan*/  instance; } ;
struct TCP_Server_Info {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CIFS_ECHO_OP ; 
 int /*<<< orphan*/  DeleteMidQEntry (struct mid_q_entry*) ; 
 int /*<<< orphan*/  add_credits (struct TCP_Server_Info*,struct cifs_credits*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
cifs_echo_callback(struct mid_q_entry *mid)
{
	struct TCP_Server_Info *server = mid->callback_data;
	struct cifs_credits credits = { .value = 1, .instance = 0 };

	DeleteMidQEntry(mid);
	add_credits(server, &credits, CIFS_ECHO_OP);
}