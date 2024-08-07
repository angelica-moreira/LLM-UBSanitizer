#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {void* data_size; } ;
struct TYPE_5__ {void* data_size; } ;
struct mvpp2_tx_desc {TYPE_3__ pp22; TYPE_2__ pp21; } ;
struct mvpp2_port {TYPE_1__* priv; } ;
struct TYPE_4__ {scalar_t__ hw_version; } ;

/* Variables and functions */
 scalar_t__ MVPP21 ; 
 void* cpu_to_le16 (size_t) ; 

__attribute__((used)) static void mvpp2_txdesc_size_set(struct mvpp2_port *port,
				  struct mvpp2_tx_desc *tx_desc,
				  size_t size)
{
	if (port->priv->hw_version == MVPP21)
		tx_desc->pp21.data_size = cpu_to_le16(size);
	else
		tx_desc->pp22.data_size = cpu_to_le16(size);
}