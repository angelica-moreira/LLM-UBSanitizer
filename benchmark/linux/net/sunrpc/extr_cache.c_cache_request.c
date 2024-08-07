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
struct cache_request {char* buf; int /*<<< orphan*/  item; } ;
struct cache_detail {int /*<<< orphan*/  (* cache_request ) (struct cache_detail*,int /*<<< orphan*/ ,char**,int*) ;} ;

/* Variables and functions */
 int EAGAIN ; 
 int PAGE_SIZE ; 
 int /*<<< orphan*/  stub1 (struct cache_detail*,int /*<<< orphan*/ ,char**,int*) ; 

__attribute__((used)) static int cache_request(struct cache_detail *detail,
			       struct cache_request *crq)
{
	char *bp = crq->buf;
	int len = PAGE_SIZE;

	detail->cache_request(detail, crq->item, &bp, &len);
	if (len < 0)
		return -EAGAIN;
	return PAGE_SIZE - len;
}