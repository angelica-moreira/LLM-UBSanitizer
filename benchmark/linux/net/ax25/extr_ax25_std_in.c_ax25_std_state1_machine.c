#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
struct sk_buff {int dummy; } ;
struct TYPE_15__ {void* modulus; TYPE_1__* ax25_dev; int /*<<< orphan*/  window; TYPE_3__* sk; int /*<<< orphan*/  n2count; int /*<<< orphan*/  state; int /*<<< orphan*/  vr; int /*<<< orphan*/  va; int /*<<< orphan*/  vs; } ;
typedef  TYPE_2__ ax25_cb ;
struct TYPE_16__ {int /*<<< orphan*/  (* sk_state_change ) (TYPE_3__*) ;int /*<<< orphan*/  sk_state; } ;
struct TYPE_14__ {int /*<<< orphan*/ * values; } ;

/* Variables and functions */
#define  AX25_DISC 132 
#define  AX25_DM 131 
 void* AX25_EMODULUS ; 
 void* AX25_MODULUS ; 
 int /*<<< orphan*/  AX25_RESPONSE ; 
#define  AX25_SABM 130 
#define  AX25_SABME 129 
 int /*<<< orphan*/  AX25_STATE_3 ; 
#define  AX25_UA 128 
 size_t AX25_VALUES_EWINDOW ; 
 size_t AX25_VALUES_WINDOW ; 
 int /*<<< orphan*/  ECONNREFUSED ; 
 int /*<<< orphan*/  SOCK_DEAD ; 
 int /*<<< orphan*/  TCP_ESTABLISHED ; 
 int /*<<< orphan*/  ax25_calculate_rtt (TYPE_2__*) ; 
 int /*<<< orphan*/  ax25_disconnect (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ax25_send_control (TYPE_2__*,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ax25_start_idletimer (TYPE_2__*) ; 
 int /*<<< orphan*/  ax25_start_t3timer (TYPE_2__*) ; 
 int /*<<< orphan*/  ax25_stop_t1timer (TYPE_2__*) ; 
 int /*<<< orphan*/  bh_lock_sock (TYPE_3__*) ; 
 int /*<<< orphan*/  bh_unlock_sock (TYPE_3__*) ; 
 int /*<<< orphan*/  sock_flag (TYPE_3__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (TYPE_3__*) ; 

__attribute__((used)) static int ax25_std_state1_machine(ax25_cb *ax25, struct sk_buff *skb, int frametype, int pf, int type)
{
	switch (frametype) {
	case AX25_SABM:
		ax25->modulus = AX25_MODULUS;
		ax25->window  = ax25->ax25_dev->values[AX25_VALUES_WINDOW];
		ax25_send_control(ax25, AX25_UA, pf, AX25_RESPONSE);
		break;

	case AX25_SABME:
		ax25->modulus = AX25_EMODULUS;
		ax25->window  = ax25->ax25_dev->values[AX25_VALUES_EWINDOW];
		ax25_send_control(ax25, AX25_UA, pf, AX25_RESPONSE);
		break;

	case AX25_DISC:
		ax25_send_control(ax25, AX25_DM, pf, AX25_RESPONSE);
		break;

	case AX25_UA:
		if (pf) {
			ax25_calculate_rtt(ax25);
			ax25_stop_t1timer(ax25);
			ax25_start_t3timer(ax25);
			ax25_start_idletimer(ax25);
			ax25->vs      = 0;
			ax25->va      = 0;
			ax25->vr      = 0;
			ax25->state   = AX25_STATE_3;
			ax25->n2count = 0;
			if (ax25->sk != NULL) {
				bh_lock_sock(ax25->sk);
				ax25->sk->sk_state = TCP_ESTABLISHED;
				/* For WAIT_SABM connections we will produce an accept ready socket here */
				if (!sock_flag(ax25->sk, SOCK_DEAD))
					ax25->sk->sk_state_change(ax25->sk);
				bh_unlock_sock(ax25->sk);
			}
		}
		break;

	case AX25_DM:
		if (pf) {
			if (ax25->modulus == AX25_MODULUS) {
				ax25_disconnect(ax25, ECONNREFUSED);
			} else {
				ax25->modulus = AX25_MODULUS;
				ax25->window  = ax25->ax25_dev->values[AX25_VALUES_WINDOW];
			}
		}
		break;

	default:
		break;
	}

	return 0;
}