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
struct dso {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int /*<<< orphan*/  dso__put (struct dso*) ; 
 struct dso** dsos ; 
 int /*<<< orphan*/  free (struct dso**) ; 
 int /*<<< orphan*/  unlink (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void dsos__delete(int cnt)
{
	int i;

	for (i = 0; i < cnt; i++) {
		struct dso *dso = dsos[i];

		unlink(dso->name);
		dso__put(dso);
	}

	free(dsos);
}