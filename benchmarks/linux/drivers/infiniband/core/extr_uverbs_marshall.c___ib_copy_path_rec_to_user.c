#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  raw; } ;
struct TYPE_3__ {int /*<<< orphan*/  raw; } ;
struct sa_path_rec {int /*<<< orphan*/  packet_life_time_selector; int /*<<< orphan*/  preference; int /*<<< orphan*/  packet_life_time; int /*<<< orphan*/  rate; int /*<<< orphan*/  rate_selector; int /*<<< orphan*/  mtu; int /*<<< orphan*/  mtu_selector; int /*<<< orphan*/  sl; int /*<<< orphan*/  pkey; int /*<<< orphan*/  numb_path; int /*<<< orphan*/  reversible; int /*<<< orphan*/  traffic_class; int /*<<< orphan*/  hop_limit; int /*<<< orphan*/  flow_label; TYPE_2__ sgid; TYPE_1__ dgid; } ;
struct ib_user_path_rec {int /*<<< orphan*/  packet_life_time_selector; int /*<<< orphan*/  preference; int /*<<< orphan*/  packet_life_time; int /*<<< orphan*/  rate; int /*<<< orphan*/  rate_selector; int /*<<< orphan*/  mtu; int /*<<< orphan*/  mtu_selector; int /*<<< orphan*/  sl; int /*<<< orphan*/  pkey; int /*<<< orphan*/  numb_path; int /*<<< orphan*/  reversible; int /*<<< orphan*/  traffic_class; int /*<<< orphan*/  hop_limit; int /*<<< orphan*/  flow_label; int /*<<< orphan*/  raw_traffic; void* slid; void* dlid; int /*<<< orphan*/  sgid; int /*<<< orphan*/  dgid; } ;

/* Variables and functions */
 void* htons (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ntohl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sa_path_get_dlid (struct sa_path_rec*) ; 
 int /*<<< orphan*/  sa_path_get_raw_traffic (struct sa_path_rec*) ; 
 int /*<<< orphan*/  sa_path_get_slid (struct sa_path_rec*) ; 

__attribute__((used)) static void __ib_copy_path_rec_to_user(struct ib_user_path_rec *dst,
				       struct sa_path_rec *src)
{
	memcpy(dst->dgid, src->dgid.raw, sizeof(src->dgid));
	memcpy(dst->sgid, src->sgid.raw, sizeof(src->sgid));

	dst->dlid		= htons(ntohl(sa_path_get_dlid(src)));
	dst->slid		= htons(ntohl(sa_path_get_slid(src)));
	dst->raw_traffic	= sa_path_get_raw_traffic(src);
	dst->flow_label		= src->flow_label;
	dst->hop_limit		= src->hop_limit;
	dst->traffic_class	= src->traffic_class;
	dst->reversible		= src->reversible;
	dst->numb_path		= src->numb_path;
	dst->pkey		= src->pkey;
	dst->sl			= src->sl;
	dst->mtu_selector	= src->mtu_selector;
	dst->mtu		= src->mtu;
	dst->rate_selector	= src->rate_selector;
	dst->rate		= src->rate;
	dst->packet_life_time	= src->packet_life_time;
	dst->preference		= src->preference;
	dst->packet_life_time_selector = src->packet_life_time_selector;
}