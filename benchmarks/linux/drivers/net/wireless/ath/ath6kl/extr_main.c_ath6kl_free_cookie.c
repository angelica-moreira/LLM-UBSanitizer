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
struct ath6kl_cookie {struct ath6kl_cookie* arc_list_next; } ;
struct ath6kl {int /*<<< orphan*/  cookie_count; struct ath6kl_cookie* cookie_list; } ;

/* Variables and functions */

void ath6kl_free_cookie(struct ath6kl *ar, struct ath6kl_cookie *cookie)
{
	/* Insert first */

	if (!ar || !cookie)
		return;

	cookie->arc_list_next = ar->cookie_list;
	ar->cookie_list = cookie;
	ar->cookie_count++;
}