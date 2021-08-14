package golang

func guessNumber(n int) int {
	low, high := 1, n

	for low <= high {
		val := low + (high - low) / 2

		res := guess(val)
		if res == 0 {
			return val
		}

		if res == -1 {
			high = val - 1
		} else {
			low = val + 1
		}
	}

	return 0
}
