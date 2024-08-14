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
typedef  int u8 ;
struct nvkm_i2c_pad {int dummy; } ;
struct nvkm_i2c_aux_func {int dummy; } ;
struct nvkm_i2c_aux {int intr; } ;
struct g94_i2c_aux {int ch; struct nvkm_i2c_aux base; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 struct g94_i2c_aux* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nvkm_i2c_aux_ctor (struct nvkm_i2c_aux_func const*,struct nvkm_i2c_pad*,int,struct nvkm_i2c_aux*) ; 

int
g94_i2c_aux_new_(const struct nvkm_i2c_aux_func *func,
		 struct nvkm_i2c_pad *pad, int index, u8 drive,
		 struct nvkm_i2c_aux **paux)
{
	struct g94_i2c_aux *aux;

	if (!(aux = kzalloc(sizeof(*aux), GFP_KERNEL)))
		return -ENOMEM;
	*paux = &aux->base;

	nvkm_i2c_aux_ctor(func, pad, index, &aux->base);
	aux->ch = drive;
	aux->base.intr = 1 << aux->ch;
	return 0;
}