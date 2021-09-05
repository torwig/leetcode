package golang

import "sort"

func fourSumV1(nums []int, target int) [][]int {
	result := make([][]int, 0)
	if len(nums) < 4 {
		return result
	}

	sort.Ints(nums)

	for i := 0; i < len(nums)-3; i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}

		for j := i + 1; j < len(nums)-2; j++ {
			if j > i+1 && nums[j] == nums[j-1] {
				continue
			}

			low := j + 1
			high := len(nums) - 1

			for low < high {
				sum := nums[i] + nums[j] + nums[low] + nums[high]

				if sum == target {
					arr := []int{nums[i], nums[j], nums[low], nums[high]}
					result = append(result, arr)
					low++
					high--

					for low < high && nums[low] == nums[low-1] {
						low++
					}

					for low < high && nums[high] == nums[high+1] {
						high--
					}
				} else if sum > target {
					high--
				} else {
					low++
				}
			}

		}
	}

	return result
}

func fourSumV2(nums []int, target int) [][]int {
	var res [][]int

	sort.Ints(nums)

	for i := 0; i < len(nums); i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}

		for j := i + 1; j < len(nums); j++ {
			if j > i+1 && nums[j] == nums[j-1] {
				continue
			}

			k := j + 1
			l := len(nums) - 1

			for k < l {
				if k > j+1 && nums[k] == nums[k-1] {
					k++
					continue
				}

				if l < len(nums)-1 && nums[l] == nums[l+1] {
					l--
					continue
				}

				sum := nums[i] + nums[j] + nums[k] + nums[l]

				if sum == target {
					temp := []int{nums[i], nums[j], nums[k], nums[l]}
					res = append(res, temp)
					k++
					l--
				} else if sum < target {
					k++
				} else {
					l--
				}
			}
		}
	}

	return res
}