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
struct rsnd_priv {int dummy; } ;
struct rsnd_mod {int dummy; } ;
struct rsnd_dai_stream {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  rsnd_dvc_activation (struct rsnd_mod*) ; 
 int /*<<< orphan*/  rsnd_dvc_volume_init (struct rsnd_dai_stream*,struct rsnd_mod*) ; 
 int /*<<< orphan*/  rsnd_dvc_volume_update (struct rsnd_dai_stream*,struct rsnd_mod*) ; 
 int /*<<< orphan*/  rsnd_mod_power_on (struct rsnd_mod*) ; 

__attribute__((used)) static int rsnd_dvc_init(struct rsnd_mod *mod,
			 struct rsnd_dai_stream *io,
			 struct rsnd_priv *priv)
{
	rsnd_mod_power_on(mod);

	rsnd_dvc_activation(mod);

	rsnd_dvc_volume_init(io, mod);

	rsnd_dvc_volume_update(io, mod);

	return 0;
}