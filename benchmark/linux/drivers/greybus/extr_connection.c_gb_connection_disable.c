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
struct gb_connection {scalar_t__ state; int /*<<< orphan*/  mutex; int /*<<< orphan*/  mode_switch; int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  ESHUTDOWN ; 
 scalar_t__ GB_CONNECTION_STATE_DISABLED ; 
 scalar_t__ GB_CONNECTION_STATE_DISCONNECTING ; 
 int /*<<< orphan*/  gb_connection_cancel_operations (struct gb_connection*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gb_connection_control_disconnected (struct gb_connection*) ; 
 int /*<<< orphan*/  gb_connection_control_disconnecting (struct gb_connection*) ; 
 int /*<<< orphan*/  gb_connection_cport_shutdown_phase_1 (struct gb_connection*) ; 
 int /*<<< orphan*/  gb_connection_cport_shutdown_phase_2 (struct gb_connection*) ; 
 int /*<<< orphan*/  gb_connection_hd_cport_clear (struct gb_connection*) ; 
 int /*<<< orphan*/  gb_connection_hd_cport_disable (struct gb_connection*) ; 
 int /*<<< orphan*/  gb_connection_hd_cport_flush (struct gb_connection*) ; 
 int /*<<< orphan*/  gb_connection_hd_cport_quiesce (struct gb_connection*) ; 
 int /*<<< orphan*/  gb_connection_svc_connection_destroy (struct gb_connection*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  trace_gb_connection_disable (struct gb_connection*) ; 

void gb_connection_disable(struct gb_connection *connection)
{
	mutex_lock(&connection->mutex);

	if (connection->state == GB_CONNECTION_STATE_DISABLED)
		goto out_unlock;

	trace_gb_connection_disable(connection);

	spin_lock_irq(&connection->lock);
	connection->state = GB_CONNECTION_STATE_DISCONNECTING;
	gb_connection_cancel_operations(connection, -ESHUTDOWN);
	spin_unlock_irq(&connection->lock);

	gb_connection_hd_cport_flush(connection);

	gb_connection_control_disconnecting(connection);
	gb_connection_cport_shutdown_phase_1(connection);
	gb_connection_hd_cport_quiesce(connection);
	gb_connection_cport_shutdown_phase_2(connection);
	gb_connection_control_disconnected(connection);

	connection->state = GB_CONNECTION_STATE_DISABLED;

	/* control-connection tear down is deferred when mode switching */
	if (!connection->mode_switch) {
		gb_connection_svc_connection_destroy(connection);
		gb_connection_hd_cport_clear(connection);

		gb_connection_hd_cport_disable(connection);
	}

out_unlock:
	mutex_unlock(&connection->mutex);
}