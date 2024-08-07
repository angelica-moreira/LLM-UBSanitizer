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
struct nfs3_createdata {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct nfs3_createdata*) ; 

__attribute__((used)) static void nfs3_free_createdata(struct nfs3_createdata *data)
{
	kfree(data);
}