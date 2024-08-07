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
typedef  int u32 ;
struct nv10_fence_priv {int sequence; int /*<<< orphan*/  lock; } ;
struct TYPE_6__ {int handle; } ;
struct nv10_fence_chan {TYPE_3__ sema; } ;
struct nouveau_fence {int dummy; } ;
struct nouveau_cli {int /*<<< orphan*/  mutex; } ;
struct TYPE_4__ {scalar_t__ client; } ;
struct nouveau_channel {struct nv10_fence_chan* fence; TYPE_2__* drm; TYPE_1__ user; } ;
struct TYPE_5__ {struct nv10_fence_priv* fence; } ;

/* Variables and functions */
 int /*<<< orphan*/  BEGIN_NV04 (struct nouveau_channel*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int EBUSY ; 
 int /*<<< orphan*/  FIRE_RING (struct nouveau_channel*) ; 
 int /*<<< orphan*/  NV11_SUBCHAN_DMA_SEMAPHORE ; 
 int /*<<< orphan*/  OUT_RING (struct nouveau_channel*,int) ; 
 int RING_SPACE (struct nouveau_channel*,int) ; 
 int /*<<< orphan*/  mutex_trylock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

int
nv17_fence_sync(struct nouveau_fence *fence,
		struct nouveau_channel *prev, struct nouveau_channel *chan)
{
	struct nouveau_cli *cli = (void *)prev->user.client;
	struct nv10_fence_priv *priv = chan->drm->fence;
	struct nv10_fence_chan *fctx = chan->fence;
	u32 value;
	int ret;

	if (!mutex_trylock(&cli->mutex))
		return -EBUSY;

	spin_lock(&priv->lock);
	value = priv->sequence;
	priv->sequence += 2;
	spin_unlock(&priv->lock);

	ret = RING_SPACE(prev, 5);
	if (!ret) {
		BEGIN_NV04(prev, 0, NV11_SUBCHAN_DMA_SEMAPHORE, 4);
		OUT_RING  (prev, fctx->sema.handle);
		OUT_RING  (prev, 0);
		OUT_RING  (prev, value + 0);
		OUT_RING  (prev, value + 1);
		FIRE_RING (prev);
	}

	if (!ret && !(ret = RING_SPACE(chan, 5))) {
		BEGIN_NV04(chan, 0, NV11_SUBCHAN_DMA_SEMAPHORE, 4);
		OUT_RING  (chan, fctx->sema.handle);
		OUT_RING  (chan, 0);
		OUT_RING  (chan, value + 1);
		OUT_RING  (chan, value + 2);
		FIRE_RING (chan);
	}

	mutex_unlock(&cli->mutex);
	return 0;
}