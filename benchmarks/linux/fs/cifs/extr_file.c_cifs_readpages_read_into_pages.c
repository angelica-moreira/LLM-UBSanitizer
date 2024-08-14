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
struct cifs_readdata {int dummy; } ;
struct TCP_Server_Info {int dummy; } ;

/* Variables and functions */
 int readpages_fill_pages (struct TCP_Server_Info*,struct cifs_readdata*,int /*<<< orphan*/ *,unsigned int) ; 

__attribute__((used)) static int
cifs_readpages_read_into_pages(struct TCP_Server_Info *server,
			       struct cifs_readdata *rdata, unsigned int len)
{
	return readpages_fill_pages(server, rdata, NULL, len);
}