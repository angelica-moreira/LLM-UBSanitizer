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
struct i2c_adapter {int dummy; } ;
struct dvb_frontend {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static inline struct i2c_adapter *s5h1420_get_tuner_i2c_adapter(struct dvb_frontend *fe)
{
	return NULL;
}