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
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct rio_mport {int /*<<< orphan*/  sys_size; } ;

/* Variables and functions */
 int /*<<< orphan*/  RIO_DID_CSR ; 
 int /*<<< orphan*/  RIO_GET_DID (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rio_local_read_config_32 (struct rio_mport*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

u16 rio_local_get_device_id(struct rio_mport *port)
{
	u32 result;

	rio_local_read_config_32(port, RIO_DID_CSR, &result);

	return (RIO_GET_DID(port->sys_size, result));
}