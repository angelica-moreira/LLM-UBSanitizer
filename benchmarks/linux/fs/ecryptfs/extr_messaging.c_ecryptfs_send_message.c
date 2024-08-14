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
struct ecryptfs_msg_ctx {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ECRYPTFS_MSG_REQUEST ; 
 int /*<<< orphan*/  ecryptfs_daemon_hash_mux ; 
 int ecryptfs_send_message_locked (char*,int,int /*<<< orphan*/ ,struct ecryptfs_msg_ctx**) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

int ecryptfs_send_message(char *data, int data_len,
			  struct ecryptfs_msg_ctx **msg_ctx)
{
	int rc;

	mutex_lock(&ecryptfs_daemon_hash_mux);
	rc = ecryptfs_send_message_locked(data, data_len, ECRYPTFS_MSG_REQUEST,
					  msg_ctx);
	mutex_unlock(&ecryptfs_daemon_hash_mux);
	return rc;
}