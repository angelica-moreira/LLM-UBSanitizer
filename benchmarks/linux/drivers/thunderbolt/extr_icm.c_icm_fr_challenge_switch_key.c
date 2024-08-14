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
typedef  int /*<<< orphan*/  u8 ;
struct tb_switch {int /*<<< orphan*/  connection_key; int /*<<< orphan*/  connection_id; int /*<<< orphan*/  const* uuid; } ;
struct tb {int dummy; } ;
struct TYPE_2__ {int flags; int /*<<< orphan*/  code; } ;
struct icm_fr_pkg_challenge_device_response {int /*<<< orphan*/  const* response; TYPE_1__ hdr; int /*<<< orphan*/ * challenge; int /*<<< orphan*/  connection_key; int /*<<< orphan*/  connection_id; int /*<<< orphan*/  ep_uuid; } ;
struct icm_fr_pkg_challenge_device {int /*<<< orphan*/  const* response; TYPE_1__ hdr; int /*<<< orphan*/ * challenge; int /*<<< orphan*/  connection_key; int /*<<< orphan*/  connection_id; int /*<<< orphan*/  ep_uuid; } ;
typedef  int /*<<< orphan*/  request ;
typedef  int /*<<< orphan*/  reply ;

/* Variables and functions */
 int EKEYREJECTED ; 
 int ENOKEY ; 
 int /*<<< orphan*/  ICM_CHALLENGE_DEVICE ; 
 int ICM_FLAGS_ERROR ; 
 int ICM_FLAGS_NO_KEY ; 
 int /*<<< orphan*/  ICM_TIMEOUT ; 
 int TB_SWITCH_KEY_SIZE ; 
 int icm_request (struct tb*,struct icm_fr_pkg_challenge_device_response*,int,struct icm_fr_pkg_challenge_device_response*,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int) ; 
 int /*<<< orphan*/  memset (struct icm_fr_pkg_challenge_device_response*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int icm_fr_challenge_switch_key(struct tb *tb, struct tb_switch *sw,
				       const u8 *challenge, u8 *response)
{
	struct icm_fr_pkg_challenge_device request;
	struct icm_fr_pkg_challenge_device_response reply;
	int ret;

	memset(&request, 0, sizeof(request));
	memcpy(&request.ep_uuid, sw->uuid, sizeof(request.ep_uuid));
	request.hdr.code = ICM_CHALLENGE_DEVICE;
	request.connection_id = sw->connection_id;
	request.connection_key = sw->connection_key;
	memcpy(request.challenge, challenge, TB_SWITCH_KEY_SIZE);

	memset(&reply, 0, sizeof(reply));
	ret = icm_request(tb, &request, sizeof(request), &reply, sizeof(reply),
			  1, ICM_TIMEOUT);
	if (ret)
		return ret;

	if (reply.hdr.flags & ICM_FLAGS_ERROR)
		return -EKEYREJECTED;
	if (reply.hdr.flags & ICM_FLAGS_NO_KEY)
		return -ENOKEY;

	memcpy(response, reply.response, TB_SWITCH_KEY_SIZE);

	return 0;
}