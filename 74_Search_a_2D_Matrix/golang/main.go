package golang

func searchMatrixV1(matrix [][]int, target int) bool {
	m, n := len(matrix), len(matrix[0])
	low, high := 0, m*n-1

	for low <= high {
		mid := low + (high-low)/2
		val := matrix[mid/n][mid%n]

		if val == target {
			return true
		}

		if val > target {
			high = mid - 1
		} else {
			low = mid + 1
		}
	}

	return false
}

func searchMatrixV2(matrix [][]int, target int) bool {
	top := 0
	bottom := len(matrix) - 1
	midR := 0
	endC := len(matrix[0]) - 1

	for top <= bottom {
		midR = (bottom + top) / 2
		if target < matrix[midR][0] {
			bottom = midR - 1
		} else if target > matrix[midR][endC] {
			top = midR + 1
		} else {
			break
		}
	}

	left := 0
	right := len(matrix[0]) - 1

	for left <= right {
		midC := (left + right) / 2
		if matrix[midR][midC] < target {
			left = midC + 1
		} else if matrix[midR][midC] > target {
			right = midC - 1
		} else {
			return true
		}
	}

	return false
}
