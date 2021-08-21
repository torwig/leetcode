package golang

func findMinV1(nums []int) int {
	left, right := 0, len(nums)-1

	if nums[left] < nums[right] {
		return nums[left]
	}

	for left < right {
		mid := left + (right-left)/2

		if nums[mid] > nums[right] {
			left = mid + 1
		} else {
			right = mid
		}
	}

	return nums[left]
}

func findMinV2(nums []int) int {
	left, right := 0, len(nums)-1

	if nums[left] < nums[right] {
		return nums[left]
	}

	mid := 0

	for left < right {
		mid = (left + right) / 2

		if nums[mid] < nums[right] { // right half sorted
			if nums[mid] < nums[mid-1] { //comparing mid with previous
				return nums[mid]
			}

			right = mid - 1
		} else { //left half sorted
			if nums[mid+1] < nums[mid] { //comparing mid with next
				return nums[mid+1]
			}

			left = mid + 1
		}
	}

	return nums[mid]
}
