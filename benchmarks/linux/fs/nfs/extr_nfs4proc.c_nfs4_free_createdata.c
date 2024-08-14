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
struct nfs4_createdata {int /*<<< orphan*/  label; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct nfs4_createdata*) ; 
 int /*<<< orphan*/  nfs4_label_free (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void nfs4_free_createdata(struct nfs4_createdata *data)
{
	nfs4_label_free(data->label);
	kfree(data);
}