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
struct kernel_param {int dummy; } ;

/* Variables and functions */
 int sprintf (char*,char*,char*) ; 
 char* uv_nmi_action ; 

__attribute__((used)) static int param_get_action(char *buffer, const struct kernel_param *kp)
{
	return sprintf(buffer, "%s\n", uv_nmi_action);
}