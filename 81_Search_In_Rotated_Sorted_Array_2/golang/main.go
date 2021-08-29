package golang

func searchV1(nums []int, target int) bool {
	low, high := 0, len(nums)-1

	for low <= high {
		mid := low + (high-low)/2

		if nums[mid] == target {
			return true
		}

		if nums[low] < nums[mid] {
			if nums[low] <= target && target < nums[mid] {
				high = mid - 1
			} else {
				low = mid + 1
			}
		} else if nums[low] == nums[mid] {
			low++
		} else {
			if nums[mid] < target && target <= nums[high] {
				low = mid + 1
			} else {
				high = mid - 1
			}
		}
	}

	return false
}

func searchV2(nums []int, target int) bool {
	l, r := 0, len(nums)-1

	for l <= r {
		m := l + (r-l)/2

		if nums[m] == target {
			return true
		}

		if nums[l] < nums[m] || nums[m] > nums[r] {
			if target > nums[m] || target < nums[l] {
				l = m + 1
			} else {
				r = m - 1
			}
		} else if nums[m] < nums[r] || nums[m] < nums[l] {
			if target > nums[r] || target < nums[m] {
				r = m - 1
			} else {
				l = m + 1
			}
		} else {
			r--
		}
	}

	return false
}
