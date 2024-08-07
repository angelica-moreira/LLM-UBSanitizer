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
struct sk_buff {int dummy; } ;
struct nft_object {int dummy; } ;
struct nft_counter_percpu_priv {int dummy; } ;

/* Variables and functions */
 int nft_counter_do_dump (struct sk_buff*,struct nft_counter_percpu_priv*,int) ; 
 struct nft_counter_percpu_priv* nft_obj_data (struct nft_object*) ; 

__attribute__((used)) static int nft_counter_obj_dump(struct sk_buff *skb,
				struct nft_object *obj, bool reset)
{
	struct nft_counter_percpu_priv *priv = nft_obj_data(obj);

	return nft_counter_do_dump(skb, priv, reset);
}