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
struct rate_control_ops {int dummy; } ;

/* Variables and functions */
 char const* CONFIG_MAC80211_RC_DEFAULT ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 char const* ieee80211_default_rc_algo ; 
 struct rate_control_ops* ieee80211_try_rate_control_ops_get (char const*) ; 
 int /*<<< orphan*/  kernel_param_lock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kernel_param_unlock (int /*<<< orphan*/ ) ; 
 scalar_t__ strlen (char const*) ; 

__attribute__((used)) static const struct rate_control_ops *
ieee80211_rate_control_ops_get(const char *name)
{
	const struct rate_control_ops *ops;
	const char *alg_name;

	kernel_param_lock(THIS_MODULE);
	if (!name)
		alg_name = ieee80211_default_rc_algo;
	else
		alg_name = name;

	ops = ieee80211_try_rate_control_ops_get(alg_name);
	if (!ops && name)
		/* try default if specific alg requested but not found */
		ops = ieee80211_try_rate_control_ops_get(ieee80211_default_rc_algo);

	/* Note: check for > 0 is intentional to avoid clang warning */
	if (!ops && (strlen(CONFIG_MAC80211_RC_DEFAULT) > 0))
		/* try built-in one if specific alg requested but not found */
		ops = ieee80211_try_rate_control_ops_get(CONFIG_MAC80211_RC_DEFAULT);

	kernel_param_unlock(THIS_MODULE);

	return ops;
}