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
struct ad5272_data {int* buf; int /*<<< orphan*/  lock; int /*<<< orphan*/  client; } ;

/* Variables and functions */
 int i2c_master_recv (int /*<<< orphan*/ ,int*,int) ; 
 int i2c_master_send (int /*<<< orphan*/ ,int*,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int ad5272_read(struct ad5272_data *data, int reg, int *val)
{
	int ret;

	data->buf[0] = reg << 2;
	data->buf[1] = 0;

	mutex_lock(&data->lock);
	ret = i2c_master_send(data->client, data->buf, sizeof(data->buf));
	if (ret < 0)
		goto error;

	ret = i2c_master_recv(data->client, data->buf, sizeof(data->buf));
	if (ret < 0)
		goto error;

	*val = ((data->buf[0] & 0x3) << 8) | data->buf[1];
	ret = 0;
error:
	mutex_unlock(&data->lock);
	return ret;
}