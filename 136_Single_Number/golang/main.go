package golang

func singleNumber(nums []int) int {
	res := nums[0]

	for _, v := range nums[1:] {
		res ^= v
	}

	return res
}
