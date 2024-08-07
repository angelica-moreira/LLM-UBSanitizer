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
struct usbhs_priv {int dummy; } ;
struct usbhs_mod_info {struct usbhs_mod** mod; } ;
struct usbhs_mod {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 size_t USBHS_HOST ; 
 struct usbhs_mod* usbhs_mod_get_current (struct usbhs_priv*) ; 
 struct usbhs_mod_info* usbhs_priv_to_modinfo (struct usbhs_priv*) ; 

int usbhs_mod_is_host(struct usbhs_priv *priv)
{
	struct usbhs_mod *mod = usbhs_mod_get_current(priv);
	struct usbhs_mod_info *info = usbhs_priv_to_modinfo(priv);

	if (!mod)
		return -EINVAL;

	return info->mod[USBHS_HOST] == mod;
}