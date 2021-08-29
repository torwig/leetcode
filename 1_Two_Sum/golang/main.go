package golang

func twoSum(nums []int, target int) []int {
	result := make([]int, 0, 2)

	m := make(map[int]int, len(nums))

	for i, v := range nums {
		if 2*v == target {
			result = append(result, i)
			if len(result) == 2 {
				return result
			}
		} else {
			m[v] = i
		}
	}

	for k, v := range m {
		need := target - k

		if j, ok := m[need]; ok {
			return []int{v, j}
		}
	}

	return nil
}

func twoSumV2(nums []int, target int) []int {
	m := make(map[int]int, len(nums))

	for i, num := range nums {
		if j, ok := m[target - num]; ok {
			return []int{i, j}
		}

		m[num] = i
	}

	return nil
}