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
struct kxcjk1013_data {int ev_enable_state; int /*<<< orphan*/  mutex; scalar_t__ motion_trigger_on; } ;
struct iio_dev {int dummy; } ;
struct iio_chan_spec {int dummy; } ;
typedef  enum iio_event_type { ____Placeholder_iio_event_type } iio_event_type ;
typedef  enum iio_event_direction { ____Placeholder_iio_event_direction } iio_event_direction ;

/* Variables and functions */
 struct kxcjk1013_data* iio_priv (struct iio_dev*) ; 
 int kxcjk1013_set_power_state (struct kxcjk1013_data*,int) ; 
 int kxcjk1013_setup_any_motion_interrupt (struct kxcjk1013_data*,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int kxcjk1013_write_event_config(struct iio_dev *indio_dev,
					   const struct iio_chan_spec *chan,
					   enum iio_event_type type,
					   enum iio_event_direction dir,
					   int state)
{
	struct kxcjk1013_data *data = iio_priv(indio_dev);
	int ret;

	if (state && data->ev_enable_state)
		return 0;

	mutex_lock(&data->mutex);

	if (!state && data->motion_trigger_on) {
		data->ev_enable_state = 0;
		mutex_unlock(&data->mutex);
		return 0;
	}

	/*
	 * We will expect the enable and disable to do operation in
	 * in reverse order. This will happen here anyway as our
	 * resume operation uses sync mode runtime pm calls, the
	 * suspend operation will be delayed by autosuspend delay
	 * So the disable operation will still happen in reverse of
	 * enable operation. When runtime pm is disabled the mode
	 * is always on so sequence doesn't matter
	 */
	ret = kxcjk1013_set_power_state(data, state);
	if (ret < 0) {
		mutex_unlock(&data->mutex);
		return ret;
	}

	ret =  kxcjk1013_setup_any_motion_interrupt(data, state);
	if (ret < 0) {
		kxcjk1013_set_power_state(data, false);
		data->ev_enable_state = 0;
		mutex_unlock(&data->mutex);
		return ret;
	}

	data->ev_enable_state = state;
	mutex_unlock(&data->mutex);

	return 0;
}