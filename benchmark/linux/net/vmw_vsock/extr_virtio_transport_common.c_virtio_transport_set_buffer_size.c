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
typedef  scalar_t__ u64 ;
struct vsock_sock {struct virtio_vsock_sock* trans; } ;
struct virtio_vsock_sock {scalar_t__ buf_size_min; scalar_t__ buf_size_max; scalar_t__ buf_alloc; scalar_t__ buf_size; } ;

/* Variables and functions */
 scalar_t__ VIRTIO_VSOCK_MAX_BUF_SIZE ; 
 int /*<<< orphan*/  VIRTIO_VSOCK_TYPE_STREAM ; 
 int /*<<< orphan*/  virtio_transport_send_credit_update (struct vsock_sock*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

void virtio_transport_set_buffer_size(struct vsock_sock *vsk, u64 val)
{
	struct virtio_vsock_sock *vvs = vsk->trans;

	if (val > VIRTIO_VSOCK_MAX_BUF_SIZE)
		val = VIRTIO_VSOCK_MAX_BUF_SIZE;
	if (val < vvs->buf_size_min)
		vvs->buf_size_min = val;
	if (val > vvs->buf_size_max)
		vvs->buf_size_max = val;
	vvs->buf_size = val;
	vvs->buf_alloc = val;

	virtio_transport_send_credit_update(vsk, VIRTIO_VSOCK_TYPE_STREAM,
					    NULL);
}