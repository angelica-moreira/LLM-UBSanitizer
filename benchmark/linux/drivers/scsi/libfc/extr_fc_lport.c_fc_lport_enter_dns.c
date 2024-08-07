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
struct fc_rport_priv {int /*<<< orphan*/ * ops; } ;
struct TYPE_2__ {int /*<<< orphan*/  disc_mutex; } ;
struct fc_lport {TYPE_1__ disc; int /*<<< orphan*/  lp_mutex; } ;

/* Variables and functions */
 int /*<<< orphan*/  FC_FID_DIR_SERV ; 
 int /*<<< orphan*/  FC_LPORT_DBG (struct fc_lport*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LPORT_ST_DNS ; 
 int /*<<< orphan*/  fc_lport_error (struct fc_lport*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  fc_lport_rport_ops ; 
 int /*<<< orphan*/  fc_lport_state (struct fc_lport*) ; 
 int /*<<< orphan*/  fc_lport_state_enter (struct fc_lport*,int /*<<< orphan*/ ) ; 
 struct fc_rport_priv* fc_rport_create (struct fc_lport*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fc_rport_login (struct fc_rport_priv*) ; 
 int /*<<< orphan*/  lockdep_assert_held (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void fc_lport_enter_dns(struct fc_lport *lport)
{
	struct fc_rport_priv *rdata;

	lockdep_assert_held(&lport->lp_mutex);

	FC_LPORT_DBG(lport, "Entered DNS state from %s state\n",
		     fc_lport_state(lport));

	fc_lport_state_enter(lport, LPORT_ST_DNS);

	mutex_lock(&lport->disc.disc_mutex);
	rdata = fc_rport_create(lport, FC_FID_DIR_SERV);
	mutex_unlock(&lport->disc.disc_mutex);
	if (!rdata)
		goto err;

	rdata->ops = &fc_lport_rport_ops;
	fc_rport_login(rdata);
	return;

err:
	fc_lport_error(lport, NULL);
}