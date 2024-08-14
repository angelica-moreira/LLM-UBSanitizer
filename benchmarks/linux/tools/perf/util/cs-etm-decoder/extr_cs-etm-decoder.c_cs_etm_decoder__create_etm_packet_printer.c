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
struct cs_etm_trace_params {int protocol; } ;
struct cs_etm_decoder {int dummy; } ;
typedef  int /*<<< orphan*/  ocsd_etmv4_cfg ;
typedef  int /*<<< orphan*/  ocsd_etmv3_cfg ;

/* Variables and functions */
#define  CS_ETM_PROTO_ETMV3 130 
#define  CS_ETM_PROTO_ETMV4i 129 
#define  CS_ETM_PROTO_PTM 128 
 char* OCSD_BUILTIN_DCD_ETMV3 ; 
 char* OCSD_BUILTIN_DCD_ETMV4I ; 
 char* OCSD_BUILTIN_DCD_PTM ; 
 int cs_etm_decoder__create_packet_printer (struct cs_etm_decoder*,char const*,void*) ; 
 int /*<<< orphan*/  cs_etm_decoder__gen_etmv3_config (struct cs_etm_trace_params*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cs_etm_decoder__gen_etmv4_config (struct cs_etm_trace_params*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int
cs_etm_decoder__create_etm_packet_printer(struct cs_etm_trace_params *t_params,
					  struct cs_etm_decoder *decoder)
{
	const char *decoder_name;
	ocsd_etmv3_cfg config_etmv3;
	ocsd_etmv4_cfg trace_config_etmv4;
	void *trace_config;

	switch (t_params->protocol) {
	case CS_ETM_PROTO_ETMV3:
	case CS_ETM_PROTO_PTM:
		cs_etm_decoder__gen_etmv3_config(t_params, &config_etmv3);
		decoder_name = (t_params->protocol == CS_ETM_PROTO_ETMV3) ?
							OCSD_BUILTIN_DCD_ETMV3 :
							OCSD_BUILTIN_DCD_PTM;
		trace_config = &config_etmv3;
		break;
	case CS_ETM_PROTO_ETMV4i:
		cs_etm_decoder__gen_etmv4_config(t_params, &trace_config_etmv4);
		decoder_name = OCSD_BUILTIN_DCD_ETMV4I;
		trace_config = &trace_config_etmv4;
		break;
	default:
		return -1;
	}

	return cs_etm_decoder__create_packet_printer(decoder,
						     decoder_name,
						     trace_config);
}