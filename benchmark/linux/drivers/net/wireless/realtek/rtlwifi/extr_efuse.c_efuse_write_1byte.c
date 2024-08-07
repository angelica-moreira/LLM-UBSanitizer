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
typedef  int u8 ;
typedef  scalar_t__ u32 ;
typedef  scalar_t__ const u16 ;
struct rtl_priv {TYPE_1__* cfg; } ;
struct ieee80211_hw {int dummy; } ;
struct TYPE_2__ {scalar_t__* maps; } ;

/* Variables and functions */
 int /*<<< orphan*/  COMP_EFUSE ; 
 int /*<<< orphan*/  DBG_LOUD ; 
 size_t EFUSE_CTRL ; 
 size_t EFUSE_REAL_CONTENT_SIZE ; 
 int /*<<< orphan*/  RT_TRACE (struct rtl_priv*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,scalar_t__ const,int) ; 
 struct rtl_priv* rtl_priv (struct ieee80211_hw*) ; 
 int rtl_read_byte (struct rtl_priv*,scalar_t__) ; 
 int /*<<< orphan*/  rtl_write_byte (struct rtl_priv*,scalar_t__,int) ; 

void efuse_write_1byte(struct ieee80211_hw *hw, u16 address, u8 value)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	u8 bytetemp;
	u8 temp;
	u32 k = 0;
	const u32 efuse_len =
		rtlpriv->cfg->maps[EFUSE_REAL_CONTENT_SIZE];

	RT_TRACE(rtlpriv, COMP_EFUSE, DBG_LOUD, "Addr=%x Data =%x\n",
		 address, value);

	if (address < efuse_len) {
		rtl_write_byte(rtlpriv, rtlpriv->cfg->maps[EFUSE_CTRL], value);

		temp = address & 0xFF;
		rtl_write_byte(rtlpriv, rtlpriv->cfg->maps[EFUSE_CTRL] + 1,
			       temp);
		bytetemp = rtl_read_byte(rtlpriv,
					 rtlpriv->cfg->maps[EFUSE_CTRL] + 2);

		temp = ((address >> 8) & 0x03) | (bytetemp & 0xFC);
		rtl_write_byte(rtlpriv,
			       rtlpriv->cfg->maps[EFUSE_CTRL] + 2, temp);

		bytetemp = rtl_read_byte(rtlpriv,
					 rtlpriv->cfg->maps[EFUSE_CTRL] + 3);
		temp = bytetemp | 0x80;
		rtl_write_byte(rtlpriv,
			       rtlpriv->cfg->maps[EFUSE_CTRL] + 3, temp);

		bytetemp = rtl_read_byte(rtlpriv,
					 rtlpriv->cfg->maps[EFUSE_CTRL] + 3);

		while (bytetemp & 0x80) {
			bytetemp = rtl_read_byte(rtlpriv,
						 rtlpriv->cfg->
						 maps[EFUSE_CTRL] + 3);
			k++;
			if (k == 100) {
				k = 0;
				break;
			}
		}
	}

}