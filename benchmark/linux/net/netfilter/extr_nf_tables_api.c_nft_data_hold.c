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
struct TYPE_4__ {int code; TYPE_1__* chain; } ;
struct nft_data {TYPE_2__ verdict; } ;
typedef  enum nft_data_types { ____Placeholder_nft_data_types } nft_data_types ;
struct TYPE_3__ {int /*<<< orphan*/  use; } ;

/* Variables and functions */
 int NFT_DATA_VERDICT ; 
#define  NFT_GOTO 129 
#define  NFT_JUMP 128 

void nft_data_hold(const struct nft_data *data, enum nft_data_types type)
{
	if (type == NFT_DATA_VERDICT) {
		switch (data->verdict.code) {
		case NFT_JUMP:
		case NFT_GOTO:
			data->verdict.chain->use++;
			break;
		}
	}
}