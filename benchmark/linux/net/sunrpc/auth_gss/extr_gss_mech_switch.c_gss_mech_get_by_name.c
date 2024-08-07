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
struct gss_api_mech {int dummy; } ;

/* Variables and functions */
 struct gss_api_mech* _gss_mech_get_by_name (char const*) ; 
 int /*<<< orphan*/  request_module (char*,char const*) ; 

struct gss_api_mech * gss_mech_get_by_name(const char *name)
{
	struct gss_api_mech *gm = NULL;

	gm = _gss_mech_get_by_name(name);
	if (!gm) {
		request_module("rpc-auth-gss-%s", name);
		gm = _gss_mech_get_by_name(name);
	}
	return gm;
}