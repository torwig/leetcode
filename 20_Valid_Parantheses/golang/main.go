package golang

func isValid(s string) bool {
	if len(s) == 0 {
		return true
	}

	if len(s)%2 != 0 {
		return false
	}

	stack := make([]int32, 0, len(s))

	for _, c := range s {
		if c == '(' || c == '{' || c == '[' {
			stack = append(stack, c)
			continue
		}

		if len(stack) == 0 {
			return false
		}

		prev := stack[len(stack)-1]

		if c == ')' && prev != '(' {
			return false
		}

		if c == '}' && prev != '{' {
			return false
		}

		if c == ']' && prev != '[' {
			return false
		}

		stack = stack[:len(stack)-1]
	}

	return len(stack) == 0
}
