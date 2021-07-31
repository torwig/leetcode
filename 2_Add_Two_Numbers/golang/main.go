package golang

type ListNode struct {
	Val  int
	Next *ListNode
}

func addElementToList(head *ListNode, tail *ListNode, value int) (*ListNode, *ListNode) {
	node := ListNode{Val: value}

	if head != nil {
		tail.Next = &node
		tail = &node

		return head, tail
	}

	return &node, &node
}

func addTwoNumbersV1(l1 *ListNode, l2 *ListNode) *ListNode {
	var (
		resultHead *ListNode
		resultTail *ListNode
		extraOne   bool
	)

	it1 := l1
	it2 := l2

	for it1 != nil && it2 != nil {
		sum := it1.Val + it2.Val
		if extraOne {
			sum += 1
			extraOne = false
		}

		if sum >= 10 {
			sum = sum % 10
			extraOne = true
		}

		resultHead, resultTail = addElementToList(resultHead, resultTail, sum)

		it1 = it1.Next
		it2 = it2.Next
	}

	for it1 != nil {
		val := it1.Val
		if extraOne {
			val += 1
			extraOne = false
		}

		if val >= 10 {
			val = val % 10
			extraOne = true
		}

		resultHead, resultTail = addElementToList(resultHead, resultTail, val)

		it1 = it1.Next
	}

	for it2 != nil {
		val := it2.Val
		if extraOne {
			val += 1
			extraOne = false
		}

		if val >= 10 {
			val = val % 10
			extraOne = true
		}

		resultHead, resultTail = addElementToList(resultHead, resultTail, val)

		it2 = it2.Next
	}

	if extraOne {
		resultHead, resultTail = addElementToList(resultHead, resultTail, 1)
	}

	return resultHead
}

func addTwoNumbersV2(l1 *ListNode, l2 *ListNode) *ListNode {
	dummyHead := &ListNode{}
	resultTail := dummyHead
	carry := 0

	it1 := l1
	it2 := l2

	for it1 != nil || it2 != nil {
		sum := carry

		if it1 != nil {
			sum += it1.Val
			it1 = it1.Next
		}

		if it2 != nil {
			sum += it2.Val
			it2 = it2.Next
		}

		carry = sum / 10

		resultTail.Next = &ListNode{Val: sum % 10}
		resultTail = resultTail.Next
	}

	if carry == 1 {
		resultTail.Next = &ListNode{Val: 1}
	}

	return dummyHead.Next
}
