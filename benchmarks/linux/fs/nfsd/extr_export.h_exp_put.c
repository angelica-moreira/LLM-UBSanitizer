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
struct svc_export {int /*<<< orphan*/  cd; int /*<<< orphan*/  h; } ;

/* Variables and functions */
 int /*<<< orphan*/  cache_put (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void exp_put(struct svc_export *exp)
{
	cache_put(&exp->h, exp->cd);
}