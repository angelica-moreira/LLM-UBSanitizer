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
struct hnae3_handle {TYPE_1__* pdev; } ;
struct hclgevf_dev {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 struct hclgevf_dev* hclgevf_ae_get_hdev (struct hnae3_handle*) ; 
 int /*<<< orphan*/  hclgevf_free_vector (struct hclgevf_dev*,int) ; 
 int hclgevf_get_vector_index (struct hclgevf_dev*,int) ; 

__attribute__((used)) static int hclgevf_put_vector(struct hnae3_handle *handle, int vector)
{
	struct hclgevf_dev *hdev = hclgevf_ae_get_hdev(handle);
	int vector_id;

	vector_id = hclgevf_get_vector_index(hdev, vector);
	if (vector_id < 0) {
		dev_err(&handle->pdev->dev,
			"hclgevf_put_vector get vector index fail. ret =%d\n",
			vector_id);
		return vector_id;
	}

	hclgevf_free_vector(hdev, vector_id);

	return 0;
}