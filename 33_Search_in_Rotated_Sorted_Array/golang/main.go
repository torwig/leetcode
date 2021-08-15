package golang

func searchV1(nums []int, target int) int {
	n := len(nums)

	// Find the pivot
	left, right := 0, n-1
	for left < right {
		mid := left + (right-left)/2
		if nums[mid] > nums[right] {
			left = mid + 1
		} else {
			right = mid
		}
	}

	pivot := left

	// Regular binary search
	left, right = pivot, pivot-1+n

	for left <= right {
		mid := left + (right-left)/2
		midVal := nums[mid%n]

		if midVal == target {
			return mid % n
		}

		if midVal > target {
			right = mid - 1
		} else {
			left = mid + 1
		}
	}

	return -1
}

func searchV2(nums []int, target int) int {
	n := len(nums)
	l := 0
	r := n - 1

	for l <= r {
		if nums[l] == target {
			return l
		}

		if nums[r] == target {
			return r
		}

		mid := (l + r) / 2

		if nums[mid] == target {
			return mid
		}

		if nums[l] > nums[r] {
			l += 1
			r -= 1
		} else {
			if nums[mid] > target {
				r = mid - 1
			} else {
				l = mid + 1
			}
		}
	}

	return -1
}
