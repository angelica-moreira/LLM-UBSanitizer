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
struct recv_frame {int dummy; } ;
struct adapter {int dummy; } ;

/* Variables and functions */
 unsigned int _SUCCESS ; 

__attribute__((used)) static unsigned int OnAction_qos(struct adapter *padapter,
				 struct recv_frame *precv_frame)
{
	return _SUCCESS;
}