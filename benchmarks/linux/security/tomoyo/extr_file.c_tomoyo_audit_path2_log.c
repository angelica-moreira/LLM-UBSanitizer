#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {size_t operation; TYPE_2__* filename2; TYPE_1__* filename1; } ;
struct TYPE_8__ {TYPE_3__ path2; } ;
struct tomoyo_request_info {TYPE_4__ param; } ;
struct TYPE_6__ {int /*<<< orphan*/  name; } ;
struct TYPE_5__ {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int /*<<< orphan*/ * tomoyo_mac_keywords ; 
 size_t* tomoyo_pp2mac ; 
 int tomoyo_supervisor (struct tomoyo_request_info*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int tomoyo_audit_path2_log(struct tomoyo_request_info *r)
{
	return tomoyo_supervisor(r, "file %s %s %s\n", tomoyo_mac_keywords
				 [tomoyo_pp2mac[r->param.path2.operation]],
				 r->param.path2.filename1->name,
				 r->param.path2.filename2->name);
}