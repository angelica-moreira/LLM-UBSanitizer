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
struct sockaddr_in {int /*<<< orphan*/  sin_addr; } ;
struct sockaddr {int dummy; } ;

/* Variables and functions */
 int snprintf (char*,size_t const,char*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int rpc_ntop4(const struct sockaddr *sap,
		     char *buf, const size_t buflen)
{
	const struct sockaddr_in *sin = (struct sockaddr_in *)sap;

	return snprintf(buf, buflen, "%pI4", &sin->sin_addr);
}