#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_3__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  (* remove_frontend ) (TYPE_1__*,int /*<<< orphan*/ *) ;} ;
struct TYPE_5__ {TYPE_1__ dmx; } ;
struct cx231xx_dvb {int /*<<< orphan*/ ** i2c_client_demod; int /*<<< orphan*/ * i2c_client_tuner; int /*<<< orphan*/  adapter; scalar_t__* frontend; TYPE_3__ demux; int /*<<< orphan*/  dmxdev; int /*<<< orphan*/  fe_hw; int /*<<< orphan*/  fe_mem; int /*<<< orphan*/  net; } ;

/* Variables and functions */
 int /*<<< orphan*/  dvb_dmx_release (TYPE_3__*) ; 
 int /*<<< orphan*/  dvb_dmxdev_release (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dvb_frontend_detach (scalar_t__) ; 
 int /*<<< orphan*/  dvb_module_release (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dvb_net_release (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dvb_unregister_adapter (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dvb_unregister_frontend (scalar_t__) ; 
 int /*<<< orphan*/  stub1 (TYPE_1__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub2 (TYPE_1__*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void unregister_dvb(struct cx231xx_dvb *dvb)
{
	dvb_net_release(&dvb->net);
	dvb->demux.dmx.remove_frontend(&dvb->demux.dmx, &dvb->fe_mem);
	dvb->demux.dmx.remove_frontend(&dvb->demux.dmx, &dvb->fe_hw);
	dvb_dmxdev_release(&dvb->dmxdev);
	dvb_dmx_release(&dvb->demux);
	if (dvb->frontend[1])
		dvb_unregister_frontend(dvb->frontend[1]);
	dvb_unregister_frontend(dvb->frontend[0]);
	if (dvb->frontend[1])
		dvb_frontend_detach(dvb->frontend[1]);
	dvb_frontend_detach(dvb->frontend[0]);
	dvb_unregister_adapter(&dvb->adapter);

	/* remove I2C tuner */
	dvb_module_release(dvb->i2c_client_tuner);
	dvb->i2c_client_tuner = NULL;
	/* remove I2C demod(s) */
	dvb_module_release(dvb->i2c_client_demod[1]);
	dvb->i2c_client_demod[1] = NULL;
	dvb_module_release(dvb->i2c_client_demod[0]);
	dvb->i2c_client_demod[0] = NULL;
}