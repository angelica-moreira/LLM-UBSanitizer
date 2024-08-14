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
struct hnae3_ring_chain_node {int dummy; } ;
struct hnae3_handle {TYPE_1__* pdev; } ;
struct hclge_vport {struct hclge_dev* back; } ;
struct hclge_dev {int /*<<< orphan*/  state; } ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  HCLGE_STATE_RST_HANDLING ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int,...) ; 
 int hclge_bind_ring_with_vector (struct hclge_vport*,int,int,struct hnae3_ring_chain_node*) ; 
 int hclge_get_vector_index (struct hclge_dev*,int) ; 
 struct hclge_vport* hclge_get_vport (struct hnae3_handle*) ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int hclge_unmap_ring_frm_vector(struct hnae3_handle *handle, int vector,
				       struct hnae3_ring_chain_node *ring_chain)
{
	struct hclge_vport *vport = hclge_get_vport(handle);
	struct hclge_dev *hdev = vport->back;
	int vector_id, ret;

	if (test_bit(HCLGE_STATE_RST_HANDLING, &hdev->state))
		return 0;

	vector_id = hclge_get_vector_index(hdev, vector);
	if (vector_id < 0) {
		dev_err(&handle->pdev->dev,
			"Get vector index fail. ret =%d\n", vector_id);
		return vector_id;
	}

	ret = hclge_bind_ring_with_vector(vport, vector_id, false, ring_chain);
	if (ret)
		dev_err(&handle->pdev->dev,
			"Unmap ring from vector fail. vectorid=%d, ret =%d\n",
			vector_id, ret);

	return ret;
}