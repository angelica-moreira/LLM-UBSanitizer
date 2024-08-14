#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
typedef  scalar_t__ u16 ;
struct TYPE_2__ {scalar_t__ rx; scalar_t__ tx; } ;
struct rt2x00_dev {int /*<<< orphan*/  led_mcu_reg; int /*<<< orphan*/  led_qual; int /*<<< orphan*/  led_assoc; int /*<<< orphan*/  led_radio; int /*<<< orphan*/  cap_flags; scalar_t__ freq_offset; TYPE_1__ default_ant; } ;

/* Variables and functions */
 int /*<<< orphan*/  CAPABILITY_EXTERNAL_LNA_A ; 
 int /*<<< orphan*/  CAPABILITY_EXTERNAL_LNA_BG ; 
 int /*<<< orphan*/  CAPABILITY_FRAME_TYPE ; 
 int /*<<< orphan*/  CAPABILITY_HW_BUTTON ; 
 int /*<<< orphan*/  EEPROM_ANTENNA ; 
 int /*<<< orphan*/  EEPROM_ANTENNA_FRAME_TYPE ; 
 int /*<<< orphan*/  EEPROM_ANTENNA_HARDWARE_RADIO ; 
 int /*<<< orphan*/  EEPROM_ANTENNA_RF_TYPE ; 
 int /*<<< orphan*/  EEPROM_ANTENNA_RX_DEFAULT ; 
 int /*<<< orphan*/  EEPROM_ANTENNA_TX_DEFAULT ; 
 int /*<<< orphan*/  EEPROM_FREQ ; 
 int /*<<< orphan*/  EEPROM_FREQ_OFFSET ; 
 int /*<<< orphan*/  EEPROM_LED ; 
 int /*<<< orphan*/  EEPROM_LED_POLARITY_ACT ; 
 int /*<<< orphan*/  EEPROM_LED_POLARITY_GPIO_0 ; 
 int /*<<< orphan*/  EEPROM_LED_POLARITY_GPIO_1 ; 
 int /*<<< orphan*/  EEPROM_LED_POLARITY_GPIO_2 ; 
 int /*<<< orphan*/  EEPROM_LED_POLARITY_GPIO_3 ; 
 int /*<<< orphan*/  EEPROM_LED_POLARITY_GPIO_4 ; 
 int /*<<< orphan*/  EEPROM_LED_POLARITY_RDY_A ; 
 int /*<<< orphan*/  EEPROM_LED_POLARITY_RDY_G ; 
 int /*<<< orphan*/  EEPROM_NIC ; 
 int /*<<< orphan*/  EEPROM_NIC_EXTERNAL_LNA ; 
 int ENODEV ; 
 scalar_t__ LED_MODE_SIGNAL_STRENGTH ; 
 int /*<<< orphan*/  LED_TYPE_ASSOC ; 
 int /*<<< orphan*/  LED_TYPE_QUALITY ; 
 int /*<<< orphan*/  LED_TYPE_RADIO ; 
 int /*<<< orphan*/  MAC_CSR0 ; 
 int /*<<< orphan*/  MAC_CSR0_CHIPSET ; 
 int /*<<< orphan*/  MAC_CSR0_REVISION ; 
 int /*<<< orphan*/  MCU_LEDCS_LED_MODE ; 
 int /*<<< orphan*/  MCU_LEDCS_POLARITY_ACT ; 
 int /*<<< orphan*/  MCU_LEDCS_POLARITY_GPIO_0 ; 
 int /*<<< orphan*/  MCU_LEDCS_POLARITY_GPIO_1 ; 
 int /*<<< orphan*/  MCU_LEDCS_POLARITY_GPIO_2 ; 
 int /*<<< orphan*/  MCU_LEDCS_POLARITY_GPIO_3 ; 
 int /*<<< orphan*/  MCU_LEDCS_POLARITY_GPIO_4 ; 
 int /*<<< orphan*/  MCU_LEDCS_POLARITY_READY_A ; 
 int /*<<< orphan*/  MCU_LEDCS_POLARITY_READY_BG ; 
 int /*<<< orphan*/  RF2527 ; 
 int /*<<< orphan*/  RF2528 ; 
 int /*<<< orphan*/  RF5225 ; 
 int /*<<< orphan*/  RF5226 ; 
 int /*<<< orphan*/  RT2573 ; 
 int /*<<< orphan*/  __set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ rt2x00_eeprom_read (struct rt2x00_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rt2x00_err (struct rt2x00_dev*,char*) ; 
 scalar_t__ rt2x00_get_field16 (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rt2x00_get_field32 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ rt2x00_rev (struct rt2x00_dev*) ; 
 int /*<<< orphan*/  rt2x00_rf (struct rt2x00_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rt2x00_rt (struct rt2x00_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rt2x00_set_chip (struct rt2x00_dev*,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rt2x00_set_field16 (int /*<<< orphan*/ *,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  rt2x00usb_register_read (struct rt2x00_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rt73usb_init_led (struct rt2x00_dev*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int rt73usb_init_eeprom(struct rt2x00_dev *rt2x00dev)
{
	u32 reg;
	u16 value;
	u16 eeprom;

	/*
	 * Read EEPROM word for configuration.
	 */
	eeprom = rt2x00_eeprom_read(rt2x00dev, EEPROM_ANTENNA);

	/*
	 * Identify RF chipset.
	 */
	value = rt2x00_get_field16(eeprom, EEPROM_ANTENNA_RF_TYPE);
	reg = rt2x00usb_register_read(rt2x00dev, MAC_CSR0);
	rt2x00_set_chip(rt2x00dev, rt2x00_get_field32(reg, MAC_CSR0_CHIPSET),
			value, rt2x00_get_field32(reg, MAC_CSR0_REVISION));

	if (!rt2x00_rt(rt2x00dev, RT2573) || (rt2x00_rev(rt2x00dev) == 0)) {
		rt2x00_err(rt2x00dev, "Invalid RT chipset detected\n");
		return -ENODEV;
	}

	if (!rt2x00_rf(rt2x00dev, RF5226) &&
	    !rt2x00_rf(rt2x00dev, RF2528) &&
	    !rt2x00_rf(rt2x00dev, RF5225) &&
	    !rt2x00_rf(rt2x00dev, RF2527)) {
		rt2x00_err(rt2x00dev, "Invalid RF chipset detected\n");
		return -ENODEV;
	}

	/*
	 * Identify default antenna configuration.
	 */
	rt2x00dev->default_ant.tx =
	    rt2x00_get_field16(eeprom, EEPROM_ANTENNA_TX_DEFAULT);
	rt2x00dev->default_ant.rx =
	    rt2x00_get_field16(eeprom, EEPROM_ANTENNA_RX_DEFAULT);

	/*
	 * Read the Frame type.
	 */
	if (rt2x00_get_field16(eeprom, EEPROM_ANTENNA_FRAME_TYPE))
		__set_bit(CAPABILITY_FRAME_TYPE, &rt2x00dev->cap_flags);

	/*
	 * Detect if this device has an hardware controlled radio.
	 */
	if (rt2x00_get_field16(eeprom, EEPROM_ANTENNA_HARDWARE_RADIO))
		__set_bit(CAPABILITY_HW_BUTTON, &rt2x00dev->cap_flags);

	/*
	 * Read frequency offset.
	 */
	eeprom = rt2x00_eeprom_read(rt2x00dev, EEPROM_FREQ);
	rt2x00dev->freq_offset = rt2x00_get_field16(eeprom, EEPROM_FREQ_OFFSET);

	/*
	 * Read external LNA informations.
	 */
	eeprom = rt2x00_eeprom_read(rt2x00dev, EEPROM_NIC);

	if (rt2x00_get_field16(eeprom, EEPROM_NIC_EXTERNAL_LNA)) {
		__set_bit(CAPABILITY_EXTERNAL_LNA_A, &rt2x00dev->cap_flags);
		__set_bit(CAPABILITY_EXTERNAL_LNA_BG, &rt2x00dev->cap_flags);
	}

	/*
	 * Store led settings, for correct led behaviour.
	 */
#ifdef CONFIG_RT2X00_LIB_LEDS
	eeprom = rt2x00_eeprom_read(rt2x00dev, EEPROM_LED);

	rt73usb_init_led(rt2x00dev, &rt2x00dev->led_radio, LED_TYPE_RADIO);
	rt73usb_init_led(rt2x00dev, &rt2x00dev->led_assoc, LED_TYPE_ASSOC);
	if (value == LED_MODE_SIGNAL_STRENGTH)
		rt73usb_init_led(rt2x00dev, &rt2x00dev->led_qual,
				 LED_TYPE_QUALITY);

	rt2x00_set_field16(&rt2x00dev->led_mcu_reg, MCU_LEDCS_LED_MODE, value);
	rt2x00_set_field16(&rt2x00dev->led_mcu_reg, MCU_LEDCS_POLARITY_GPIO_0,
			   rt2x00_get_field16(eeprom,
					      EEPROM_LED_POLARITY_GPIO_0));
	rt2x00_set_field16(&rt2x00dev->led_mcu_reg, MCU_LEDCS_POLARITY_GPIO_1,
			   rt2x00_get_field16(eeprom,
					      EEPROM_LED_POLARITY_GPIO_1));
	rt2x00_set_field16(&rt2x00dev->led_mcu_reg, MCU_LEDCS_POLARITY_GPIO_2,
			   rt2x00_get_field16(eeprom,
					      EEPROM_LED_POLARITY_GPIO_2));
	rt2x00_set_field16(&rt2x00dev->led_mcu_reg, MCU_LEDCS_POLARITY_GPIO_3,
			   rt2x00_get_field16(eeprom,
					      EEPROM_LED_POLARITY_GPIO_3));
	rt2x00_set_field16(&rt2x00dev->led_mcu_reg, MCU_LEDCS_POLARITY_GPIO_4,
			   rt2x00_get_field16(eeprom,
					      EEPROM_LED_POLARITY_GPIO_4));
	rt2x00_set_field16(&rt2x00dev->led_mcu_reg, MCU_LEDCS_POLARITY_ACT,
			   rt2x00_get_field16(eeprom, EEPROM_LED_POLARITY_ACT));
	rt2x00_set_field16(&rt2x00dev->led_mcu_reg, MCU_LEDCS_POLARITY_READY_BG,
			   rt2x00_get_field16(eeprom,
					      EEPROM_LED_POLARITY_RDY_G));
	rt2x00_set_field16(&rt2x00dev->led_mcu_reg, MCU_LEDCS_POLARITY_READY_A,
			   rt2x00_get_field16(eeprom,
					      EEPROM_LED_POLARITY_RDY_A));
#endif /* CONFIG_RT2X00_LIB_LEDS */

	return 0;
}