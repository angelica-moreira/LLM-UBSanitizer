#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct intel_guc_client {scalar_t__ doorbell_id; TYPE_1__* guc; } ;
struct TYPE_2__ {int /*<<< orphan*/  doorbell_bitmap; } ;

/* Variables and functions */
 scalar_t__ GUC_DOORBELL_INVALID ; 
 int test_bit (scalar_t__,int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool has_doorbell(struct intel_guc_client *client)
{
	if (client->doorbell_id == GUC_DOORBELL_INVALID)
		return false;

	return test_bit(client->doorbell_id, client->guc->doorbell_bitmap);
}