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
struct nfp_app {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct nfp_app*) ; 

void nfp_app_free(struct nfp_app *app)
{
	kfree(app);
}