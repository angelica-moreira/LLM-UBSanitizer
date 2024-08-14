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
struct adb_request {int /*<<< orphan*/  complete; } ;

/* Variables and functions */
 int /*<<< orphan*/  CUDA_GET_SET_IIC ; 
 int /*<<< orphan*/  CUDA_PACKET ; 
 int /*<<< orphan*/  cuda_poll () ; 
 int /*<<< orphan*/  cuda_request (struct adb_request*,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,unsigned char) ; 

__attribute__((used)) static void set_control_clock(unsigned char *params)
{
#ifdef CONFIG_ADB_CUDA
	struct adb_request req;
	int i;

	for (i = 0; i < 3; ++i) {
		cuda_request(&req, NULL, 5, CUDA_PACKET, CUDA_GET_SET_IIC,
			     0x50, i + 1, params[i]);
		while (!req.complete)
			cuda_poll();
	}
#endif	
}