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
struct sockaddr_vm {int dummy; } ;
typedef  int /*<<< orphan*/  guid_t ;

/* Variables and functions */
 int /*<<< orphan*/  VMADDR_CID_ANY ; 
 unsigned int get_port_by_srv_id (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  vsock_addr_init (struct sockaddr_vm*,int /*<<< orphan*/ ,unsigned int) ; 

__attribute__((used)) static void hvs_addr_init(struct sockaddr_vm *addr, const guid_t *svr_id)
{
	unsigned int port = get_port_by_srv_id(svr_id);

	vsock_addr_init(addr, VMADDR_CID_ANY, port);
}