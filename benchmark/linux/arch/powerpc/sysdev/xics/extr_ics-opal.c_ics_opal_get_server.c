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
struct ics {int dummy; } ;
typedef  int /*<<< orphan*/  int8_t ;
typedef  scalar_t__ int64_t ;
typedef  int /*<<< orphan*/  __be16 ;

/* Variables and functions */
 scalar_t__ OPAL_SUCCESS ; 
 int /*<<< orphan*/  be16_to_cpu (int /*<<< orphan*/ ) ; 
 long ics_opal_unmangle_server (int /*<<< orphan*/ ) ; 
 scalar_t__ opal_get_xive (unsigned long,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static long ics_opal_get_server(struct ics *ics, unsigned long vec)
{
	int64_t rc;
	__be16 server;
	int8_t priority;

	/* Check if HAL knows about this interrupt */
	rc = opal_get_xive(vec, &server, &priority);
	if (rc != OPAL_SUCCESS)
		return -1;
	return ics_opal_unmangle_server(be16_to_cpu(server));
}