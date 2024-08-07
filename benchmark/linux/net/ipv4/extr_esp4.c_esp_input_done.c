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
struct crypto_async_request {struct sk_buff* data; } ;

/* Variables and functions */
 int /*<<< orphan*/  esp_input_done2 (struct sk_buff*,int) ; 
 int /*<<< orphan*/  xfrm_input_resume (struct sk_buff*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void esp_input_done(struct crypto_async_request *base, int err)
{
	struct sk_buff *skb = base->data;

	xfrm_input_resume(skb, esp_input_done2(skb, err));
}