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
struct xdr_stream {int dummy; } ;
struct user_namespace {int dummy; } ;
struct nfs3_mknodargs {int /*<<< orphan*/  rdev; int /*<<< orphan*/  sattr; } ;

/* Variables and functions */
 int /*<<< orphan*/  encode_sattr3 (struct xdr_stream*,int /*<<< orphan*/ ,struct user_namespace*) ; 
 int /*<<< orphan*/  encode_specdata3 (struct xdr_stream*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void encode_devicedata3(struct xdr_stream *xdr,
			       const struct nfs3_mknodargs *args,
			       struct user_namespace *userns)
{
	encode_sattr3(xdr, args->sattr, userns);
	encode_specdata3(xdr, args->rdev);
}