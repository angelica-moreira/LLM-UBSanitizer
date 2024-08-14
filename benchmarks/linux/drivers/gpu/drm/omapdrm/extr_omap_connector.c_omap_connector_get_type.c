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
struct omap_dss_device {int type; } ;
typedef  enum omap_display_type { ____Placeholder_omap_display_type } omap_display_type ;

/* Variables and functions */
 int DRM_MODE_CONNECTOR_DPI ; 
 int DRM_MODE_CONNECTOR_DSI ; 
 int DRM_MODE_CONNECTOR_DVID ; 
 int DRM_MODE_CONNECTOR_HDMIA ; 
 int DRM_MODE_CONNECTOR_LVDS ; 
 int DRM_MODE_CONNECTOR_SVIDEO ; 
 int DRM_MODE_CONNECTOR_Unknown ; 
#define  OMAP_DISPLAY_TYPE_DBI 134 
#define  OMAP_DISPLAY_TYPE_DPI 133 
#define  OMAP_DISPLAY_TYPE_DSI 132 
#define  OMAP_DISPLAY_TYPE_DVI 131 
#define  OMAP_DISPLAY_TYPE_HDMI 130 
#define  OMAP_DISPLAY_TYPE_SDI 129 
#define  OMAP_DISPLAY_TYPE_VENC 128 
 int /*<<< orphan*/  omapdss_device_put (struct omap_dss_device*) ; 
 struct omap_dss_device* omapdss_display_get (struct omap_dss_device*) ; 

__attribute__((used)) static int omap_connector_get_type(struct omap_dss_device *output)
{
	struct omap_dss_device *display;
	enum omap_display_type type;

	display = omapdss_display_get(output);
	type = display->type;
	omapdss_device_put(display);

	switch (type) {
	case OMAP_DISPLAY_TYPE_HDMI:
		return DRM_MODE_CONNECTOR_HDMIA;
	case OMAP_DISPLAY_TYPE_DVI:
		return DRM_MODE_CONNECTOR_DVID;
	case OMAP_DISPLAY_TYPE_DSI:
		return DRM_MODE_CONNECTOR_DSI;
	case OMAP_DISPLAY_TYPE_DPI:
	case OMAP_DISPLAY_TYPE_DBI:
		return DRM_MODE_CONNECTOR_DPI;
	case OMAP_DISPLAY_TYPE_VENC:
		/* TODO: This could also be composite */
		return DRM_MODE_CONNECTOR_SVIDEO;
	case OMAP_DISPLAY_TYPE_SDI:
		return DRM_MODE_CONNECTOR_LVDS;
	default:
		return DRM_MODE_CONNECTOR_Unknown;
	}
}