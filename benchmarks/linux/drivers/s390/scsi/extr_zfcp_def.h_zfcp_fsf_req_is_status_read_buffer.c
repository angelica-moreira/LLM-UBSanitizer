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
struct zfcp_fsf_req {int /*<<< orphan*/ * qtcb; } ;

/* Variables and functions */

__attribute__((used)) static inline bool zfcp_fsf_req_is_status_read_buffer(struct zfcp_fsf_req *req)
{
	return req->qtcb == NULL;
}