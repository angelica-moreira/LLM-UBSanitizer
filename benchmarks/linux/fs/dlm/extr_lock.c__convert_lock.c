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
struct dlm_rsb {int dummy; } ;
struct dlm_lkb {int dummy; } ;

/* Variables and functions */
 int do_convert (struct dlm_rsb*,struct dlm_lkb*) ; 
 int /*<<< orphan*/  do_convert_effects (struct dlm_rsb*,struct dlm_lkb*,int) ; 
 scalar_t__ is_remote (struct dlm_rsb*) ; 
 int send_convert (struct dlm_rsb*,struct dlm_lkb*) ; 

__attribute__((used)) static int _convert_lock(struct dlm_rsb *r, struct dlm_lkb *lkb)
{
	int error;

	if (is_remote(r)) {
		/* receive_convert() calls do_convert() on remote node */
		error = send_convert(r, lkb);
	} else {
		error = do_convert(r, lkb);
		/* for remote locks the convert_reply is sent
		   between do_convert and do_convert_effects */
		do_convert_effects(r, lkb, error);
	}

	return error;
}